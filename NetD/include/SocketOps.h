//
// Created by XingfengYang on 2020/5/12.
//

#ifndef NMCS_SOCKETOPS_H
#define NMCS_SOCKETOPS_H
#include <functional>

namespace hm {
    namespace netd {

        using SocketAcceptEventHandler = std::function<void(char *buffer, int fdc)>;

        class SocketOps {
            ~SocketOps() noexcept;

            SocketOps(const SocketOps &) = delete;

            SocketOps(SocketOps &&) noexcept;

            SocketOps &operator=(const SocketOps &) = delete;

            SocketOps &operator=(SocketOps &&) noexcept;

        public:
            SocketOps();

            int SetUp();

            int Bind();

            int Listen();

            int Accept(SocketAcceptEventHandler acceptEventHandler);

            void SetSocketAcceptEventHandler(SocketAcceptEventHandler acceptEventHandler);

            int Connect(int port);

            int Send(char *buf);

        };
    };
};


#endif //NMCS_SOCKETOPS_H
