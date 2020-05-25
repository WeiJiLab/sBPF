//
// Created by XingfengYang on 2020/5/15.
//

#ifndef NMCS_NETWORK_CONTEXT_H
#define NMCS_NETWORK_CONTEXT_H

#include <memory>

#include "../connect/SocketOps.h"
#include "../event/NetlinkEvent.h"
#include "../connect/SocketListener.h"

namespace hm {
    namespace netd {

        struct NetworkData {

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
        private:
            NetworkData network;
        };
    }
}


#endif //NMCS_NETWORK_CONTEXT_H
