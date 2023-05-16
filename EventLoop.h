#pragma once

#include "CurrentThread.h"
#include "noncopyable.h"
#include "Timestamp.h"
#include "Channel.h"
#include "logger.h"
#include "Poller.h"

#include <sys/eventfd.h>
#include <unistd.h>

#include <functional>
#include <memory>
#include <vector>
#include <atomic>
#include <mutex>

class Channel;
class Poller;

// * 事件循环类 {Channel, Poller}
class EventLoop : noncopyable{
    public:
        using Functor = std::function<void()>;

        EventLoop();
        ~EventLoop();

        void loop();
        void quit();
        Timestamp pollReturnTime() const { return pollReturnTime_; }
        void runInLoop(Functor cb); // * run in current thread
        void queueInLoop(Functor cb); // * run in the loop's thread
        void wakeup(); // * wakeup the loop's thread
        void updateChannel(Channel *channel);
        void removeChannel(Channel *channel);
        void haschannel(Channel *channel);

        bool isInLoopThread() const { return threadId_ == CurrentThread::tid(); } // * determine whether the loop obj in it's thread
    private:
        void handleRead();
        void doPendingFunctors();
        using ChannelList = std::vector<Channel *>;

        std::atomic<bool> looping_; // * atomic realize by CAS
        std::atomic<bool> quit_;
        std::atomic<bool> callingPendingFunctors_;// * 当前loop是否有需要执行的回调
        const pid_t threadId_;
        Timestamp pollReturnTime_; // * Poller返回事件的时间点
        std::unique_ptr<Poller> poller_;

        int wakeupFd_; // * use wakeupFd_ to wakeup one loop when mainLoop get a new connection
        std::unique_ptr<Channel> wakeupChannel_;

        ChannelList activeChannels_;
        
        std::vector<Functor> pendingFuctors_; // * storage all callback of the loop
        std::mutex mutex_;; // * to protect pendingFuctors_
};