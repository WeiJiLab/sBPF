#include <fcntl.h>
#include "../../include/http_server/HttpSocketOps.h"
#include "../../include/log/Log.h"
#include <stdio.h>


hm::netd::HttpSocketOps::~HttpSocketOps() noexcept = default;

hm::netd::HttpSocketOps::HttpSocketOps(hm::netd::HttpSocketOps &&) noexcept = default;

hm::netd::HttpSocketOps &hm::netd::HttpSocketOps::operator=(hm::netd::HttpSocketOps &&) noexcept = default;

hm::netd::HttpSocketOps::HttpSocketOps() {
}

bool hm::netd::HttpSocketOps::Configure(const hm::netd::HttpServerConfigguration::SocketConfiguration &configuration) {
    this->configuration = configuration;
}

int hm::netd::HttpSocketOps::SetUp() {
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(configuration.port);
    addr.sin_addr.s_addr = INADDR_ANY;
    if ((fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        LogError("[Socket] Unable to Open the Socket\n");
        exit(0);
    }
}

int hm::netd::HttpSocketOps::Bind() {
    if (bind(fd, (struct sockaddr *) (&addr), sizeof(addr)) != 0) {
        LogError("[Socket] Unable to bind the Socket\n");
        exit(0);
    }
}

int hm::netd::HttpSocketOps::Listen() {
    if (listen(fd, 50) == -1) {
        LogError("[Socket] Unable to listen the Socket\n");
        exit(0);
    }
}

using SocketAcceptEventHandler = std::function<void(char *buffer, int fdc)>;

void hm::netd::HttpSocketOps::SetSocketAcceptEventHandler(SocketAcceptEventHandler socketAcceptEventHandler) {
    this->socketAcceptEventHandler = socketAcceptEventHandler;
}
int hm::netd::HttpSocketOps::Accept(SocketAcceptEventHandler socketAcceptEventHandler) {

}


