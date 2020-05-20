//
// Created by XingfengYang on 2020/5/15.
//

#ifndef NMCS_NETLINKHANDLER_H
#define NMCS_NETLINKHANDLER_H

namespace hm {
    namespace netd {
        class NetlinkHandler {
        public:
            ~NetlinkHandler() noexcept;

            NetlinkHandler(const NetlinkHandler &) = delete;

            NetlinkHandler(NetlinkHandler &&) noexcept;

            NetlinkHandler &operator=(const NetlinkHandler &) = delete;

            NetlinkHandler &operator=(NetlinkHandler &&) noexcept;

        public:
            NetlinkHandler();
        };
    }
}

#endif //NMCS_NETLINKHANDLER_H
