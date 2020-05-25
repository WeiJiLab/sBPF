//
// Created by XingfengYang on 2020/5/13.
//

#include "../../include/log/Log.h"
#include "../../include/netlink/NetlinkManager.h"

hm::netd::NetlinkManager::~NetlinkManager() noexcept = default;

hm::netd::NetlinkManager::NetlinkManager(hm::netd::NetlinkManager &&) noexcept = default;

hm::netd::NetlinkManager &hm::netd::NetlinkManager::operator=(hm::netd::NetlinkManager &&) noexcept = default;

hm::netd::NetlinkManager::NetlinkManager() {
    LogInfo("NetlinkManager constractor");
    this->netlinks.insert(std::pair<std::string, std::shared_ptr<NetlinkListener>>("command", std::make_shared<NetlinkListener>("command")));
    LogInfo("Netlink set cound:%ld", this->netlinks.size());
}

std::shared_ptr<hm::netd::NetlinkListener> hm::netd::NetlinkManager::GetNetlinkListener(const std::string &name) {
    LogInfo("Netlink get cound:%ld", this->netlinks.size());
    std::map<std::string, std::shared_ptr<NetlinkListener>>::iterator it = this->netlinks.find(name);
    return it->second;
}
