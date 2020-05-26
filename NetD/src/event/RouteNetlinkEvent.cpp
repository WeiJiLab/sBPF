//
// Created by XingfengYang on 2020/5/20.
//

#include "../../include/event/RouteNetlinkEvent.h"
#include "../../include/log/Log.h"


hm::netd::RouteNetlinkEvent::~RouteNetlinkEvent() noexcept = default;

hm::netd::RouteNetlinkEvent::RouteNetlinkEvent(hm::netd::RouteNetlinkEvent &&) noexcept = default;

hm::netd::RouteNetlinkEvent &hm::netd::RouteNetlinkEvent::operator=(hm::netd::RouteNetlinkEvent &&) noexcept = default;

hm::netd::RouteNetlinkEvent::RouteNetlinkEvent() {

}

hm::netd::RouteNetlinkEvent::RouteNetlinkEvent(std::shared_ptr<NetworkContext> networkContext) : NetlinkEvent(networkContext) {

}


void hm::netd::RouteNetlinkEvent::OnMessageSend() {

}

void hm::netd::RouteNetlinkEvent::OnMessageReceived(struct nlmsghdr *msg) {
    struct rtmsg *rte = (rtmsg *) NLMSG_DATA(msg);
    struct rtattr *attr = RTM_RTA(rte);
    int len = RTM_PAYLOAD(msg);
    char dest[32] = {0};
    char gway[32] = {"unspecified"};

    if (rte->rtm_table != RT_TABLE_MAIN) {
        return;
    }

    for (; RTA_OK(attr, len); attr = RTA_NEXT(attr, len)) {
        switch (attr->rta_type) {
            case RTA_DST:
                inet_ntop(AF_INET, RTA_DATA(attr), dest, sizeof(dest));
                break;
            case RTA_GATEWAY:
                inet_ntop(AF_INET, RTA_DATA(attr), gway, sizeof(gway));
                break;
            default:
                break;
        }
    }

    LogInfo("[Event] update Routes in network context")
    this->networkContext->AddRouteData({
                                               .destination=dest,
                                               .rtm_dst_len = rte->rtm_dst_len,
                                               .gateway= gway
                                       });

    printf("%s/%d gateway %s\n", dest, rte->rtm_dst_len, gway);
}

