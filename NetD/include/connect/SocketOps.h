//
// Created by XingfengYang on 2020/5/12.
//

#ifndef NMCS_SOCKETOPS_H
#define NMCS_SOCKETOPS_H

#include <functional>
#include <bits/sockaddr.h>
#include <sys/socket.h>
#include <asm/types.h>
#include <linux/netlink.h>

#include <string>

namespace hm {
    namespace netd {

        using SocketAcceptEventHandler = std::function<void(int fd, void *buffer, size_t len, int flags)>;

        struct NetDConfiguration {
            struct sockaddr_nl {
                sa_family_t nl_family; //AF_NETLINK
                unsigned short nl_pad;
                unsigned int nl_pid;
                unsigned int nl_group;
            };

            struct nlmsghdr {
                unsigned int nlmsg_len;
                unsigned short nlmsg_type;
                unsigned short nlmsg_flags;
                unsigned int nlmsg_seq;
                unsigned int nlmsg_pid;
            };
        };

        class SocketOps {
        public:
            SocketOps();
            SocketOps(std::string &sockName);

            int Config(NetDConfiguration netDConfiguration);

            int SetUp();

            int Bind();

            int Listen();

            virtual int Accept(SocketAcceptEventHandler acceptEventHandler) = 0;

            void SetSocketAcceptEventHandler(SocketAcceptEventHandler acceptEventHandler);

            int Connect(int port);

            virtual ssize_t Send(int fd, const struct msghdr *msg, int flags);

        private:
            SocketAcceptEventHandler socketAcceptEventHandler;

            std::string sockName;
        };
    };
};


#endif //NMCS_SOCKETOPS_H
