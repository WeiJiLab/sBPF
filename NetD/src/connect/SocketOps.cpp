//
// Created by XingfengYang on 2020/5/12.
//

#include "../../include/connect/SocketOps.h"
#include "../../include/log/Log.h"


hm::netd::SocketOps::SocketOps() {

}

hm::netd::SocketOps::SocketOps(const std::string &sockName) : sockName(sockName), seq(0) {

}

int hm::netd::SocketOps::Config(hm::netd::NetDConfiguration netDConfiguration) {
    this->netDConfiguration = netDConfiguration;
    return 0;
}

int hm::netd::SocketOps::CreateSock() {
    this->sockfd = socket(AF_NETLINK, SOCK_RAW, this->netDConfiguration.type);
    if (this->sockfd < 0) {
        LogError("Socket created failed for socket:'%s'", this->sockName.c_str())
        exit(0);
    }
    if (fcntl(this->sockfd, F_SETFL, O_NONBLOCK) < 0) {
        LogError("Socket created failed for socket:'%s',ubable to set socket flags", sockName.c_str());
        exit(0);
    }
    return this->sockfd;
}

int hm::netd::SocketOps::Bind() {
    int bindfd = bind(this->sockfd, (struct sockaddr *) &this->netDConfiguration.bindAddr, sizeof(this->netDConfiguration.bindAddr));
    if (bindfd < 0) {
        LogError("Socket bind failed for socket:'%s'", this->sockName.c_str())
        exit(0);
    }
    return bindfd;
}


ssize_t hm::netd::SocketOps::SendRequest(int family, int type, int sockfd) {
    if (sockfd < 0) {
        LogError("Socket '%s' is not active.", this->sockName.c_str());
        return -1;
    }


    struct nl_req_s {
        struct nlmsghdr hdr;
        struct rtgenmsg gen;
    };


    struct sockaddr_nl kernel;
    int s, end = 0, len;
    struct msghdr msg;
    struct nl_req_s req;
    struct iovec io;
    char buf[4096];

    //build kernel netlink address
    memset(&kernel, 0, sizeof(kernel));
    kernel.nl_family = AF_NETLINK;
    kernel.nl_groups = 0;

    //build netlink message
    memset(&req, 0, sizeof req);
    req.hdr.nlmsg_len = NLMSG_LENGTH(sizeof(struct rtgenmsg));
    req.hdr.nlmsg_type = type;
    req.hdr.nlmsg_flags = NLM_F_REQUEST | NLM_F_DUMP;
    req.hdr.nlmsg_seq = 1;
    req.hdr.nlmsg_pid = this->netDConfiguration.bindAddr.nl_pid;
    req.gen.rtgen_family = family;

    memset(&io, 0, sizeof(io));
    io.iov_base = &req;
    io.iov_len = req.hdr.nlmsg_len;

    memset(&msg, 0, sizeof(msg));
    msg.msg_iov = &io;
    msg.msg_iovlen = 1;
    msg.msg_name = &kernel;
    msg.msg_namelen = sizeof(kernel);

    //send the message
    if (sendmsg(this->sockfd, &msg, 0) < 0) {
        LogError("Socket '%s' send msg failed", this->sockName.c_str());
    }
}

int hm::netd::SocketOps::Receive(SocketAcceptEventHandler acceptEventHandler, int nlSockFd, void *arg) {
    char buffer[4096];

    struct iovec iov = {buffer, sizeof buffer};
    struct sockaddr_nl netlinkAddr;
    struct msghdr msg = {(void *) &netlinkAddr, sizeof netlinkAddr, &iov, 1, ((void *) 0), 0, 0};

    int messageStatus = recvmsg(sockfd, &msg, 0);
    if (messageStatus < 0) {
        LogWarnning("Socket '%s' receive message failed.", this->sockName.c_str());
        return 0;
    }

    if (netlinkAddr.nl_pid != 0) {
        LogWarnning("Ignore non kernel message from pid:%d", netlinkAddr.nl_pid);
        return 0;
    }

    if (messageStatus == 0) {
        LogError("Socket '%s' EOF.", this->sockName.c_str());
        return -1;
    }


    if (msg.msg_namelen != sizeof netlinkAddr) {
        LogError("Socket '%s' sender address length error.", this->sockName.c_str());
        return -1;
    }

    for (struct nlmsghdr *h = (struct nlmsghdr *) buffer; NLMSG_OK(h, messageStatus); h = NLMSG_NEXT(h, messageStatus)) {
        if (h->nlmsg_type == NLMSG_DONE) {
            return 0;
        }
        if (h->nlmsg_type == NLMSG_ERROR) {
            struct nlmsgerr *err = (struct nlmsgerr *) NLMSG_DATA(h);

            if (err->error == 0) {
                return 0;
            }

            if (h->nlmsg_len < NLMSG_LENGTH(sizeof(struct nlmsgerr))) {
                LogError("Socket '%s' error: message truncated", this->sockName.c_str());
                return -1;
            }

            LogError("Socket '%s' error: %s, type=%u, seq=%u, pid=%d",
                     this->sockName.c_str(),
                     strerror(-err->error),
                     err->msg.nlmsg_type,
                     err->msg.nlmsg_seq,
                     err->msg.nlmsg_pid);
            return -1;
        }

        if (nlSockFd != this->sockfd && h->nlmsg_pid == this->netDConfiguration.bindAddr.nl_pid) {
            return 0;
        }

        int error = acceptEventHandler(&netlinkAddr, h, arg);
        if (error < 0) {
            LogError("Socket '%s' handler function error", this->sockName.c_str());
            return 0;
        }
    }

    if (msg.msg_flags & MSG_TRUNC) {
        LogWarnning("Socket '%s' error: message truncated", this->sockName.c_str());
        return 0;
    }

    if (messageStatus) {
        LogError("Socket '%s' error: data remnant size :%d", this->sockName.c_str(), messageStatus);
        return -1;
    }

    return 0;
}



















