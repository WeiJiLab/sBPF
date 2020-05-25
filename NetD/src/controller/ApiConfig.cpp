//
// Created by XingfengYang on 2020/5/25.
//

#include "../../include/controller/ApiConfig.h"
#include "../../include/controller/NetlinkController.h"

void hm::netd::ApiConfig::AttachApps(std::shared_ptr<HttpServer> httpServer, std::shared_ptr<NetworkContext> networkContext) {
    hm::netd::NetlinkController netlinkController;
    netlinkController.SetServer(httpServer);
    netlinkController.SetNetworkContext(networkContext);
    netlinkController.Init();
}

