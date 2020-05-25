//
// Created by XingfengYang on 2020/5/12.
//

#ifndef NMCS_COMMANDLISTENER_H
#define NMCS_COMMANDLISTENER_H

#include <memory>
#include "../netlink/NetlinkManager.h"
#include "AbstractServiceListener.h"


namespace hm {
    namespace netd {
        struct CommandListenerConfiguration {
            NetDConfiguration netdConfiguration;
        };


        class CommandListener : public AbstractServiceListener {
        public:
            ~CommandListener() noexcept;

            CommandListener(const CommandListener &) = delete;

            CommandListener(CommandListener &&) noexcept;

            CommandListener &operator=(const CommandListener &) = delete;

            CommandListener &operator=(CommandListener &&) noexcept;

        public:
            CommandListener();

            void SetConfiguration(CommandListenerConfiguration commandListenerConfiguration);

            int StartListener() const;

        private:
            CommandListenerConfiguration commandListenerConfiguration;
        };
    };
};


#endif //NMCS_COMMANDLISTENER_H
