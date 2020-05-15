//
// Created by XingfengYang on 2020/5/13.
//

#include "../../include/listener/FwmarkServer.h"

hm::netd::FwmarkServer::~FwmarkServer() noexcept = default;

hm::netd::FwmarkServer::FwmarkServer(hm::netd::FwmarkServer &&) noexcept = default;

hm::netd::FwmarkServer &hm::netd::FwmarkServer::operator=(hm::netd::FwmarkServer &&) noexcept = default;

hm::netd::FwmarkServer::FwmarkServer() {

}

int hm::netd::FwmarkServer::StartListener() const {
    return 1;
}
