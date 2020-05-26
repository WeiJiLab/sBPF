//
// Created by XingfengYang on 2020/5/25.
//

#ifndef NMCS_NETLINKCONTROLLER_H
#define NMCS_NETLINKCONTROLLER_H

#include "../http_server/HttpServer.h"
#include "ApiController.h"

namespace hm {
    namespace netd {
        class NetlinkController : public ApiController, public std::enable_shared_from_this<NetlinkController> {
        public:
            void Init();
        public:
            HandlerResponse GetRoute(HttpRequest request);
        };
    }
}


#endif //NMCS_NETLINKCONTROLLER_H
