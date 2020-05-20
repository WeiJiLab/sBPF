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
        class NetlinkListener : public SocketListener {
        public:
            ~NetlinkListener() noexcept;

            NetlinkListener(const NetlinkListener &) = delete;

            NetlinkListener(NetlinkListener &&) noexcept;

            NetlinkListener &operator=(const NetlinkListener &) = delete;

            NetlinkListener &operator=(NetlinkListener &&) noexcept;

        public:
            NetlinkListener();

            NetlinkListener(const std::string &socketName);


            void SetNetlinkEvent(std::shared_ptr<NetlinkEvent> netlinkEvent);

            void Config(NetDConfiguration netdConfiguration);

            void StartListen();

        private:
            std::shared_ptr<NetlinkEvent> netlinkEvent;
            std::string socketName;
        };
    }
}


#endif //NMCS_NETLINKLISTENER_H
