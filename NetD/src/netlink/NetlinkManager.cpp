//
// Created by XingfengYang on 2020/5/13.
//

#include "../../include/log/Log.h"
#include "../../include/netlink/NetlinkManager.h"

hm::netd::NetlinkManager::~NetlinkManager() noexcept = default;

hm::netd::NetlinkManager::NetlinkManager(hm::netd::NetlinkManager &&) noexcept = default;

hm::netd::NetlinkManager &hm::netd::NetlinkManager::operator=(hm::netd::NetlinkManager &&) noexcept = default;

hm::netd::NetlinkManager::NetlinkManager() {

}


std::shared_ptr<hm::netd::NetlinkListener> hm::netd::NetlinkManager::GetNetlinkListener(const std::string &name) {
    LogInfo("Netlink get cound:%ld", this->netlinks.size());
    auto it = this->netlinks.find(name);
    return it->second;
}

void hm::netd::NetlinkManager::StartListeners() {
    for (auto it = this->netlinks.begin(); it != netlinks.end(); it++) {

        auto netlinkListener = it->second;

        if (it->second == nullptr) {
            LogError("Command Netlink Listener not found!");
            exit(1);
        }

        netlinkListener->StartListen();
    }
}

hm::netd::NetlinkManager::NetlinkManager(std::shared_ptr<NetworkContext> networkContext) : networkContext(networkContext) {

}

void hm::netd::NetlinkManager::AddNetlinkListener(std::string name, std::shared_ptr<NetlinkListener> netlinkListener) {
    this->netlinks.insert(std::pair<std::string, std::shared_ptr<NetlinkListener>>(name, netlinkListener));
    LogInfo("Netlink added '%s'", name.c_str())
}

void hm::netd::NetlinkManager::SetNetworkContext(std::shared_ptr<NetworkContext> networkContext) {
    this->networkContext = networkContext;

}
