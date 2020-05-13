
//
// Created by XingfengYang on 2020/5/13.
//

#ifndef HM_NET_MDNSSDLISTENER_H
#define HM_NET_MDNSSDLISTENER_H

#include "AbstractServiceListener.h"

namespace hm {
    namespace netd {
        class MDnsSdListener : public AbstractServiceListener {
        public:
            ~MDnsSdListener() noexcept;

            MDnsSdListener(const MDnsSdListener &) = delete;

            MDnsSdListener(MDnsSdListener &&) noexcept;

            MDnsSdListener &operator=(const MDnsSdListener &) = delete;

            MDnsSdListener &operator=(MDnsSdListener &&) noexcept;

        public:
            MDnsSdListener();

            int StartListener() const;
        };
    }
}


#endif //HM_NET_MDNSSDLISTENER_H
