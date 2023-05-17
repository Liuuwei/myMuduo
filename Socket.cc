#include "Socket.h"
#include "logger.h"
#include "InetAddress.h"

#include <unistd.h>
#include <string.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/types.h>

Socket::~Socket() {
    ::close(sockfd_);
}

void Socket::bindAddress(const InetAddress &localAddr) {
    if (::bind(sockfd_, (sockaddr *)localAddr.getSockaddr(), sizeof(sockaddr_in) < 0)) {
        LOG_FATAL("bind sockfd: %d fail\n", sockfd_);
    }
}
void Socket::listen() {
    if (::listen(sockfd_, 1024) < 0) {
        LOG_FATAL("listen sockfd: %d fail\n", sockfd_);
    }
}

int Socket::accept(InetAddress &peeraddr){
    sockaddr_in addr;
    socklen_t len;
    bzero(&addr, sizeof(addr));
    int connfd;
    if ( (connfd = ::accept(sockfd_, (sockaddr *)&addr, &len)) >= 0) {
        peeraddr.setSockAddr(addr);
    }
    return connfd;
}

void Socket::shutdownWrite() {
    if (::shutdown(sockfd_, SHUT_WR) < 0) {
        LOG_ERROR("shutdownWrite fd: %d error: %d\n", sockfd_, errno);
    }
}

void Socket::setTcpNoDelay(bool on) {
    int optVal = on ? 1 : 0;
    ::setsockopt(sockfd_, IPPROTO_TCP, TCP_NODELAY, &optVal, sizeof(optVal));
}

void Socket::setReuseAddr(bool on) {
    int optVal = on ? 1 : 0;
    ::setsockopt(sockfd_, SOCK_STREAM, SO_REUSEADDR, &optVal, sizeof(optVal));
}

void Socket::setReusePort(bool on) {
    int optVal = on ? 1 : 0;
    ::setsockopt(sockfd_, SOCK_STREAM, SO_REUSEPORT, &optVal, sizeof(optVal));
}

void Socket::setKeepAlive(bool on) {
    int optVal = on ? 1 : 0;
    ::setsockopt(sockfd_, SOCK_STREAM, SO_KEEPALIVE, &optVal, sizeof(optVal));
}