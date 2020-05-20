//
// Created by XingfengYang on 2020/5/12.
//

#include "../../include/listener/CommandListener.h"
#include "../../include/event/CommandNetlinkEvent.h"

hm::netd::CommandListener::~CommandListener() noexcept = default;

hm::netd::CommandListener::CommandListener(hm::netd::CommandListener &&) noexcept = default;

hm::netd::CommandListener &hm::netd::CommandListener::operator=(hm::netd::CommandListener &&) noexcept = default;

hm::netd::CommandListener::CommandListener() {

}

int hm::netd::CommandListener::StartListener() const {

    const std::shared_ptr<hm::netd::NetlinkListener> &commandNetlinkListener = this->netlinkManager->GetNetlinkListener("command");

    std::shared_ptr<CommandNetlinkEvent> commandNetlinkEvent = std::make_shared<CommandNetlinkEvent>();

    commandNetlinkListener->SetNetlinkEvent(commandNetlinkEvent);

    return 1;
}
