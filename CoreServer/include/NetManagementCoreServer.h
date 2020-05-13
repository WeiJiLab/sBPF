//
// Created by XingfengYang on 2020/5/12.
//

#ifndef NMCS_NETMANAGEMENTCORESERVER_H
#define NMCS_NETMANAGEMENTCORESERVER_H

#include <memory>
#include "CommandListener.h"
#include "DnsProxyListener.h"
#include "MDnsSdListener.h"
#include "FwmarkServer.h"

namespace hm {
    namespace netd {
        class NetManagementCoreServer {
        public:
            ~NetManagementCoreServer() noexcept;

            NetManagementCoreServer(const NetManagementCoreServer &) = delete;

            NetManagementCoreServer(NetManagementCoreServer &&) noexcept;

            NetManagementCoreServer &operator=(const NetManagementCoreServer &) = delete;

            NetManagementCoreServer &operator=(NetManagementCoreServer &&) noexcept;

            void Start();

        public:
            NetManagementCoreServer();

        private:
            std::shared_ptr<CommandListener> commandListener;
            std::shared_ptr<DnsProxyListener> dnsProxyListener;
            std::shared_ptr<MDnsSdListener> mdnsSdListener;
            std::shared_ptr<FwmarkServer> fwmarkServer;
        };
    }
};


#endif //NMCS_NETMANAGEMENTCORESERVER_H
