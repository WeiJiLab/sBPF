//
// Created by XingfengYang on 2020/5/25.
//

#ifndef NMCS_APICONFIG_H
#define NMCS_APICONFIG_H

#include "../http_server/HttpServer.h"
#include "../../include/context/NetworkContext.h"
#include "ApiController.h"

namespace hm {
    namespace netd {
        class ApiConfig {
        public:
            void AttachApps(std::shared_ptr<HttpServer> httpServer, std::shared_ptr<NetworkContext> networkContext);
        };
    }
}

#endif //NMCS_APICONFIG_H
