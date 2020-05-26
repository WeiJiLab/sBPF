//
// Created by XingfengYang on 2020/5/25.
//

#include "../../include/controller/ApiController.h"
#include "../../include/log/Log.h"

void hm::netd::ApiController::Init() {

}

void hm::netd::ApiController::AddRoute(Route route, std::function<HandlerResponse(HttpRequest)> handler) {
    this->httpServer->AddRoute(route, handler);
}

void hm::netd::ApiController::SetServer(std::shared_ptr<HttpServer> server) {
    this->httpServer = server;
}

void hm::netd::ApiController::SetNetworkContext(std::shared_ptr<NetworkContext> networkContext) {
    this->networkContext = networkContext;
}
