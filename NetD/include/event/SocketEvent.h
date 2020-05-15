//
// Created by XingfengYang on 2020/5/15.
//

#ifndef NMCS_SOCKETEVENT_H
#define NMCS_SOCKETEVENT_H

namespace hm {
    namespace netd {
        class SocketEvent {
        public:
            ~SocketEvent() noexcept;

            SocketEvent(const SocketEvent &) = delete;

            SocketEvent(SocketEvent &&) noexcept;

            SocketEvent &operator=(const SocketEvent &) = delete;

            SocketEvent &operator=(SocketEvent &&) noexcept;

        public:
            SocketEvent();

            void OnSend();

            void OnReceived();
        };
    }
}


#endif //NMCS_SOCKETEVENT_H
