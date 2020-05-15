//
// Created by XingfengYang on 2020/5/12.
//

#include "../include/NetManagementCoreServer.h"
#include "../include/log/Log.h"

hm::netd::NetManagementCoreServer::~NetManagementCoreServer() noexcept = default;

hm::netd::NetManagementCoreServer::NetManagementCoreServer(hm::netd::NetManagementCoreServer &&) noexcept = default;

hm::netd::NetManagementCoreServer &hm::netd::NetManagementCoreServer::operator=(hm::netd::NetManagementCoreServer &&) noexcept = default;

hm::netd::NetManagementCoreServer::NetManagementCoreServer() :
        commandListener(std::shared_ptr<CommandListener>()),
        dnsProxyListener(std::shared_ptr<DnsProxyListener>()),
        mdnsSdListener(std::shared_ptr<MDnsSdListener>()),
        fwmarkServer(std::shared_ptr<FwmarkServer>()),
        netlinkManager(std::shared_ptr<NetlinkManager>()) {

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
