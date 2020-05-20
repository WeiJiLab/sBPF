//
// Created by XingfengYang on 2020/5/13.
//

#include "../../include/netlink/NetlinkManager.h"

hm::netd::NetlinkManager::~NetlinkManager() noexcept = default;

hm::netd::NetlinkManager::NetlinkManager(hm::netd::NetlinkManager &&) noexcept = default;

hm::netd::NetlinkManager &hm::netd::NetlinkManager::operator=(hm::netd::NetlinkManager &&) noexcept = default;

hm::netd::NetlinkManager::NetlinkManager() {

}

std::shared_ptr<hm::netd::NetlinkListener> hm::netd::NetlinkManager::GetNetlinkListener(const std::string &name) {
    return std::make_shared<hm::netd::NetlinkListener>("command");
}
