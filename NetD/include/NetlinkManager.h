//
// Created by XingfengYang on 2020/5/13.
//

#ifndef HM_NET_NETLINKMANAGER_H
#define HM_NET_NETLINKMANAGER_H

#include <memory>
#include "SocketOps.h"

namespace hm {
    namespace netd {
        class NetlinkManager {
        public:
            ~NetlinkManager() noexcept;

            NetlinkManager(const NetlinkManager &) = delete;

            NetlinkManager(NetlinkManager &&) noexcept;

            NetlinkManager &operator=(const NetlinkManager &) = delete;

            NetlinkManager &operator=(NetlinkManager &&) noexcept;

        public:
            NetlinkManager();

        private:
            std::shared_ptr<SocketOps> socketOps;
        };
    }
}


#endif //HM_NET_NETLINKMANAGER_H
