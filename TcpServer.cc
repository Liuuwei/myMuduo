#include "TcpServer.h"
#include "logger.h"

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

// void TcpServer::newConnection(int sockfd, const InetAddress &peerAddr); // * choice a subloop, sent the new client fd
// void TcpServer::removeConnection(const TcpConnectionPtr &conn);
// void TcpServer::removeConnectionInLoop(const TcpConnectionPtr &conn);

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