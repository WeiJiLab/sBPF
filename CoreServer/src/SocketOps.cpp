//
// Created by XingfengYang on 2020/5/12.
//

#include "../include/SocketOps.h"


hm::netd::SocketOps::~SocketOps() noexcept = default;

hm::netd::SocketOps::SocketOps(hm::netd::SocketOps &&) noexcept = default;

hm::netd::SocketOps &hm::netd::SocketOps::operator=(hm::netd::SocketOps &&) noexcept = default;

hm::netd::SocketOps::SocketOps() {

}
