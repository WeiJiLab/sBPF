//
// Created by XingfengYang on 2020/5/15.
//

#ifndef NMCS_DAEMONCONNECTOR_H
#define NMCS_DAEMONCONNECTOR_H


namespace hm {
    namespace netd {
        class DaemonConnector {
        public:
            ~DaemonConnector() noexcept;

            DaemonConnector(const DaemonConnector &) = delete;

            DaemonConnector(DaemonConnector &&) noexcept;

            DaemonConnector &operator=(const DaemonConnector &) = delete;

            DaemonConnector &operator=(DaemonConnector &&) noexcept;

        public:
            DaemonConnector();
        };
    }
}


#endif //NMCS_DAEMONCONNECTOR_H
