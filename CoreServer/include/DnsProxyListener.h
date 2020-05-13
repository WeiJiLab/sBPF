//
// Created by XingfengYang on 2020/5/13.
//

#ifndef HM_NET_DNSPROXYLISTENER_H
#define HM_NET_DNSPROXYLISTENER_H

#include "AbstractServiceListener.h"

namespace hm {
    namespace netd {
        class DnsProxyListener : public AbstractServiceListener {
        public:
            ~DnsProxyListener() noexcept;

            DnsProxyListener(const DnsProxyListener &) = delete;

            DnsProxyListener(DnsProxyListener &&) noexcept;

            DnsProxyListener &operator=(const DnsProxyListener &) = delete;

            DnsProxyListener &operator=(DnsProxyListener &&) noexcept;

        public:
            DnsProxyListener();


            int StartListener() const;
        };
    }
}


#endif //HM_NET_DNSPROXYLISTENER_H
