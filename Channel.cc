#include "Channel.h"
#include "EventLoop.h"

#include <sys/epoll.h>

const int Channel::kNoneEvent = 0;
const int Channel::kReadEvent = EPOLLIN | EPOLLPRI;
const int Channel::kWriteEvent = EPOLLOUT;

Channel::Channel(EventLoop* loop, int fd)
    : loop_(loop)
    , fd_(fd)
    , events_(0)
    , revents_(0)
    , index_(-1) 
    , tied_(false) {

}

Channel::~Channel() {

}
// ? 何时调用, bind TcpConnection 避免TcpConnection被销毁之后channel还执行回调
void Channel::tie(const std::shared_ptr<void> &obj) { 
    tie_ = obj;
    tied_ = true;
}

// * 通过loop中的poller进行更新
void Channel::updata() {
    loop_->updateChannel(this);
}

void Channel::remove() {
    loop_->removeChannel(this);
}
// * fd得到poller通知时执行
void Channel::handlEvent(Timestamp receivetime) {
    if (tied_) {
        std::shared_ptr<void> guard;
        guard = tie_.lock();
        if (guard) {
            handleEventWithGuard(receivetime);
        }
    } else {
        handleEventWithGuard(receivetime);
    }
}

void Channel::handleEventWithGuard(Timestamp receiveTime) {
    LOG_INFO("channel handleEventWithGuard revents: %d", revents_);
    if (revents_ & EPOLLHUP && !(revents_ & EPOLLIN)) {
        if (closeCallback_)
            closeCallback_();
    }
    if (revents_ & EPOLLERR) {
        if (errorCallback_)
            errorCallback_();
    }
    if (revents_ & (EPOLLIN | EPOLLPRI)) {
        if (readCallback_)
            readCallback_(receiveTime);
    }
    if (revents_ & EPOLLOUT) {
        if (writeCallback_)
            writeCallback_();
    }
}