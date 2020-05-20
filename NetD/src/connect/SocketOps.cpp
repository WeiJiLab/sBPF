//
// Created by XingfengYang on 2020/5/12.
//

#include "../../include/connect/SocketOps.h"
#include "../../include/log/Log.h"


hm::netd::SocketOps::SocketOps() {

}

hm::netd::SocketOps::SocketOps(const std::string &sockName) : sockName(sockName) {

}

int hm::netd::SocketOps::Config(hm::netd::NetDConfiguration netDConfiguration) {
  return 0;
}

int hm::netd::SocketOps::CreateSock() {
  this->sockfd = socket(AF_NETLINK, SOCK_RAW, this->netDConfiguration.type);
  if (this->sockfd < 0) {
      LogError("Socket created failed for socket:'%s'", sockName.c_str())
          exit(0);
    }
  return this->sockfd;
}

int hm::netd::SocketOps::Bind() {
  int bindfd = bind(this->sockfd, (struct sockaddr *) &this->netDConfiguration.bindAddr, sizeof(this->netDConfiguration.bindAddr));
  if (bindfd < 0) {
      LogError("Socket bind failed for socket:'%s'", sockName.c_str())
          exit(0);
    }
  return bindfd;
}

int hm::netd::SocketOps::Listen() {
  return 0;
}

int hm::netd::SocketOps::Receive(SocketAcceptEventHandler acceptEventHandler){
  return 0;
}

void hm::netd::SocketOps::SetSocketAcceptEventHandler(hm::netd::SocketAcceptEventHandler acceptEventHandler) {
  this->socketAcceptEventHandler = socketAcceptEventHandler;
}

int hm::netd::SocketOps::Connect(int port) {
  return 0;
}

ssize_t hm::netd::SocketOps::SendRequest(int fd, const struct msghdr *msg, int flags) {
  return 0;
}

