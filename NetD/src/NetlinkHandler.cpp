//
// Created by XingfengYang on 2020/5/15.
//

#include "../include/netlink/NetlinkHandler.h"

hm::netd::NetlinkHandler::~NetlinkHandler() noexcept = default;

hm::netd::NetlinkHandler::NetlinkHandler(hm::netd::NetlinkHandler &&) noexcept = default;

hm::netd::NetlinkHandler &hm::netd::NetlinkHandler::operator=(hm::netd::NetlinkHandler &&) noexcept = default;

hm::netd::NetlinkHandler::NetlinkHandler() {

}
