//
// Created by XingfengYang on 2020/5/15.
//

#ifndef NMCS_SOCKETLISTENER_H
#define NMCS_SOCKETLISTENER_H

#include <memory>
#include "SocketOps.h"

namespace hm {
    namespace netd {
        class SocketListener {
        public:
            SocketListener();

            SocketListener(const std::string &socketName);

        protected:
            std::shared_ptr<SocketOps> socketOps;
        };
    }
}


#endif //NMCS_SOCKETLISTENER_H
