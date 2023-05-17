#pragma once

#include <unistd.h>

#include <algorithm>
#include <vector>
#include <string>

/// @code
/// +-------------------+------------------+------------------+
/// | prependable bytes |  readable bytes  |  writable bytes  |
/// |                   |     (CONTENT)    |                  |
/// +-------------------+------------------+------------------+
/// |                   |                  |                  |
/// 0      <=      readerIndex   <=   writerIndex    <=     size
/// @endcode
class Buffer {
    public:
        static const size_t kCheapPrepend = 8;
        static const size_t kInitialSize = 1024;

        explicit Buffer(size_t initialSize = kInitialSize) :
            buffer_(kCheapPrepend + initialSize), 
            readerIndex_(kCheapPrepend), 
            writerIndex_(kCheapPrepend) {}
        
        size_t readableBytes() const { return writerIndex_ - readerIndex_; }
        size_t writeableBytes() const { return buffer_.size() - writerIndex_; }
        size_t prependBytes() const { return readerIndex_; }
        
        const char* peek() const { return begin() + readerIndex_; } // * return readable's begin address

        void retrieve(size_t len) {
            if (len < readableBytes()) {
                readerIndex_ += len;
            } else {
                retrieveAll();
            }
        }

        void retrieveAll() {
            writerIndex_ = readerIndex_ = kCheapPrepend;
        }

        std::string retrieveAllAsString() {
            return retrieveAsString(readableBytes());
        }

        std::string retrieveAsString(size_t len) {
            std::string result(peek(), len);
            retrieve(len);
            return result;
        }

        void ensureWriteablyBytes(size_t len) {
            if (writeableBytes() < len) {
                makeSpace(len);
            }
        }

        void append(const char *data, size_t len) {
            ensureWriteablyBytes(len);
            std::copy(data, data + len, beginWrite());
            writerIndex_ += len;
        }

        ssize_t readFd(int fd, int *saveErrno);
        ssize_t writeFd(int fd, int *saveErrno);
    private:
        char *begin() {
            return &*buffer_.begin();
        }

        const char *begin() const {
            return &*buffer_.begin();
        }   

        char *beginWrite() {
            return begin() + writerIndex_;
        }

        const char *beginWrite() const {
            return begin() + writerIndex_;
        }

        void makeSpace(size_t len) {
            if (writeableBytes() + prependBytes() < len) {
                buffer_.resize(writerIndex_ + len);
            } else {
                size_t readable = readableBytes();
                std::copy(begin() + readerIndex_, begin() + writerIndex_, begin() + kCheapPrepend);
                readerIndex_ = kCheapPrepend;
                writerIndex_ = readerIndex_ + readable;
            }
        }

        std::vector<char> buffer_;
        size_t readerIndex_;
        size_t writerIndex_;
};