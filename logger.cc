#include "logger.h"

logger& logger::instance() {
    static logger logger;
    return logger;
}

void logger::setLogLevel(int level) {
    logLevel_ = level;
}

void logger::log(std::string msg) {
    switch (logLevel_) {
        case INFO:
            std::cout << "[INFO]";
            break;
        case ERROR:
            std::cout << "[ERROR]";
            break;
        case FATAL:
            std::cout << "[FATAL]";
            break;
        case DEBUG:
            std::cout << "[DEBUF]";
            break;       
    }
    std::cout << Timestamp::now().toString() << msg << " " << std::endl;
}