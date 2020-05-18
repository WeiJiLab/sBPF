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
        class CommandListener : public AbstractServiceListener {
            ~CommandListener() noexcept;

            CommandListener(const CommandListener &) = delete;

            CommandListener(CommandListener &&) noexcept;

            CommandListener &operator=(const CommandListener &) = delete;

            CommandListener &operator=(CommandListener &&) noexcept;

            virtual void SetNetlinkManager(std::shared_ptr<NetlinkManager> netlinkManager);

        public:
            CommandListener();


            int StartListener() const;


        private:
            std::shared_ptr<NetlinkManager> netlinkManager;
        };
    };
};


#endif //NMCS_COMMANDLISTENER_H
