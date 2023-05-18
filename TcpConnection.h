#pragma once

#include "noncopyable.h"
#include "InetAddress.h"
#include "Callbacks.h"
#include "Timestamp.h"
#include "Buffer.h"

#include <memory>
#include <string>
#include <atomic>

class Socket;
class Channel;
class EventLoop;
class InetAddress;

/**
 * * TcpServer通过Acceptor连接新用户，连接完成之后，将新客户端打包为TcpConnection
 * * TcpConnection设置Channel的回调
*/
class TcpConnection : noncopyable, public std::enable_shared_from_this<TcpConnection> {
    public:
        TcpConnection(EventLoop *loop, const std::string nameArg, int sockfd, const InetAddress &localAddr, const InetAddress &peerAddr);
        ~TcpConnection();

        EventLoop* getLoop() const { return loop_; }
        const std::string name() const { return name_; }
        const InetAddress localAddress() const { return localAddr_; }
        const InetAddress peerAddress() const { return peerAddr_; }

        bool connected() const { return state_ == kConnected; }

        void send(const std::string &buf);
        void sendInLoop(const void *message, int len);

        void shutdown();
        void shutdownInLoop();

        void setConnectionCallback(const ConnectionCallback &cb) { connectionCallback_ = cb; }
        void setMessageCallback(const MessageCallback &cb) { messageCallback_ = cb; }
        void setWriteCompleteCallback(const WriteCompleteCallback &cb) { writeCompleteCallback_ = cb; }
        void setCloseCallback(const CloseCallback &cb) { closeCallback_ = cb; }
        void setHighWaterMarkCallback(const HighWaterMarkCallback &cb) { highWaterMarkCallback_ = cb; }

        void connectEstablised();
        void connectDestroyed();

        void handleRead(Timestamp receiveTime);
        void handleWrite();
        void handleClose();
        void handleError();

    private:
        enum StateE { kDisconnected, kConnecting, kConnected, kDisconnecting };
        void setState(StateE state) { state_ = state; }
        EventLoop *loop_; // * subloop, manage client communication
        const std::string name_;
        std::atomic<int> state_;
        std::unique_ptr<Socket> socket_;
        std::unique_ptr<Channel> channel_;

        const InetAddress localAddr_;
        const InetAddress peerAddr_;

        ConnectionCallback connectionCallback_;
        MessageCallback messageCallback_;
        WriteCompleteCallback writeCompleteCallback_;
        CloseCallback closeCallback_;
        HighWaterMarkCallback highWaterMarkCallback_;

        size_t highWaterMark_;
        
        Buffer inputBuffer_;
        Buffer outputBuffer_;

};