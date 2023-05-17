#pragma once

#include "noncopyable.h"
#include "Channel.h"
#include "Socket.h"

class EventLoop;
class InetAddress;

class Acceptor : noncopyable {
    public:
        using newConnectionCallback = std::function<void(int sockfd, const InetAddress &)>; 

        Acceptor(EventLoop *loop, const InetAddress &listenAddr, bool reusePort);
        ~Acceptor();

        void setNewConnectionCallback(const newConnectionCallback &cb) { newConnectionCallback_ = cb; }
        
        bool listenning() const { return listenning_; }
        void listen();
    private:
        void handleRead();
        EventLoop *loop_; // * baseloop
        Socket acceptSocket_;
        Channel acceptChannel_;       
        newConnectionCallback newConnectionCallback_; // * Round Robin to find a subLoop to communication with a new client / set by TcpServer
        bool listenning_;
};