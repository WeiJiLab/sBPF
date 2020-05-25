//
// Created by XingfengYang on 2020/5/15.
//

#ifndef NMCS_SOCKETEVENT_H
#define NMCS_SOCKETEVENT_H
#include <functional>
#include <sys/socket.h>
#include <linux/types.h>
#include <bits/sockaddr.h>
#include <asm/types.h>
#include <linux/netlink.h>
#include <linux/if.h>
#include <linux/rtnetlink.h>
#include <sys/file.h>
#include <sys/fcntl.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include <arpa/inet.h>

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
