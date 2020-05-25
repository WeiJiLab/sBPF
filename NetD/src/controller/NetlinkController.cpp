//
// Created by XingfengYang on 2020/5/25.
//

#include "../../include/controller/NetlinkController.h"
#include "../../include/log/Log.h"


void hm::netd::NetlinkController::Init() {
    this->AddRoute({"/getRoute", GET}, std::bind(&NetlinkController::GetRoute, this, std::placeholders::_1));
}

hm::netd::HandlerResponse hm::netd::NetlinkController::GetRoute(hm::netd::HttpRequest request) {

    assert(networkContext!=NULL);

    std::vector<RouteData> routes = networkContext->GetRoutesData();


    LogInfo("[Controller] GetRoute size:%d",routes.size());

    std::string result = "{\"routes\":[";
//    for (auto &route:routes) {
//        result += "{\"destination\":\"" + route.destination + "\",\"gateway\":" + route.gateway + "\"},";
//    }

    result += "]";
    return {OK, result};
}
