#include <fcntl.h>
#include "../../include/http_server/HttpSocketOps.h"
#include "../../include/log/Log.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

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
        LogError("[Socket] Unable to Open the Socket");
        exit(0);
    }

    epollFd = epoll_create(EPOLL_SIZE);
    epEvents = (struct epoll_event *) malloc(sizeof(struct epoll_event) * EPOLL_SIZE);

    event.events = EPOLLIN;
    event.data.fd = this->fd;
    epoll_ctl(epollFd, EPOLL_CTL_ADD, fd, &event);
}

int hm::netd::HttpSocketOps::Bind() {
    if (bind(fd, (struct sockaddr *) (&addr), sizeof(addr)) != 0) {
        LogError("[Socket] Unable to bind the Socket");
        exit(0);
    }
}

int hm::netd::HttpSocketOps::Listen() {
    if (listen(fd, 50) == -1) {
        LogError("[Socket] Unable to listen the Socket");
        exit(0);
    }
}

using SocketAcceptEventHandler = std::function<void(char *buffer, int fdc)>;

void hm::netd::HttpSocketOps::SetSocketAcceptEventHandler(SocketAcceptEventHandler socketAcceptEventHandler) {
    this->socketAcceptEventHandler = socketAcceptEventHandler;
}


#define BUF_SIZE 1024

int hm::netd::HttpSocketOps::Accept(SocketAcceptEventHandler socketAcceptEventHandler) {
    socklen_t adr_sz;
    struct sockaddr_in clnt_adr;
    int clnt_sock;
    int str_len;
    char buf[BUF_SIZE];
    while (1) {
        eventCnt = epoll_wait(epollFd, epEvents, EPOLL_SIZE, -1);
        if (eventCnt == -1) {
            LogError("[HttpServer]  epoll_wait() error");
            break;
        }

        for (int i = 0; i < eventCnt; i++) {
            if (epEvents[i].data.fd == fd) {
                adr_sz = sizeof(clnt_adr);
                clnt_sock =
                        accept(fd, (struct sockaddr *) &clnt_adr, &adr_sz);
                event.events = EPOLLIN;
                event.data.fd = clnt_sock;
                epoll_ctl(epollFd, EPOLL_CTL_ADD, clnt_sock, &event);
                LogInfo("[HttpServer] connected client: %d \n", clnt_sock);
            } else {
                str_len = read(epEvents[i].data.fd, buf, BUF_SIZE);
                if (str_len == 0)    // close request!
                {
                    epoll_ctl(epollFd, EPOLL_CTL_DEL, epEvents[i].data.fd, NULL);
                    close(epEvents[i].data.fd);
                    LogInfo("[HttpServer]  closed client: %d \n", epEvents[i].data.fd);
                } else {
                    write(epEvents[i].data.fd, buf, str_len);    // echo!
                    socketAcceptEventHandler(buf, clnt_sock);
                }

            }
        }
    }
    close(fd);
    close(epollFd);
    return 0;
}


