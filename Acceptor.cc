#include "Acceptor.h"
#include "InetAddress.h"
#include "logger.h"

#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

static int createNonblocking() {
    int fd = ::socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK | SOCK_CLOEXEC, 0);
    if (fd < 0) {
        LOG_FATAL("%s:%s:%d listen socket create error: %d\n", __FILE__, __FUNCTION__, __LINE__, errno);
    }
    return fd;
}

Acceptor::Acceptor(EventLoop *loop, const InetAddress &listenAddr, bool reusePort) :
    loop_(loop), 
    acceptSocket_(createNonblocking()), 
    acceptChannel_(loop, acceptSocket_.fd()), 
    listenning_(false) {
    acceptSocket_.setReuseAddr(true);
    acceptSocket_.setReusePort(true);
    acceptSocket_.bindAddress(listenAddr);
    acceptChannel_.setReadCallback(std::bind(&Acceptor::handleRead, this));
}

Acceptor::~Acceptor() {
    acceptChannel_.disableAll();
    acceptChannel_.remove();
}

void Acceptor::listen() {
    printf("listen\n");
    listenning_ = true;
    acceptSocket_.listen();
    acceptChannel_.enableReading(); // * 调用之后loop会调用poller去更新channel，并且如果没添加该fd的监听事件则会添加
}

void Acceptor::handleRead() {
    printf("handlread\n");
    InetAddress peerAddr;
    int connfd = acceptSocket_.accept(peerAddr);
    if (connfd > 0) {
        if (newConnectionCallback_) {
            printf("new\n");
            newConnectionCallback_(connfd, peerAddr);
        }
    } else {
        LOG_ERROR("%s:%s:%d accept error: %d\n", __FILE__, __FUNCTION__, __LINE__, errno);
        ::close(connfd);
    }
}