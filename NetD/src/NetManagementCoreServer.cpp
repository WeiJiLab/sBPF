//
// Created by XingfengYang on 2020/5/12.
//

#include "../include/NetManagementCoreServer.h"
#include "../include/log/Log.h"

hm::netd::NetManagementCoreServer::~NetManagementCoreServer() noexcept = default;

hm::netd::NetManagementCoreServer::NetManagementCoreServer(hm::netd::NetManagementCoreServer &&) noexcept = default;

hm::netd::NetManagementCoreServer &hm::netd::NetManagementCoreServer::operator=(hm::netd::NetManagementCoreServer &&) noexcept = default;

hm::netd::NetManagementCoreServer::NetManagementCoreServer() : 

commandListener(std::make_shared<CommandListener>()),
dnsProxyListener(std::make_shared<DnsProxyListener>()),
mdnsSdListener(std::make_shared<MDnsSdListener>()),
fwmarkServer(std::make_shared<FwmarkServer>()),
netlinkManager(std::make_shared<NetlinkManager>()) {

}


void hm::netd::NetManagementCoreServer::Init() {
    // init netlink manager


    // set initial
    commandListener->AbstractServiceListener::SetNetlinkManager(netlinkManager);
    dnsProxyListener->AbstractServiceListener::SetNetlinkManager(netlinkManager);
    mdnsSdListener->AbstractServiceListener::SetNetlinkManager(netlinkManager);
    fwmarkServer->AbstractServiceListener::SetNetlinkManager(netlinkManager);
}


void hm::netd::NetManagementCoreServer::Start() {

    if (commandListener->StartListener()) {
        LogError("Unable to start CommandListener")
        exit(1);
    }

    if (dnsProxyListener->StartListener()) {
        LogError("Unable to start DnsProxyListener")
        exit(1);
    }

    if (mdnsSdListener->StartListener()) {
        LogError("Unable to start MdnsSdListener")
        exit(1);
    }

    if (fwmarkServer->StartListener()) {
        LogError("Unable to start FwmarkServer")
        exit(1);
    }

}
