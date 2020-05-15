//
// Created by XingfengYang on 2020/5/15.
//

#ifndef NMCS_NETLINKLISTENER_H
#define NMCS_NETLINKLISTENER_H

#include <memory>

#include "../connect/SocketOps.h"
#include "../event/NetlinkEvent.h"

namespace hm {
    namespace netd {
        class NetlinkListener : public SocketOps {
        public:
            ~NetlinkListener() noexcept;

            NetlinkListener(const NetlinkListener &) = delete;

            NetlinkListener(NetlinkListener &&) noexcept;

            NetlinkListener &operator=(const NetlinkListener &) = delete;

            NetlinkListener &operator=(NetlinkListener &&) noexcept;

        public:
            NetlinkListener();


            void SetNetlinkEvent(std::shared_ptr<NetlinkEvent> netlinkEvent);

        private:
            std::shared_ptr<NetlinkEvent> netlinkEvent;
        };
    }
}


#endif //NMCS_NETLINKLISTENER_H
