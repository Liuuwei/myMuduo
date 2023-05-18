#pragma once

#include "noncopyable.h"
#include "EventLoopThreadPool.h"
#include "InetAddress.h"
#include "EventLoop.h"
#include "Callbacks.h"
#include "Acceptor.h"
#include "Buffer.h"

#include <unordered_map>
#include <functional>
#include <memory>
#include <string>
#include <atomic>

class TcpServer : noncopyable{
    public:
        using ThreadInitCallback = std::function<void(EventLoop *)>;

        enum Option{
            kNoRequstPort, 
            kRequstPort,
        };

        TcpServer(EventLoop *loop, const InetAddress &addr, const std::string nameArg, Option option = kNoRequstPort);
        ~TcpServer();

        void setThreadInitCallback(const ThreadInitCallback &cb) { threadInitCallback_ = cb; }
        void setConectionCallbck(const ConnectionCallback &cb) { connectionCallback_ = cb; }
        void setMessageCallback(const MessageCallback &cb) { messageCallback_ = cb; }
        void setWriteCompelteCallback(const WriteCompleteCallback &cb) { writeCompleteCallback_ = cb; }

        void setThreadNum(int numThreads); // * set subloop number

        void start();
    private:
        void newConnection(int sockfd, const InetAddress &peerAddr); // * choice a subloop, sent the new client fd
        void removeConnection(const TcpConnectionPtr &conn);
        void removeConnectionInLoop(const TcpConnectionPtr &conn);

        using ConnectionMap = std::unordered_map<std::string, TcpConnectionPtr>;

        EventLoop *loop_; // * baseloop
        const std::string ipPort_;
        const std::string name_;
        std::unique_ptr<Acceptor> acceptor_; // * run in mainloop, listen new client connection
        std::shared_ptr<EventLoopThreadPool> threadPool_;
        ConnectionCallback connectionCallback_;
        MessageCallback messageCallback_;
        WriteCompleteCallback writeCompleteCallback_;
        ThreadInitCallback threadInitCallback_;
        //std::atomic_int started_;
        int started_ = 0;
        int nextConnId_;
        ConnectionMap connections_;
};