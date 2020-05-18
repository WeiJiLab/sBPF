//
// Created by XingfengYang on 2020/5/12.
//

#ifndef NMCS_NETMANAGEMENTCORESERVER_H
#define NMCS_NETMANAGEMENTCORESERVER_H

#include <memory>
#include "listener/CommandListener.h"
#include "listener/DnsProxyListener.h"
#include "listener/MDnsSdListener.h"
#include "listener/FwmarkServer.h"

namespace hm {
    namespace netd {
        class NetManagementCoreServer {
        public:
            ~NetManagementCoreServer() noexcept;

            NetManagementCoreServer(const NetManagementCoreServer &) = delete;

            NetManagementCoreServer(NetManagementCoreServer &&) noexcept;

            NetManagementCoreServer &operator=(const NetManagementCoreServer &) = delete;

            NetManagementCoreServer &operator=(NetManagementCoreServer &&) noexcept;



            void Init();
            void Start();

        public:
            NetManagementCoreServer();

        private:
            std::shared_ptr<CommandListener> commandListener;
            std::shared_ptr<DnsProxyListener> dnsProxyListener;
            std::shared_ptr<MDnsSdListener> mdnsSdListener;
            std::shared_ptr<FwmarkServer> fwmarkServer;

            std::shared_ptr<NetlinkManager> netlinkManager;
        };
    }
};


#endif //NMCS_NETMANAGEMENTCORESERVER_H
