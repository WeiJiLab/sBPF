//
// Created by XingfengYang on 2020/5/12.
//

#ifndef NMCS_SOCKETOPS_H
#define NMCS_SOCKETOPS_H

#include <functional>
#include <sys/socket.h>

#include <bits/sockaddr.h>
#include <asm/types.h>
#include <linux/netlink.h>

#include <string>

namespace hm {
    namespace netd {

        using SocketAcceptEventHandler = std::function<void(int fd, void *buffer, size_t len, int flags)>;


        struct sockaddr_nl {
            sa_family_t nl_family; //AF_NETLINK
            unsigned short nl_pad;
            unsigned int nl_pid;

            /**
             * NETLINK_ROUTE
             *
             * RTMGRP_LINK          ; when network changed
             * RTMGRP_IPV4_IFADDR   ; when ipv4 address changed
             * RTMGRP_IPV4_ROUTE    ; when ipv4 route changed
             * RTMGRP_IPV6_IFADDR   ; when ipv6 address changed
             * RTMGRP_IPV6_ROUTE    ; when ipv6 route changed
             */
            unsigned int nl_group;
        };


        struct nlmsghdr {
            unsigned int nlmsg_len;

            /**
             * RTM_NEWLINK/RTM_DELLINK      ; from kernel when network changed
             * RTM_NEWADDR/RTM_DELADDR      ; from kernel when ip address changed
             * RTM_NEWROUTE/RTM_DELROUTE    ; form kernel when route changed
             */
            unsigned short nlmsg_type;
            unsigned short nlmsg_flags;
            unsigned int nlmsg_seq;
            unsigned int nlmsg_pid;
        };
        struct NetDConfiguration {
            int type;
            sockaddr_nl bindAddr;
        };

        class SocketOps {
        public:
            SocketOps();

            SocketOps(const std::string &sockName);

            int Config(NetDConfiguration netDConfiguration);

            int CreateSock();

            int Bind();

            int Listen();

            int Receive(SocketAcceptEventHandler acceptEventHandler);

            void SetSocketAcceptEventHandler(SocketAcceptEventHandler acceptEventHandler);

            int Connect(int port);

            virtual ssize_t SendRequest(int fd, const struct msghdr *msg, int flags);

        private:
            SocketAcceptEventHandler socketAcceptEventHandler;

            NetDConfiguration netDConfiguration;

            int sockfd;
            std::string sockName;

        };
    };
};


#endif //NMCS_SOCKETOPS_H
