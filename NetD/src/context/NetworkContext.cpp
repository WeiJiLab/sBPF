//
// Created by XingfengYang on 2020/5/15.
//

#include "../../include/context/NetworkContext.h"

hm::netd::NetworkContext::~NetworkContext() noexcept = default;

hm::netd::NetworkContext::NetworkContext(hm::netd::NetworkContext &&) noexcept = default;

hm::netd::NetworkContext &hm::netd::NetworkContext::operator=(hm::netd::NetworkContext &&) noexcept = default;

hm::netd::NetworkContext::NetworkContext() {

}

void hm::netd::NetworkContext::AddRouteData(hm::netd::RouteData routeData) {
    mutex.lock();
    this->network.routes.push_back(routeData);
    mutex.unlock();
}
