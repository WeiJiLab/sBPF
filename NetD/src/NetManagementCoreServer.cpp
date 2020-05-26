//
// Created by XingfengYang on 2020/5/12.
//

#include "../include/NetManagementCoreServer.h"
#include "../include/log/Log.h"
#include "../include/controller/ApiConfig.h"
#include "../include/event/RouteNetlinkEvent.h"

#include "unistd.h"
#include <linux/rtnetlink.h>
#include <thread>


hm::netd::NetManagementCoreServer::~NetManagementCoreServer() noexcept = default;

hm::netd::NetManagementCoreServer::NetManagementCoreServer(hm::netd::NetManagementCoreServer &&) noexcept = default;

hm::netd::NetManagementCoreServer &hm::netd::NetManagementCoreServer::operator=(hm::netd::NetManagementCoreServer &&) noexcept = default;

hm::netd::NetManagementCoreServer::NetManagementCoreServer() :
        netlinkManager(std::make_shared<NetlinkManager>()),
        networkContext(std::make_shared<NetworkContext>()),
        httpServer(std::make_shared<HttpServer>()) {

}


void hm::netd::NetManagementCoreServer::Init() {
    // init netlink manager

    unsigned int pid = (unsigned int) getpid();

    LogInfo("[NMCS] pid: %d", pid)

    // initial and add netlink listeneer here
    sockaddr_nl netlinkAddr{
            .nl_family=AF_NETLINK,
            .nl_pad=0,
            .nl_pid=pid,
            .nl_groups = RTMGRP_IPV4_IFADDR
    };

    NetlinkListenerConfiguration routeListenerConfiguration{
            .netdConfiguration={
                    .type=NETLINK_ROUTE,
                    .bindAddr=netlinkAddr
            },
            .msgType=RTM_GETROUTE
    };
    std::shared_ptr<RouteNetlinkEvent> routeNetLinkEvent = std::make_shared<RouteNetlinkEvent>(networkContext);
    std::shared_ptr<NetlinkEvent> routeEvent = std::shared_ptr<NetlinkEvent>(routeNetLinkEvent, reinterpret_cast<NetlinkEvent *>(routeNetLinkEvent.get()));
    netlinkManager->AddNetlinkListener(std::make_shared<NetlinkListener>("route", routeEvent, routeListenerConfiguration));

    netlinkManager->SetNetworkContext(networkContext);
}

void hm::netd::NetManagementCoreServer::StartNetlinkListeners() {
    netlinkManager->StartListeners();
}


void hm::netd::NetManagementCoreServer::StartHttpServer(unsigned int port) {
    httpServer->Configure({
                                  .socketConfiguration={
                                          .port=port
                                  }
                          });

    hm::netd::ApiConfig apiConfig;
    apiConfig.AttachApps(httpServer, networkContext);

    httpServer->Start();
}


void hm::netd::NetManagementCoreServer::Start() {
    this->StartHttpServer(8080);

    std::thread(&NetManagementCoreServer::StartNetlinkListeners, this).join();

    while (true);
}
