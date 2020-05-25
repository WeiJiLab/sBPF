//
// Created by XingfengYang on 2020/5/15.
//

#include "../../include/netlink/NetlinkListener.h"
#include "../../include/log/Log.h"
#include <unistd.h>


hm::netd::NetlinkListener::~NetlinkListener() noexcept = default;

hm::netd::NetlinkListener::NetlinkListener(hm::netd::NetlinkListener &&) noexcept = default;

hm::netd::NetlinkListener &hm::netd::NetlinkListener::operator=(hm::netd::NetlinkListener &&) noexcept = default;

hm::netd::NetlinkListener::NetlinkListener() {
}


hm::netd::NetlinkListener::NetlinkListener(const std::string &socketName) : SocketListener(socketName) {
    this->socketName = socketName;
}


void hm::netd::NetlinkListener::SetNetlinkEvent(std::shared_ptr<NetlinkEvent> netlinkEvent) {
    this->netlinkEvent = netlinkEvent;
}

void hm::netd::NetlinkListener::Config(NetDConfiguration netdConfiguration) {
    this->socketOps->Config(netdConfiguration);
}

int hm::netd::NetlinkListener::ReceiveHandler(struct sockaddr_nl *nlAddr, struct nlmsghdr *msg, void *) {
    LogInfo("Message from netLink received.");
    this->netlinkEvent->OnMessageReceived(msg);
}

void hm::netd::NetlinkListener::StartListen() {
    LogInfo("CommandNetlinkListener Listening...");
    if (this->socketOps == nullptr) {
        LogError("socket op is null");
    }

    this->socketOps->CreateSock();

    this->socketOps->Bind();

    int nlSockFd = this->socketOps->GetSock();

    const auto bind = std::bind(&NetlinkListener::ReceiveHandler, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
    this->SendRequest(RTM_GETROUTE);
    while (!(this->socketOps->Receive(bind, nlSockFd, (void *) 0) < 0)) {
        this->SendRequest(RTM_GETROUTE);
        sleep(5);
    }
}

void hm::netd::NetlinkListener::SendRequest(int type) {
    this->socketOps->SendRequest(AF_INET, type, this->socketOps->GetSock());
    this->netlinkEvent->OnMessageSend();
}
