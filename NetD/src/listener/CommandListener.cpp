//
// Created by XingfengYang on 2020/5/12.
//

#include "../../include/listener/CommandListener.h"
#include "../../include/event/CommandNetlinkEvent.h"
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
    if (this->netlinkManager == nullptr) {
        LogError("Netlink manager for CommandListener not assigned.");
    }

    std::shared_ptr<hm::netd::NetlinkListener> commandNetlinkListener = this->netlinkManager->GetNetlinkListener("command");

    if (commandNetlinkListener == nullptr) {
        LogError("Command Netlink Listener not found!");
        return 1;
    }

    std::shared_ptr<CommandNetlinkEvent> commandNetlinkEvent = std::make_shared<CommandNetlinkEvent>();
    commandNetlinkEvent.SetNetworkContext(networkContext);

    commandNetlinkListener->SetNetlinkEvent(commandNetlinkEvent);

    commandNetlinkListener->Config(this->commandListenerConfiguration.netdConfiguration);

    commandNetlinkListener->StartListen();
}
