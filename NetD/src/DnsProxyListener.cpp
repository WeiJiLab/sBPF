//
// Created by XingfengYang on 2020/5/13.
//

#include "../include/listener/DnsProxyListener.h"

hm::netd::DnsProxyListener::~DnsProxyListener() noexcept = default;

hm::netd::DnsProxyListener::DnsProxyListener(hm::netd::DnsProxyListener &&) noexcept = default;

hm::netd::DnsProxyListener &hm::netd::DnsProxyListener::operator=(hm::netd::DnsProxyListener &&) noexcept = default;

hm::netd::DnsProxyListener::DnsProxyListener() {

}

int hm::netd::DnsProxyListener::StartListener() const {
    return 1;
}
