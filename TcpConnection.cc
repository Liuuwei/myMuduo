#include "TcpConnection.h"
#include "EventLoop.h"
#include "Channel.h"
#include "logger.h"
#include "Socket.h"

#include <sys/types.h>
#include <sys/types.h>


static EventLoop *CheckNotNull(EventLoop *loop) {
    if (loop) {
        return loop;
    }
    LOG_FATAL("%s:%s:%d subloop is nullptr", __FILE__, __FUNCTION__, __LINE__);
    return nullptr;
}

TcpConnection::TcpConnection(EventLoop *loop, const std::string nameArg, int sockfd, const InetAddress &localAddr, const InetAddress &peerAddr) : 
    loop_(CheckNotNull(loop)), 
    name_(nameArg), 
    socket_(new Socket(sockfd)), 
    channel_(new Channel(loop, sockfd)), 
    localAddr_(localAddr), 
    peerAddr_(peerAddr), 
    state_(kConnecting), 
    highWaterMark_(64 * 1024 * 64) {
    channel_->setReadCallback(std::bind(&TcpConnection::handleRead, this, std::placeholders::_1));
    channel_->setWriteCallback(std::bind(&TcpConnection::handleWrite, this));
    channel_->setCloseCallback(std::bind(&TcpConnection::handleClose, this));
    channel_->setErrorCallback(std::bind(&TcpConnection::handleError, this));
    LOG_INFO("TcpConnection::ctor[%s] at fd=%d\n", name_.c_str(), channel_->fd());
    socket_->setKeepAlive(true);
}

TcpConnection::~TcpConnection() {
    LOG_INFO("TcpConnection::dtor[%s] at fd=%d state=%d\n", name_.c_str(), channel_->fd(), (int)state_);
}

void TcpConnection::connectEstablised() {
    setState(kConnected);
    channel_->tie(shared_from_this());
    channel_->enableReading(); // * 向poller注册
    
    connectionCallback_(shared_from_this());
}

void TcpConnection::connectDestroyed() {
    if (state_ == kConnected) {
        setState(kDisconnected);
        channel_->disableAll(); // * 从poller中删除
        connectionCallback_(shared_from_this());
    }
    channel_->remove(); // * 从loop中删除
}

void TcpConnection::shutdown() {
    if (state_ == kConnected) {
        setState(kDisconnecting);
        loop_->runInLoop(std::bind(&TcpConnection::shutdownInLoop, this));
    }
}

void TcpConnection::shutdownInLoop() {
    if (channel_->isWriteing()) {
        channel_->disableWriteing();
    }
}

void TcpConnection::handleRead(Timestamp receiveTime) {
    int savedErrno = 0;
    ssize_t n = inputBuffer_.readFd(channel_->fd(), &savedErrno);
    if (n > 0) {
        messageCallback_(shared_from_this(), &inputBuffer_, receiveTime);
    } else if (n == 0) {
        handleClose();
    } else {
        errno = savedErrno;
        LOG_ERROR("TcpConnection handleRead error: %d\n", errno);
        handleError();
    }
}

void TcpConnection::handleWrite() {
    if (channel_->isWriteing()) {
        int savedErrno = 0;
        ssize_t n = outputBuffer_.writeFd(channel_->fd(), &savedErrno);
        if (n > 0) {
            outputBuffer_.retrieve(n);
            if (outputBuffer_.readableBytes() == 0) {
                channel_->disableWriteing();
                if (writeCompleteCallback_) {
                    loop_->queueInLoop(std::bind(writeCompleteCallback_, shared_from_this()));
                }
                if (state_ == kDisconnecting) { // * 发送过程中某处调用了shutdown，将state_置为kDisconnecting，等待此时写完再调用
                    shutdownInLoop();
                }
            }
        } else {
            LOG_ERROR("TcpConnetion::handleWrite\n");
        }
    } else {
        LOG_ERROR("TcpConnection fd=%d is down, no more writing\n", channel_->fd());
    }
}

void TcpConnection::handleClose() {
    LOG_INFO("fd=%d state=%d\n", channel_->fd(), (int)state_);
    setState(kDisconnected);
    channel_->disableAll();
    TcpConnectionPtr guardThis(shared_from_this());
    connectionCallback_(guardThis);
    closeCallback_(guardThis);
}

void TcpConnection::handleError() {
    int optval;
    socklen_t optlen;
    int err = ::getsockopt(channel_->fd(), SOL_SOCKET, SO_ERROR, &optval, &optlen);
    if (err < 0) {
        err = errno;
    } else {
        err = optval;
    }
    LOG_ERROR("TcpConnection::handleError name: %s -SO_ERROR: %d\n", name_.c_str(), err);
}

void TcpConnection::send(const std::string &buf) {
    if (state_ == kConnected) {
        if (loop_->isInLoopThread()) {
            sendInLoop(buf.c_str(), buf.size());
        } else {
            loop_->runInLoop(std::bind(&TcpConnection::sendInLoop, this, buf.c_str(), buf.size()));
        }
    }
}

void TcpConnection::sendInLoop(const void *data, int len) {
    ssize_t nwrote = 0;
    ssize_t remaining = len;
    bool faultError = false;
    if (state_ == kDisconnected) { // * 之前调用过shutdown
        LOG_ERROR("TcpConnection::sendInLoop fail connection is kDisconnected\n");
    } else {
        if (!channel_->isWriteing() && outputBuffer_.readableBytes() == 0) { // * 第一次开始write数据，并且发送缓冲区中没有数据
            nwrote = ::write(channel_->fd(), data, len);
            if (nwrote > 0) {
                remaining -= nwrote;
                if (remaining == 0 && writeCompleteCallback_) {
                    loop_->queueInLoop(std::bind(writeCompleteCallback_, shared_from_this()));
                }
            } else {
                nwrote = 0;
                if (errno != EWOULDBLOCK) {
                    LOG_ERROR("TcpConnection::sendInLoop\n");
                    if (errno == EPIPE || errno == ECONNRESET) {
                        faultError =true;
                    }
                }
            }
        }
    }

    if (!faultError && remaining > 0) { // * 当前一次操作没有发送完，剩余数据保存到发生缓冲区，注册EPOLLOUT事件
        size_t oldLen = outputBuffer_.readableBytes();
        if (oldLen + remaining >= highWaterMark_ && oldLen < highWaterMark_ && highWaterMarkCallback_) {
            loop_->queueInLoop(std::bind(highWaterMarkCallback_, shared_from_this(), oldLen + remaining));
        }
        outputBuffer_.append((char *)data + nwrote, remaining);
        if (!channel_->isWriteing()) {
            channel_->enableWriteing();
        }
    }
}