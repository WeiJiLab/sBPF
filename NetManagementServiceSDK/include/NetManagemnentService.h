//
// Created by XingfengYang on 2020/5/13.
//

#ifndef HM_NET_NETMANAGEMNENTSERVICE_H
#define HM_NET_NETMANAGEMNENTSERVICE_H

namespace hm {
    namespace netd {
        class NetManagemnentService {
        public:
            ~NetManagemnentService() noexcept;

            NetManagemnentService(const NetManagemnentService &) = delete;

            NetManagemnentService(NetManagemnentService &&) noexcept;

            NetManagemnentService &operator=(const NetManagemnentService &) = delete;

            NetManagemnentService &operator=(NetManagemnentService &&) noexcept;

        public:
            NetManagemnentService();
        };
    }
}


#endif //HM_NET_NETMANAGEMNENTSERVICE_H
