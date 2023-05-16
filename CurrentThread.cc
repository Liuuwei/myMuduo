#include "CurrentThread.h"

namespace CurrentThread {
    __thread int t_cacheId = 0;

    void cacheTid() {
        if (t_cacheId == 0) {
            t_cacheId = static_cast<pid_t>(syscall(SYS_gettid));
        }
    }
}