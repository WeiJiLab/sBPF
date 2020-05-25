//
// Created by XingfengYang on 2020/5/15.
//

#ifndef NMCS_NETLINKEVENT_H
#define NMCS_NETLINKEVENT_H

#include <memory>
#include "SocketEvent.h"
#include "../netlink/NetlinkHandler.h"
#include "../context/NetworkContext.h"

namespace hm {
    namespace netd {
        class NetlinkEvent : public SocketEvent {
        public:
            NetlinkEvent();

            virtual void OnMessageSend() = 0;

            virtual void OnMessageReceived(struct nlmsghdr *) = 0;

            virtual void SetNetlinkHandler(std::shared_ptr<NetlinkHandler> netlinkHandler);
            virtual void SetNetworkContext(std::shared_ptr<NetworkContext> networkContext);

        protected:
            std::shared_ptr<NetlinkHandler> netlinkHandler;
            std::shared_ptr<NetworkContext> networkContext;
        };
    }
}


#endif //NMCS_NETLINKEVENT_H
