//
// Created by XingfengYang on 2020/5/12.
//

#include "../../include/connect/SocketOps.h"


hm::netd::SocketOps::SocketOps() {

}

hm::netd::SocketOps::SocketOps(std::string &sockName) : sockName(sockName) {

}

int hm::netd::SocketOps::Config(hm::netd::NetDConfiguration netDConfiguration) {
    return 0;
}

int hm::netd::SocketOps::SetUp() {
    return 0;
}

int hm::netd::SocketOps::Bind() {
    return 0;
}

int hm::netd::SocketOps::Listen() {
    return 0;
}

void hm::netd::SocketOps::SetSocketAcceptEventHandler(hm::netd::SocketAcceptEventHandler acceptEventHandler) {
    this->socketAcceptEventHandler = socketAcceptEventHandler;
}

int hm::netd::SocketOps::Connect(int port) {
    return 0;
}

ssize_t hm::netd::SocketOps::Send(int fd, const struct msghdr *msg, int flags) {
    return 0;
}

