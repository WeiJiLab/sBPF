//
// Created by XingfengYang on 2020/5/13.
//

#include "../include/NetlinkManager.h"

hm::netd::NetlinkManager::~NetlinkManager() noexcept = default;

hm::netd::NetlinkManager::NetlinkManager(hm::netd::NetlinkManager &&) noexcept = default;

hm::netd::NetlinkManager &hm::netd::NetlinkManager::operator=(hm::netd::NetlinkManager &&) noexcept = default;

hm::netd::NetlinkManager::NetlinkManager() {

}
