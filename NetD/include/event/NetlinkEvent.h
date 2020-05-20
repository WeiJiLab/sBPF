//
// Created by XingfengYang on 2020/5/15.
//

#ifndef NMCS_NETLINKEVENT_H
#define NMCS_NETLINKEVENT_H

#include "SocketEvent.h"

namespace hm {
    namespace netd {
        class NetlinkEvent : public SocketEvent {
        public:
            NetlinkEvent();

            virtual void OnMessageSend() = 0;

            virtual void OnMessageReceived() = 0;

        };
    }
}


#endif //NMCS_NETLINKEVENT_H
