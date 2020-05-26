//
// Created by XingfengYang on 2020/5/15.
//

#include "../../include/event/NetlinkEvent.h"

hm::netd::NetlinkEvent::NetlinkEvent() {

}

void hm::netd::NetlinkEvent::SetNetlinkHandler(std::shared_ptr<NetlinkHandler> netlinkHandler) {
    this->netlinkHandler = netlinkHandler;
}

void hm::netd::NetlinkEvent::SetNetworkContext(std::shared_ptr<NetworkContext> networkContext) {
    this->networkContext = networkContext;
}

hm::netd::NetlinkEvent::NetlinkEvent(std::shared_ptr<NetworkContext> networkContext) : networkContext(networkContext) {

}
