#include "Buffer.h"
#include "logger.h"

#include <sys/uio.h>
#include <unistd.h>

ssize_t Buffer::readFd(int fd, int *saveErrno) {
    char extraBuf[65536] = {0};
    ::iovec vec[2];
    const size_t writeAble = writeableBytes();
    vec[0].iov_base = begin() + writerIndex_;
    vec[0].iov_len = writeAble;
    vec[1].iov_base = extraBuf;
    vec[1].iov_len = sizeof(extraBuf);

    int iovcnt = (writeAble > sizeof(extraBuf)) ? 2 : 1; // * 一次最多读64k，如果writeable大于65536则不必使用extrabuf
    int n = readv(fd, vec, iovcnt);
    if (n < 0) {
        *saveErrno = errno;
    } else if(n <= writeAble) { // * Buffer 自身空间足够读取
        writerIndex_ += n;
    } else { // * 用到了extrabuf
        writerIndex_ = buffer_.size();
        append(extraBuf, n - writeAble);
    }
    return n;
}

ssize_t Buffer::writeFd(int fd, int *saveErrno) {
    ssize_t n = ::write(fd, peek(), readableBytes());
    if (n < 0) {
        *saveErrno = errno;
    }
    return n;
}