//
// Created by XingfengYang on 2020/5/15.
//

#include "../../include/context/NetworkContext.h"

hm::netd::NetworkContext::~NetworkContext() noexcept = default;

hm::netd::NetworkContext::NetworkContext(hm::netd::NetworkContext &&) noexcept = default;

hm::netd::NetworkContext &hm::netd::NetworkContext::operator=(hm::netd::NetworkContext &&) noexcept = default;

hm::netd::NetworkContext::NetworkContext() :
        mutex(std::make_shared<std::mutex>()),
        network(std::make_shared<NetworkData>()) {

    network->routes.resize(20);

}

void hm::netd::NetworkContext::AddRouteData(hm::netd::RouteData routeData) {
//    std::lock_guard<std::mutex> lock(*mutex);
    this->network->routes.push_back(routeData);
}
