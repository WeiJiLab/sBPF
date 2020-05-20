//
// Created by XingfengYang on 2020/5/15.
//

#include "../../include/connect/SocketListener.h"
#include "../../include/log/Log.h"

hm::netd::SocketListener::SocketListener():socketOps(std::make_shared<SocketOps>()) {
  LogInfo("SocketListener constructor");
}



hm::netd::SocketListener::SocketListener(const std::string& socketName) {
  this->socketOps = std::make_shared<SocketOps>(socketName);
  LogInfo("SocketListener constructor");
}

