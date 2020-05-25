//
// Created by XingfengYang on 2020/5/13.
//

#ifndef HM_NET_ABSTRACTSERVICELISTENER_H
#define HM_NET_ABSTRACTSERVICELISTENER_H

#include <memory>
#include "../netlink/NetlinkManager.h"
#include "../context/NetworkContext.h"

namespace hm {
    namespace netd {
        class AbstractServiceListener {
        public:
            virtual void SetNetlinkManager(std::shared_ptr<NetlinkManager> netlinkManager);

            virtual void SetNetworkContext(std::shared_ptr<NetworkContext> networkContext);

        protected:
            std::shared_ptr<NetlinkManager> netlinkManager;
            std::shared_ptr<NetworkContext> networkContext;
        };
    }
}


#endif //HM_NET_ABSTRACTSERVICELISTENER_H
