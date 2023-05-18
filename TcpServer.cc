#include "TcpServer.h"
#include "TcpConnection.h"
#include "logger.h"

#include <netinet/in.h>
#include <string.h>

#include <functional>

static EventLoop *CheckNotNull(EventLoop *loop) {
    if (loop) {
        return loop;
    }
    LOG_FATAL("%s:%s:%d mainloop is nullptr", __FILE__, __FUNCTION__, __LINE__);
    return nullptr;
}

TcpServer::TcpServer(EventLoop *loop, const InetAddress &listenAddr, const std::string nameArg, Option option) :
    loop_(CheckNotNull(loop)), 
    ipPort_(listenAddr.toIpPort()), 
    name_(nameArg), 
    acceptor_(new Acceptor(loop_, listenAddr, option == kRequstPort)), 
    threadPool_(new EventLoopThreadPool(loop_, name_)), 
    connectionCallback_(), 
    messageCallback_(), 
    nextConnId_(1) {
    // * execute when a new client connection
    acceptor_->setNewConnectionCallback(std::bind(&TcpServer::newConnection, this, std::placeholders::_1, std::placeholders::_2));
}

TcpServer::~TcpServer() {
    for (auto &item : connections_) {
        TcpConnectionPtr conn(item.second);
        item.second.reset();
        conn->getLoop()->runInLoop(std::bind(&TcpConnection::connectDestroyed, conn));
    }
}

void TcpServer::setThreadNum(int numThreads) {
    threadPool_->setThreadNum(numThreads);
}

void TcpServer::start() {
    if (started_ ++ == 0) { // * prevent start many times
        threadPool_->start(threadInitCallback_);
        loop_->runInLoop(std::bind(&Acceptor::listen, acceptor_.get()));
        loop_->loop();
    }
}

void TcpServer::newConnection(int sockfd, const InetAddress &peerAddr) {
    EventLoop *ioLoop = threadPool_->getNextLoop();
    char buf[64] = {0};
    snprintf(buf, sizeof(buf), "-%s#%d", ipPort_.c_str(), nextConnId_ ++ );
    std::string connName = name_ + buf;

    LOG_INFO("TcpServer::newConnection [%s] - new connection [%s] from %s\n", name_.c_str(), connName.c_str(), peerAddr.toIpPort().c_str());

    sockaddr_in local;
    ::bzero(&local, sizeof(local));
    socklen_t len = sizeof(local);
    if (::getsockname(sockfd, (sockaddr *)&local, &len) < 0) {
        LOG_ERROR("%s:%s:%d\n", __FILE__, __FUNCTION__, __LINE__);
    }
    InetAddress localAddr(local);

    TcpConnectionPtr conn(new TcpConnection(ioLoop, connName, sockfd, localAddr, peerAddr));

    connections_[connName] = conn;
    conn->setConnectionCallback(connectionCallback_);
    conn->setMessageCallback(messageCallback_);
    conn->setWriteCompleteCallback(writeCompleteCallback_);
    conn->setCloseCallback(std::bind(&TcpServer::removeConnection, this, std::placeholders::_1));
    ioLoop->runInLoop(std::bind(&TcpConnection::connectEstablised, conn));
}

void TcpServer::removeConnection(const TcpConnectionPtr &conn) {
    loop_->runInLoop(std::bind(&TcpServer::removeConnectionInLoop, this, conn));
}

void TcpServer::removeConnectionInLoop(const TcpConnectionPtr &conn) {
    LOG_INFO("TcpServer::removeConnectionInLoop [%s] - connection %s\n", name_.c_str(), conn->name().c_str());
    connections_.erase(conn->name());
    EventLoop *ioLoop = conn->getLoop();
    ioLoop->queueInLoop(std::bind(&TcpConnection::connectDestroyed, conn));
}