#include "EventLoop.h"

__thread EventLoop *t_loopInThisLoop = nullptr; // * prevent a thread to create more EventLoop obj

const int kPollTimes = 10000; // * Poller default overtime time

// * create a wakeupFd to notify subEventLoop
int createEventfd() {
    int eventFd = ::eventfd(0, EFD_NONBLOCK | EFD_CLOEXEC);
    if (eventFd < 0) {
        LOG_FATAL("eventfd error: %d\n", errno);        
    }
    return eventFd;
}

EventLoop::EventLoop() :
    looping_(false),  
    quit_(false), 
    callingPendingFunctors_(false), 
    threadId_(CurrentThread::tid()), 
    poller_(Poller::newDefaultPoller(this)), 
    wakeupFd_(createEventfd()), 
    wakeupChannel_(new Channel(this, wakeupFd_)) {
    LOG_DEBUG("EventLoop created %p in thread: %d\n", this, threadId_);
    if (t_loopInThisLoop) {
        LOG_FATAL("Another EventLoop %p in this thread: %d\n", t_loopInThisLoop, threadId_);
    } else {
        t_loopInThisLoop = this;
    }
    wakeupChannel_->setReadCallback(std::bind(&EventLoop::handleRead, this)); // * set wakeupfd's event and callback
    wakeupChannel_->enableReading(); // * every eventloop will listen wakeupfd
}

EventLoop::~EventLoop() {
    wakeupChannel_->disableAll();
    wakeupChannel_->remove();
    ::close(wakeupFd_);
    t_loopInThisLoop = nullptr;
}

void EventLoop::loop() {
    looping_ = true;
    quit_ = false;

    LOG_INFO("EventLoop::loop: %p start looping\n", this);

    while(!quit_) {
        activeChannels_.clear();
        // * listen clientfd and wakeupfd
        pollReturnTime_ = poller_->poll(kPollTimes, &activeChannels_);
        for (auto channel : activeChannels_) {
            channel->handlEvent(pollReturnTime_);
        }

        // * wakeup to execute
        doPendingFunctors(); // * execute eventloop's callback
    }

    LOG_INFO("EventLoop %p stop looping\n", this);
    looping_ = false;
}
// * 1. call quit byself 2. call by other thread
void EventLoop::quit() {
    quit_ = true;

    if (!isInLoopThread()) {
        wakeup();
    }   
}

void EventLoop::runInLoop(Functor cb) {
    if (isInLoopThread()) {
        cb();
    } else {
        queueInLoop(cb);
    }
}


void EventLoop::queueInLoop(Functor cb) {
    {
        std::unique_lock<std::mutex> lock(mutex_);
        pendingFuctors_.push_back(cb);
    }
    // * wakeup
    if (!isInLoopThread() || callingPendingFunctors_) // ! if the current is doing cb, must to wakeup again
        wakeup();
}

void EventLoop::handleRead() {
    uint64_t one = 1;
    ssize_t n = read(wakeupFd_, &one, sizeof(one));
    if (n != sizeof(one)) {
        LOG_ERROR("EventLoop::handleRead reads %ld bytes instead of 8", n);
    }
}
// * write one byte to wakeupfd
void EventLoop::wakeup() {
    uint64_t one = 1;
    ssize_t n = write(wakeupFd_, &one, sizeof(one));
    if (n != sizeof(one)) {
        LOG_ERROR("EventLoop::wakeup() writes %lu bytes instead of 8", n);
    }
}

void EventLoop::updateChannel(Channel *channel) {
    poller_->updateChannel(channel);
}

void EventLoop::removeChannel(Channel *channel) {
    poller_->removeChannel(channel);
}

void EventLoop::haschannel(Channel *channel) {
    poller_->hasChannel(channel);
}

void EventLoop::doPendingFunctors() { // * just runing in himself thread
    std::vector<Functor> functors;
    callingPendingFunctors_ = true;
    {   
        std::unique_lock<std::mutex> lock(mutex_);
        functors.swap(pendingFuctors_);
    }
    for (const Functor &functor : functors) {
        functor(); // * to execute current loop's cb
    }
}