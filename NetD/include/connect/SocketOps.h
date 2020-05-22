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

#include <string>

namespace hm {
  namespace netd {

    using SocketAcceptEventHandler = std::function<void(int fd, void *buffer, size_t len, int flags)>;

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

      virtual ssize_t SendRequest(int family,int type, int sockfd);

      int Receive(SocketAcceptEventHandler acceptEventHandler);

      void SetSocketAcceptEventHandler(SocketAcceptEventHandler acceptEventHandler);

      int Connect(int port);

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
