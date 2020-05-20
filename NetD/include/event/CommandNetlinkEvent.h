//
// Created by XingfengYang on 2020/5/20.
//

#ifndef NMCS_COMMANDNETLINKEVENT_H
#define NMCS_COMMANDNETLINKEVENT_H

#include "NetlinkEvent.h"


namespace hm {
    namespace netd {
        class CommandNetlinkEvent : public NetlinkEvent {
        public:
            ~CommandNetlinkEvent() noexcept;

            CommandNetlinkEvent(const CommandNetlinkEvent &) = delete;

            CommandNetlinkEvent(NetlinkEvent &&) noexcept;

            CommandNetlinkEvent &operator=(const CommandNetlinkEvent &) = delete;

            CommandNetlinkEvent &operator=(CommandNetlinkEvent &&) noexcept;

        public:
            CommandNetlinkEvent();

            virtual void OnMessageSend() override;

            virtual void OnMessageReceived() override;
        };
    };
};


#endif //NMCS_COMMANDNETLINKEVENT_H
