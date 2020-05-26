//
// Created by XingfengYang on 2020/5/20.
//

#ifndef NMCS_ROUTENETLINKEVENT_H
#define NMCS_ROUTENETLINKEVENT_H

#include "NetlinkEvent.h"
#include "../netlink/NetlinkHandler.h"


namespace hm {
    namespace netd {
        class RouteNetlinkEvent : public NetlinkEvent {
        public:
            ~RouteNetlinkEvent() noexcept;

            RouteNetlinkEvent(const RouteNetlinkEvent &) = delete;

            RouteNetlinkEvent(RouteNetlinkEvent &&) noexcept;

            RouteNetlinkEvent &operator=(const RouteNetlinkEvent &) = delete;

            RouteNetlinkEvent &operator=(RouteNetlinkEvent &&) noexcept;

        public:
            RouteNetlinkEvent();

            RouteNetlinkEvent(std::shared_ptr<NetworkContext> networkContext);

            virtual void OnMessageSend() override;

            virtual void OnMessageReceived(struct nlmsghdr *) override;


        private:

        };
    };
};


#endif //NMCS_ROUTENETLINKEVENT_H
