#pragma

#include "copyable.h"

#include <arpa/inet.h>
#include <string.h>
#include <string>

class InetAddress : public copyable {
    public:
        explicit InetAddress(uint16_t port = 9999, std::string ip = "127.0.0.1");
        explicit InetAddress(const sockaddr_in& addr) : addr_(addr) {}
        std::string toIp() const;
        std::string toIpPort() const;
        uint16_t toPort() const;
        const sockaddr_in* getSockaddr() const { return &addr_; }
        void setSockAddr(const sockaddr_in &addr) { addr_ = addr; }
    private:
        sockaddr_in addr_;
};