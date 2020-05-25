//
// Created by XingfengYang on 2020/5/15.
//

#ifndef NMCS_NETWORK_CONTEXT_H
#define NMCS_NETWORK_CONTEXT_H

#include <memory>
#include <string>
#include <vector>

#include "../connect/SocketOps.h"
#include "../event/NetlinkEvent.h"
#include "../connect/SocketListener.h"

namespace hm {
    namespace netd {


        struct RouteData {
            std::string destination;
            int rtm_dst_len;
            std::string gateway;
        };
        struct NetworkData {
            std::vector<RouteData> routes;
        };

        class NetworkContext {
        public:
            ~NetworkContext() noexcept;

            NetworkContext(const NetworkContext &) = delete;

            NetworkContext(NetworkContext &&) noexcept;

            NetworkContext &operator=(const NetworkContext &) = delete;

            NetworkContext &operator=(NetworkContext &&) noexcept;

        public:
            NetworkContext();

        public:
            std::vector<RouteData> GetRoutesData() { return this->network.routes; };

            void AddRouteData(RouteData routeData);

        private:
            NetworkData network;
        };
    }
}


#endif //NMCS_NETWORK_CONTEXT_H
