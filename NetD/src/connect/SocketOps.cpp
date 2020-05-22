//
// Created by XingfengYang on 2020/5/12.
//

#include "../../include/connect/SocketOps.h"
#include "../../include/log/Log.h"


hm::netd::SocketOps::SocketOps() {

}

hm::netd::SocketOps::SocketOps(const std::string &sockName) : sockName(sockName),seq(0) {

}

int hm::netd::SocketOps::Config(hm::netd::NetDConfiguration netDConfiguration) {
  this->netDConfiguration = netDConfiguration;
  return 0;
}

int hm::netd::SocketOps::CreateSock() {
  this->sockfd = socket(AF_NETLINK, SOCK_RAW, this->netDConfiguration.type);
  if (this->sockfd < 0) {
      LogError("Socket created failed for socket:'%s'", this->sockName.c_str())
          exit(0);
    }
  if(fcntl(this->sockfd,F_SETFL,O_NONBLOCK)<0){
      LogError("Socket created failed for socket:'%s',ubable to set socket flags", sockName.c_str());
      exit(0);
    }
  return this->sockfd;
}

int hm::netd::SocketOps::Bind() {
  int bindfd = bind(this->sockfd, (struct sockaddr *) &this->netDConfiguration.bindAddr, sizeof(this->netDConfiguration.bindAddr));
  if (bindfd < 0) {
      LogError("Socket bind failed for socket:'%s'", this->sockName.c_str())
          exit(0);
    }
  return bindfd;
}


ssize_t hm::netd::SocketOps::SendRequest(int family,int type,int sockfd) {
  if(sockfd<0){
      LogError("Socket '%s' is not active.",this->sockName.c_str());
      return -1;
    }

  struct {
    struct nlmsghdr nlHeader;
    struct rtgenmsg genMsg;
  } request;

  struct sockaddr_nl socketAddrNetlink;
  socketAddrNetlink.nl_family = AF_NETLINK;

  request.nlHeader.nlmsg_len = sizeof request;
  request.nlHeader.nlmsg_type = type;
  request.nlHeader.nlmsg_flags = NLM_F_ROOT | NLM_F_MATCH | NLM_F_REQUEST;
  request.nlHeader.nlmsg_pid = 0;
  request.nlHeader.nlmsg_seq = ++this->seq;
  request.genMsg.rtgen_family = family;

  int send = sendto(sockfd,(void *)&request,sizeof request,0,(struct sockaddr*)&socketAddrNetlink,sizeof socketAddrNetlink);
  if(send<0){
      LogError("Socket '%s' send msg failed",this->sockName.c_str());
    }
  return 0;
}

int hm::netd::SocketOps::Receive(SocketAcceptEventHandler acceptEventHandler){
  return 0;
}


