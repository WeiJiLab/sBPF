#ifndef _NMCS_HTTP_SERVER_H
#define _NMCS_HTTP_SERVER_H

#include <memory>
#include <map>
#include <functional>

#include "HttpSocketOps.h"
#include "HttpMessage.h"

namespace hm {
    namespace netd {
        struct Route {
            std::string uri;
            HttpMethod method;

            bool operator<(const Route &rhs) const;

            bool operator>(const Route &rhs) const;

            bool operator<=(const Route &rhs) const;

            bool operator>=(const Route &rhs) const;
        };

        struct HandlerResponse {
            HttpResponseStatus responseStatus;
            std::string body;
        };

        using SendMessageDelegate = std::function<void(std::shared_ptr<HttpMessage> message, unsigned int receivedFd)>;

        class HttpServer {
        public:
            ~HttpServer() noexcept;

            HttpServer(const HttpServer &) = delete;

            HttpServer(HttpServer &&) noexcept;

            HttpServer &operator=(const HttpServer &) = delete;

            HttpServer &operator=(HttpServer &&) noexcept;

        public:
            HttpServer();

        public:
            bool Configure(const SocketConfiguration &configuration);

            void SetSendMessageDelegate(SendMessageDelegate sendMessageDelegate);

            void ReceiveMessage(std::shared_ptr<HttpMessage> message,
                                unsigned int senderInstanceNumber);

        public:
            void Start();

            void SetRunning() { this->isRunning = true; }

            void AddRoute(Route route, std::function<HandlerResponse(HttpRequest)> handler);

        private:
            bool isRunning = false;
            std::shared_ptr<HttpSocketOps> socketOps;
        };
    } // namespace netd
} // namespace hm

#endif