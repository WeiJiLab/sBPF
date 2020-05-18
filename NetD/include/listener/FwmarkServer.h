//
// Created by XingfengYang on 2020/5/13.
//

#ifndef HM_NET_FWMARKSERVER_H
#define HM_NET_FWMARKSERVER_H

#include "../listener/AbstractServiceListener.h"

namespace hm {
    namespace netd {
        class FwmarkServer : public AbstractServiceListener {
        public:
            ~FwmarkServer() noexcept;

            FwmarkServer(const FwmarkServer &) = delete;

            FwmarkServer(FwmarkServer &&) noexcept;

            FwmarkServer &operator=(const FwmarkServer &) = delete;

            FwmarkServer &operator=(FwmarkServer &&) noexcept;

            virtual void SetNetlinkManager(std::shared_ptr<NetlinkManager> netlinkManager);

        public:
            FwmarkServer();

            int StartListener() const;
        };
    }
}


#endif //HM_NET_FWMARKSERVER_H
