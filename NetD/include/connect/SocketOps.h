//
// Created by XingfengYang on 2020/5/12.
//

#ifndef NMCS_SOCKETOPS_H
#define NMCS_SOCKETOPS_H

#include <functional>

namespace hm {
    namespace netd {

        using SocketAcceptEventHandler = std::function<void(char *buffer, int fdc)>;


        struct NetDConfiguration {

        };

        class SocketOps {
        public:
            SocketOps();

            int Config(NetDConfiguration netDConfiguration);

            int SetUp();

            int Bind();

            int Listen();

            virtual int Accept(SocketAcceptEventHandler acceptEventHandler) = 0;

            void SetSocketAcceptEventHandler(SocketAcceptEventHandler acceptEventHandler);

            int Connect(int port);

            virtual int Send(char *buf);

        private:
            SocketAcceptEventHandler socketAcceptEventHandler;
        };
    };
};


#endif //NMCS_SOCKETOPS_H
