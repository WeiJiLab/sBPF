#ifndef _NMCS_HTTP_SERVER_H
#define _NMCS_HTTP_SERVER_H

#include <memory>
#include <map>
#include <string>
#include <functional>
#include <thread>

#include "HttpSocketOps.h"
#include "HttpMessage.h"

namespace hm {
    namespace netd {
        struct Route {
            std::string uri;
            HttpMethod method;

            bool operator==(const Route &rhs) const;

            bool operator!=(const Route &rhs) const;

            bool operator<(const Route &rhs) const;

            bool operator>(const Route &rhs) const;

            bool operator<=(const Route &rhs) const;

            bool operator>=(const Route &rhs) const;
        };

        struct HandlerResponse {
            HttpResponseStatus responseStatus;
            std::string body;
        };

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
            bool Configure(const HttpServerConfigguration &configuration);

            void ReceiveMessage(hm::netd::HttpRequest request,
                                unsigned int senderInstanceNumber);

            void ServerWorker();

        public:
            void Start();

            void SetRunning() { this->isRunning = true; }

            void AddRoute(Route route, std::function<HandlerResponse(HttpRequest)> handler);

        private:
            bool isRunning = false;
            std::shared_ptr<HttpSocketOps> socketOps;
            std::thread worker;
            HttpServerConfigguration configguration;
            std::map<Route, std::function<HandlerResponse(HttpRequest)>> router;

        private:
            void Handler(char *buffer, int fdc);
        };
    } // namespace netd
} // namespace hm

#endif
