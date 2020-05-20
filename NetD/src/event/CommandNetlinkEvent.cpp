//
// Created by XingfengYang on 2020/5/20.
//

#include "../../include/event/CommandNetlinkEvent.h"


hm::netd::CommandNetlinkEvent::~CommandNetlinkEvent() noexcept = default;

hm::netd::CommandNetlinkEvent::CommandNetlinkEvent(hm::netd::CommandNetlinkEvent &&) noexcept = default;

hm::netd::CommandNetlinkEvent &hm::netd::CommandNetlinkEvent::operator=(hm::netd::CommandNetlinkEvent &&) noexcept = default;

hm::netd::CommandNetlinkEvent::CommandNetlinkEvent() {

}


void hm::netd::CommandNetlinkEvent::OnMessageSend() {

}

void hm::netd::CommandNetlinkEvent::OnMessageReceived() {

}
