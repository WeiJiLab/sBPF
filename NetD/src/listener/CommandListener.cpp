//
// Created by XingfengYang on 2020/5/12.
//

#include "../../include/listener/CommandListener.h"

hm::netd::CommandListener::~CommandListener() noexcept = default;

hm::netd::CommandListener::CommandListener(hm::netd::CommandListener &&) noexcept = default;

hm::netd::CommandListener &hm::netd::CommandListener::operator=(hm::netd::CommandListener &&) noexcept = default;

hm::netd::CommandListener::CommandListener() {

}

int hm::netd::CommandListener::StartListener() const {
    return 1;
}
