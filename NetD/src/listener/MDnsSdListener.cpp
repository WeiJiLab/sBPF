//
// Created by XingfengYang on 2020/5/13.
//

#include "../../include/listener/MDnsSdListener.h"

hm::netd::MDnsSdListener::~MDnsSdListener() noexcept = default;

hm::netd::MDnsSdListener::MDnsSdListener(hm::netd::MDnsSdListener &&) noexcept = default;

hm::netd::MDnsSdListener &hm::netd::MDnsSdListener::operator=(hm::netd::MDnsSdListener &&) noexcept = default;

hm::netd::MDnsSdListener::MDnsSdListener() {

}

int hm::netd::MDnsSdListener::StartListener() const {
    return 1;
}
