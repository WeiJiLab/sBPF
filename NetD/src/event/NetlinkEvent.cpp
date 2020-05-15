//
// Created by XingfengYang on 2020/5/15.
//

#include "../../include/event/NetlinkEvent.h"

hm::netd::NetlinkEvent::~NetlinkEvent() noexcept = default;

hm::netd::NetlinkEvent::NetlinkEvent(hm::netd::NetlinkEvent &&) noexcept = default;

hm::netd::NetlinkEvent &hm::netd::NetlinkEvent::operator=(hm::netd::NetlinkEvent &&) noexcept = default;

hm::netd::NetlinkEvent::NetlinkEvent() {

}
