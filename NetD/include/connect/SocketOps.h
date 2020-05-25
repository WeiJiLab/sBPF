//
// Created by XingfengYang on 2020/5/12.
//

#ifndef NMCS_SOCKETOPS_H
#define NMCS_SOCKETOPS_H

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

        using SocketAcceptEventHandler = std::function<int(struct sockaddr_nl *, struct nlmsghdr *, void *)>;

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

            virtual ssize_t SendRequest(int family, int type, int sockfd);

            int Receive(SocketAcceptEventHandler acceptEventHandler, int nlSockFd, void *arg);

            int GetSock() { return this->sockfd; }

        private:
            SocketAcceptEventHandler socketAcceptEventHandler;

            NetDConfiguration netDConfiguration;

            int sockfd;
            int seq;
            std::string sockName;

        };
    };
};


#endif //NMCS_SOCKETOPS_H
