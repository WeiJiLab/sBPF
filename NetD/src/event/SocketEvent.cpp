//
// Created by XingfengYang on 2020/5/15.
//

#include "../../include/event/SocketEvent.h"

hm::netd::SocketEvent::~SocketEvent() noexcept = default;

hm::netd::SocketEvent::SocketEvent(hm::netd::SocketEvent &&) noexcept = default;

hm::netd::SocketEvent &hm::netd::SocketEvent::operator=(hm::netd::SocketEvent &&) noexcept = default;

hm::netd::SocketEvent::SocketEvent() {

}
