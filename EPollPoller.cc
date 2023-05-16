#include "EPollPoller.h"

const int kNew = -1; // * 表示Channel未添加到EPoll
const int kAdded = 1;
const int kDeleted = 2;

EPollPoller::EPollPoller(EventLoop *loop)
    : Poller(loop)
    , epollfd_(::epoll_create1(EPOLL_CLOEXEC))
    , events_(kInitEventListSize) {
    if (epollfd_ < 0) {
        LOG_FATAL("epoll_create error: %d\n", errno);
    }
}

EPollPoller::~EPollPoller() {
    ::close(epollfd_);
}

Timestamp EPollPoller::poll(int timeoutMs, ChannelList *activeChannels) {
    LOG_INFO("Function=%s, fd count total: %ld", __FUNCTION__, channels_.size());
    int numEvents = ::epoll_wait(epollfd_, &*events_.begin(), static_cast<int>(events_.size()), timeoutMs);
    int saveError = errno;
    Timestamp now(Timestamp::now());

    if (numEvents > 0) {
        LOG_INFO("%d events happened\n", numEvents);
        fillActiveChannels(numEvents, activeChannels);
        if (numEvents == events_.size()) {
            events_.resize(events_.size() * 2);
        }
    } else if (numEvents == 0) {
        LOG_DEBUG("%s timeout\n", __FUNCTION__);
    } else {
        if (saveError != EINTR) {
            errno = saveError;
            LOG_ERROR("epoll_wait\n");
        }
    }
    return Timestamp::now();
}

void EPollPoller::fillActiveChannels(int numEvents, ChannelList *activeChannels) const {
    for (int i = 0; i < numEvents; ++ i) {
        Channel *channel = static_cast<Channel *>(events_[i].data.ptr);
        channel->setRevents(events_[i].events);
        activeChannels->push_back(channel);
    }
}

void EPollPoller::updateChannel(Channel *channel) {
    const int index = channel->index();
    LOG_INFO("Function=%s, fd=%d, events=%d, index=%d\n", __FUNCTION__, channel->fd(), channel->events(), index);
    if (index == kNew || index == kDeleted) {
        if (index == kNew) {
            int fd = channel->fd();
            channels_[fd] = channel;
        }
        channel->setIndex(kAdded);
        update(EPOLL_CTL_ADD, channel);
    } else {
        int fd = channel->fd();
        if (channel->isNoneEvent()) {
            update(EPOLL_CTL_DEL, channel);
            channel->setIndex(kDeleted);
        } else {
            update(EPOLL_CTL_MOD, channel);
        }
    }
}

void EPollPoller::removeChannel(Channel *channel) {
    LOG_INFO("Function=%s, fd=%d\n", __FUNCTION__, channel->fd());
    int fd = channel->fd();
    int index = channel->index();
    channels_.erase(fd);
    if (index == kAdded) {
        update(EPOLL_CTL_DEL, channel);
    }
    channel->setIndex(kNew);
}

void EPollPoller::update(int operation, Channel *channel) {
    epoll_event event;
    bzero(channel, sizeof(channel));
    event.data.ptr = channel;
    event.events = channel->events();
    int fd = channel->fd();
    if (::epoll_ctl(epollfd_, operation, fd, &event) < 0) {
        if (operation == EPOLL_CTL_DEL) {
            LOG_ERROR("epoll_ctl del error: %d\n", errno);
        } else {
            LOG_FATAL("epoll ctl add|mod error: %d\n", errno);
        }
    }
}