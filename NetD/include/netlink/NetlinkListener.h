//
// Created by XingfengYang on 2020/5/15.
//

#ifndef NMCS_NETLINKLISTENER_H
#define NMCS_NETLINKLISTENER_H

#include <memory>

#include "../connect/SocketOps.h"
#include "../event/NetlinkEvent.h"
#include "../connect/SocketListener.h"

namespace hm {
    namespace netd {

        struct NetlinkListenerConfiguration {
            NetDConfiguration netdConfiguration;
        };

        class NetlinkListener : public SocketListener {
        public:
            ~NetlinkListener() noexcept;

            NetlinkListener(const NetlinkListener &) = delete;

            NetlinkListener(NetlinkListener &&) noexcept;

            NetlinkListener &operator=(const NetlinkListener &) = delete;

            NetlinkListener &operator=(NetlinkListener &&) noexcept;

        public:
            NetlinkListener();

            NetlinkListener(const std::string &socketName, std::shared_ptr<NetlinkEvent> netlinkEvent, NetlinkListenerConfiguration netlinkConfiguration);

            void SendRequest(int type);

            void StartListen();

            int ReceiveHandler(struct sockaddr_nl *nlAddr, struct nlmsghdr *msg, void *);

            std::string GetName() { return socketName; }

        private:
            std::shared_ptr<NetlinkEvent> netlinkEvent;
            std::string socketName;
            NetlinkListenerConfiguration netlinkConfiguration;
        };
    }
}


#endif //NMCS_NETLINKLISTENER_H
