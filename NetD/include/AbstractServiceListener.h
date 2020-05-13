//
// Created by XingfengYang on 2020/5/13.
//

#ifndef HM_NET_ABSTRACTSERVICELISTENER_H
#define HM_NET_ABSTRACTSERVICELISTENER_H

#include <memory>
#include "NetlinkManager.h"

namespace hm {
    namespace netd {
        class AbstractServiceListener {
        public:
            virtual void SetNetlink(std::shared_ptr<NetlinkManager> netlinkManager);
        private:
            std::shared_ptr<NetlinkManager> netlinkManager;
        };
    }
}


#endif //HM_NET_ABSTRACTSERVICELISTENER_H
