//
// Created by XingfengYang on 2020/5/15.
//

#ifndef NMCS_NETLINKEVENT_H
#define NMCS_NETLINKEVENT_H

namespace hm {
    namespace netd {
        class NetlinkEvent {
        public:
            ~NetlinkEvent() noexcept;

            NetlinkEvent(const NetlinkEvent &) = delete;

            NetlinkEvent(NetlinkEvent &&) noexcept;

            NetlinkEvent &operator=(const NetlinkEvent &) = delete;

            NetlinkEvent &operator=(NetlinkEvent &&) noexcept;

        public:
            NetlinkEvent();

            void OnMessageSend();

            void OnMessageReceived();


        };
    }
}


#endif //NMCS_NETLINKEVENT_H
