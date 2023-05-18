#pragma once

#include <sys/syscall.h>
#include <unistd.h>

namespace CurrentThread {
    extern __thread int t_cacheId;

    void cacheTid();

    inline int tid() {
        if (__builtin_expect(t_cacheId == 0, 0)) {
            cacheTid();
        }
        return t_cacheId;
    }
}