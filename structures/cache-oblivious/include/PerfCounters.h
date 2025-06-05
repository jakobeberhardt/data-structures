#pragma once
#include <linux/perf_event.h>
#include <cstdint>         
#include <sys/syscall.h>    
#ifndef __NR_perf_event_open
#endif
#include <sys/ioctl.h>
#include <unistd.h>
#include <cstring>
#include <cerrno>
#include <stdexcept>
#include <array>

class PerfCounters {
    int fd_refs_{-1}, fd_misses_{-1};
    long long refs_{0}, misses_{0};

    static int openCounter(uint32_t type, uint64_t config)
    {
        perf_event_attr pea{};
        pea.type           = type;
        pea.size           = sizeof(perf_event_attr);
        pea.config         = config;
        pea.inherit        = 0;       
        pea.disabled       = 1;
        pea.exclude_kernel = 0;
        pea.exclude_hv     = 1;

        int fd = syscall(__NR_perf_event_open, &pea, 0, -1, -1, 0);
        if (fd == -1)
            throw std::runtime_error{"perf_event_open: " + std::string(strerror(errno))};
        return fd;
    }
public:
    PerfCounters()
    {
        fd_refs_   = openCounter(PERF_TYPE_HARDWARE, PERF_COUNT_HW_CACHE_REFERENCES);
        fd_misses_ = openCounter(PERF_TYPE_HARDWARE, PERF_COUNT_HW_CACHE_MISSES);
    }
    ~PerfCounters() { close(fd_refs_); close(fd_misses_); }

    inline void start() const { ioctl(fd_refs_, PERF_EVENT_IOC_RESET, 0); ioctl(fd_misses_, PERF_EVENT_IOC_RESET, 0);
                                ioctl(fd_refs_, PERF_EVENT_IOC_ENABLE, 0); ioctl(fd_misses_, PERF_EVENT_IOC_ENABLE, 0); }
    inline void stop()
{
    ioctl(fd_refs_,   PERF_EVENT_IOC_DISABLE, 0);
    ioctl(fd_misses_, PERF_EVENT_IOC_DISABLE, 0);

    if (read(fd_refs_, &refs_, sizeof(refs_))   != sizeof(refs_))
        throw std::runtime_error("failed to read cache-refs counter");
    if (read(fd_misses_, &misses_, sizeof(misses_)) != sizeof(misses_))
        throw std::runtime_error("failed to read cache-miss counter");
}
    long long refs()   const { return refs_;   }
    long long misses() const { return misses_; }
};
