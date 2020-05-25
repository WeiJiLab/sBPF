#ifndef _NMCS_HTTP_SERVER_SOCKETOPS_
#define _NMCS_HTTP_SERVER_SOCKETOPS_

#include <memory>
#include <functional>
#include <string>
#include <netinet/in.h>

namespace hm {
    namespace netd {
        struct HttpServerConfigguration {
            struct SocketConfiguration {
                unsigned int port = 8899;
            } socketConfiguration;
        };

        class HttpSocketOps {
        public:
            ~HttpSocketOps() noexcept;

            HttpSocketOps(const HttpSocketOps &) = delete;

            HttpSocketOps(HttpSocketOps &&) noexcept;

            HttpSocketOps &operator=(const HttpSocketOps &) = delete;

            HttpSocketOps &operator=(HttpSocketOps &&) noexcept;

        public:
            HttpSocketOps();

            bool Configure(const HttpServerConfigguration::SocketConfiguration &configuration);

            int SetUp();

            int Bind();

            int Listen();

            using SocketAcceptEventHandler = std::function<void(char *buffer, int fdc)>;

            int Accept(SocketAcceptEventHandler socketAcceptEventHandler);

            void SetSocketAcceptEventHandler(SocketAcceptEventHandler socketAcceptEventHandler);

        private:
            int fd = 0;

            struct sockaddr_in addr{};

            HttpServerConfigguration::SocketConfiguration configuration;

            SocketAcceptEventHandler socketAcceptEventHandler;
        };
    } // namespace netd
} // namespace hm

#endif // _NMCS_HTTP_SERVER_SOCKETOPS_
