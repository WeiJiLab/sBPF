//
// Created by XingfengYang on 2020/5/15.
//

#include "../../include/netlink/NetlinkListener.h"
#include "../../include/log/Log.h"

hm::netd::NetlinkListener::~NetlinkListener() noexcept = default;

hm::netd::NetlinkListener::NetlinkListener(hm::netd::NetlinkListener &&) noexcept = default;

hm::netd::NetlinkListener &hm::netd::NetlinkListener::operator=(hm::netd::NetlinkListener &&) noexcept = default;

hm::netd::NetlinkListener::NetlinkListener() {

}

void hm::netd::NetlinkListener::SetNetlinkEvent(std::shared_ptr<NetlinkEvent> netlinkEvent) {

}

void hm::netd::NetlinkListener::StartListen() {
    LogInfo("CommandNetlinkListener Listening...")


}
