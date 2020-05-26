//
// Created by XingfengYang on 2020/5/12.
//

#include "../../include/listener/CommandListener.h"
#include "../../include/event/RouteNetlinkEvent.h"
#include "../../include/log/Log.h"

hm::netd::CommandListener::~CommandListener() noexcept = default;

hm::netd::CommandListener::CommandListener(hm::netd::CommandListener &&) noexcept = default;

hm::netd::CommandListener &hm::netd::CommandListener::operator=(hm::netd::CommandListener &&) noexcept = default;

hm::netd::CommandListener::CommandListener() : commandListenerConfiguration({}) {

}


void hm::netd::CommandListener::SetConfiguration(CommandListenerConfiguration commandListenerConfiguration) {
    this->commandListenerConfiguration = commandListenerConfiguration;
}

int hm::netd::CommandListener::StartListener() const {

}
