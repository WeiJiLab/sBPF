//
// Created by XingfengYang on 2020/5/25.
//

#ifndef NMCS_APICONTROLLER_H
#define NMCS_APICONTROLLER_H

#include "../http_server/HttpServer.h"
#include "../context/NetworkContext.h"


namespace hm {
    namespace netd {
        class ApiController {
        public:
            virtual void Init();

            void SetServer(std::shared_ptr<HttpServer> server);
            void SetNetworkContext(std::shared_ptr<NetworkContext> networkContext);

        protected:
            std::shared_ptr<HttpServer> httpServer;
            std::shared_ptr<NetworkContext> networkContext;

            void AddRoute(Route route, std::function<HandlerResponse(HttpRequest)> handler);
        };
    }
}

#endif //NMCS_APICONTROLLER_H
