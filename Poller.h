#pragma once

#include "noncopyable.h"
#include "Timestamp.h"
#include "Channel.h"

#include <unordered_map>
#include <vector>

#include <string.h>
#include <errno.h>

class EventLoop;

// * muduo中多路事件分发器，核心IO复用模块
class Poller : noncopyable {
    public:
        using ChannelList = std::vector<Channel*>;

        Poller(EventLoop* loop);
        virtual ~Poller() = default;
        // * 给所有的IO复用保留统一的借口，纯虚函数
        virtual Timestamp poll(int timeoutMs, ChannelList *activeChannels) = 0;
        virtual void updateChannel(Channel *) = 0;
        virtual void removeChannel(Channel *) = 0;

        bool hasChannel(Channel *) const;
        // * EventLoop 可以通过该接口获取IO复用的默认实现
        static Poller *newDefaultPoller(EventLoop *loop);
    protected:
        using ChannelMap = std::unordered_map<int, Channel*>; // * <fd, Channel>
        ChannelMap channels_;
    private:
        EventLoop* ownerloop_;
};