//
// Created by XingfengYang on 2020/5/13.
//

#ifndef HM_NET_NETLINKMANAGER_H
#define HM_NET_NETLINKMANAGER_H

#include <memory>
#include <string>
#include <map>
#include "../connect/SocketOps.h"
#include "../netlink/NetlinkListener.h"

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
            NetlinkManager(std::shared_ptr<NetworkContext> networkContext);


            void StartListeners();

            void SetNetworkContext(std::shared_ptr<NetworkContext> network);

            void AddNetlinkListener(std::shared_ptr<NetlinkListener> netlinkListener);
            std::shared_ptr<hm::netd::NetlinkListener> GetNetlinkListener(const std::string &name);


        private:
            std::map<std::string, std::shared_ptr<NetlinkListener>> netlinks;
            std::shared_ptr<NetworkContext> networkContext;
        };
    }
}


#endif //HM_NET_NETLINKMANAGER_H
