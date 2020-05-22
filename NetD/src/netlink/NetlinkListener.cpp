//
// Created by XingfengYang on 2020/5/15.
//

#include "../../include/netlink/NetlinkListener.h"
#include "../../include/log/Log.h"

hm::netd::NetlinkListener::~NetlinkListener() noexcept = default;

hm::netd::NetlinkListener::NetlinkListener(hm::netd::NetlinkListener &&) noexcept = default;

hm::netd::NetlinkListener &hm::netd::NetlinkListener::operator=(hm::netd::NetlinkListener &&) noexcept = default;

hm::netd::NetlinkListener::NetlinkListener() {
}


hm::netd::NetlinkListener::NetlinkListener(const std::string &socketName):SocketListener(socketName){
  this->socketName = socketName;
}


void hm::netd::NetlinkListener::SetNetlinkEvent(std::shared_ptr<NetlinkEvent> netlinkEvent) {
  this->netlinkEvent = netlinkEvent;
}

void hm::netd::NetlinkListener::Config(NetDConfiguration netdConfiguration){
  this->socketOps->Config(netdConfiguration);
}

void hm::netd::NetlinkListener::StartListen() {
  LogInfo("CommandNetlinkListener Listening...");
  if(this->socketOps==nullptr){
      LogError("socket op is null");
    }

  this->socketOps->CreateSock();

  this->socketOps->Bind();
}
