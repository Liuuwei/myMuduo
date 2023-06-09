#pragma once

#include "noncopyable.h"
#include "Timestamp.h"

#include <string>
#include <iostream>

#define LOG_INFO(logmsgFormat, ...) \
    do{ \
        logger &logger = logger::instance(); \
        logger.setLogLevel(INFO); \
        char buf[1024] = {0}; \
        snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__); \
        logger.log(buf); \
    } while(0);

#define LOG_ERROR(logmsgFormat, ...) \
    do{ \
        logger &logger = logger::instance(); \
        logger.setLogLevel(ERROR); \
        char buf[1024] = {0}; \
        snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__); \
        logger.log(buf); \
    } while(0);

#define LOG_FATAL(logmsgFormat, ...) \
    do{ \
        logger &logger = logger::instance(); \
        logger.setLogLevel(FATAL); \
        char buf[1024] = {0}; \
        snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__); \
        logger.log(buf); \
        exit(1); \
    } while(0);
#ifdef MUDUO_DEBUG
#define LOG_DEBUG(logmsgFormat, ...) \
    do{ \
        logger &logger = logger::instance(); \
        logger.setLogLevel(DEBUG); \
        char buf[1024] = {0}; \
        snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__); \
        logger.log(buf); \
    } while(0);
#else
#define LOG_DEBUG(logmsgFormat, ...)
#endif

// *log level INFO ERROR FATAL DEBUG
enum LogLevel {
    INFO, 
    ERROR, 
    FATAL, 
    DEBUG, 
};

class logger : noncopyable {
    public:
        logger() {}
        ~logger() {}
        static logger &instance();
        void setLogLevel(int Level);
        void log(std::string msg);
    private:
        int logLevel_;
};