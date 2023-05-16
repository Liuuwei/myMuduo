#pragma once

#include "noncopyable.h"
#include "Timestamp.h"
#include "logger.h"

#include <functional>
#include <memory>

class EventLoop;

// * Channel 为通道，封装了sockfd，event，

class Channel : noncopyable{
    public:
        using EventCallback = std::function<void()>;
        using ReadEventCallback = std::function<void(Timestamp)>;

        Channel(EventLoop* loop, int fd);
        ~Channel();

        // * 调用 Callback
        void handlEvent(Timestamp receivetime);
        void setReadCallback(ReadEventCallback cb) { readCallback_ = std::move(cb); }
        void setWriteCallback(EventCallback cb) { writeCallback_ = std::move(cb); }
        void setCloseCallback(EventCallback cb) { closeCallback_ = std::move(cb); }
        void setErrorCallback(EventCallback cb) { errorCallback_ = std::move(cb); }
        // * 防止当Channel被手动remove之后，Channel还在执行回调
        void tie(const std::shared_ptr<void>&);
        
        int fd() const { return fd_; }
        int events() const { return events_; }
        void setRevents(int revt) { revents_ = revt; }

        void enableReading() { events_ |= kReadEvent; updata(); }
        void enableWriteing() { events_ |= kWriteEvent; updata(); }
        void disableReading() { events_ |= ~kReadEvent; updata(); }
        void disableWriteing() { events_ &= ~kWriteEvent; updata(); }
        void disableAll() { events_ = kNoneEvent; updata(); }

        bool isNoneEvent() const { return events_&kNoneEvent; }
        bool isReading() const { return events_&kReadEvent; }
        bool isWriteing() const { return events_&kWriteEvent; }

        int index() const { return index_; }
        void setIndex(int idx) { index_ = idx; }

        EventLoop* ownerLopp() const { return loop_; }
        void remove();
    private:
        void updata();
        void handleEventWithGuard(Timestamp receiveTime);
        static const int kNoneEvent;
        static const int kReadEvent;
        static const int kWriteEvent;

        EventLoop *loop_;
        const int fd_;
        int events_;
        int revents_;
        int index_;

        std::weak_ptr<void> tie_;
        bool tied_;

        ReadEventCallback readCallback_;
        EventCallback writeCallback_;
        EventCallback closeCallback_;
        EventCallback errorCallback_;
};