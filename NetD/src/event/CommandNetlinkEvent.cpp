//
// Created by XingfengYang on 2020/5/20.
//

#include "../../include/event/CommandNetlinkEvent.h"


hm::netd::CommandNetlinkEvent::~CommandNetlinkEvent() noexcept = default;

hm::netd::CommandNetlinkEvent::CommandNetlinkEvent(hm::netd::CommandNetlinkEvent &&) noexcept = default;

hm::netd::CommandNetlinkEvent &hm::netd::CommandNetlinkEvent::operator=(hm::netd::CommandNetlinkEvent &&) noexcept = default;

hm::netd::CommandNetlinkEvent::CommandNetlinkEvent() {

}


void hm::netd::CommandNetlinkEvent::OnMessageSend() {

}

void hm::netd::CommandNetlinkEvent::OnMessageReceived(struct nlmsghdr *msg) {
 struct rtmsg * rte = (rtmsg*)NLMSG_DATA(msg);
    struct rtattr * attr = RTM_RTA(rte);
    int len = RTM_PAYLOAD(msg);
    char dest[32] = {0};
    char gway[32] = {"unspecified"};

    if (rte->rtm_table != RT_TABLE_MAIN) {
        return;
    }

    for (; RTA_OK(attr, len); attr = RTA_NEXT(attr, len))
    {
        switch (attr->rta_type)
        {
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

    

    printf("%s/%d gateway %s\n", dest, rte->rtm_dst_len, gway);
}
