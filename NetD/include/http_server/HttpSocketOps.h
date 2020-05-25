#ifndef _NMCS_HTTP_SERVER_SOCKETOPS_
#define _NMCS_HTTP_SERVER_SOCKETOPS_

#include <memory>
#include <functional>
#include <string>
#include <netinet/in.h>
#include <sys/epoll.h>

namespace hm {
    namespace netd {

#define EPOLL_SIZE 50

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
            int epollFd = 0;
            int eventCnt = 0;
            struct epoll_event *epEvents;
            struct epoll_event event{};

            struct sockaddr_in addr{};

            HttpServerConfigguration::SocketConfiguration configuration;

            SocketAcceptEventHandler socketAcceptEventHandler;
        };
    } // namespace netd
} // namespace hm

#endif // _NMCS_HTTP_SERVER_SOCKETOPS_
