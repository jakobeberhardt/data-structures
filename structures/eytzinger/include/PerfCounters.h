#pragma once
#include <linux/perf_event.h>
#include <cstdint>
#include <sys/syscall.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <cstring>
#include <cerrno>
#include <stdexcept>

class PerfCounters {
    int fd_refs_{-1},     fd_miss_{-1}; 
    int fd_l1_refs_{-1},  fd_l1_miss_{-1};
    int fd_l2_refs_{-1},  fd_l2_miss_{-1};
    int fd_l3_refs_{-1},  fd_l3_miss_{-1};
    int fd_br_{-1},       fd_br_miss_{-1};  

    long long refs_{0},  miss_{0};
    long long l1_refs_{0}, l1_miss_{0};
    long long l2_refs_{0}, l2_miss_{0};
    long long l3_refs_{0}, l3_miss_{0};
    long long br_{0},     br_miss_{0};

    static int open(uint32_t type, uint64_t cfg)
    {
        perf_event_attr pea{};
        pea.type           = type;
        pea.size           = sizeof(pea);
        pea.config         = cfg;
        pea.disabled       = 1;
        pea.exclude_kernel = 0;
        pea.exclude_hv     = 1;

        int fd = syscall(__NR_perf_event_open, &pea, 0, -1, -1, 0);
        if (fd == -1)
            throw std::runtime_error{"perf_event_open: " + std::string(strerror(errno))};
        return fd;
    }
    static int openCache(uint64_t id, uint64_t result)
    {
        uint64_t cfg = id
                     | (PERF_COUNT_HW_CACHE_OP_READ << 8)
                     | (result                       << 16);
        return open(PERF_TYPE_HW_CACHE, cfg);
    }
    static int tryOpenCache(uint64_t id, uint64_t result)
    {
        try { return openCache(id, result); }
        catch (...) { return -1; }
    }
public:
    PerfCounters()
    {
        fd_refs_  = open(PERF_TYPE_HARDWARE, PERF_COUNT_HW_CACHE_REFERENCES);
        fd_miss_  = open(PERF_TYPE_HARDWARE, PERF_COUNT_HW_CACHE_MISSES);

        fd_l1_refs_ = openCache(PERF_COUNT_HW_CACHE_L1D,
                                PERF_COUNT_HW_CACHE_RESULT_ACCESS);
        fd_l1_miss_ = openCache(PERF_COUNT_HW_CACHE_L1D,
                                PERF_COUNT_HW_CACHE_RESULT_MISS);

    #if defined(PERF_COUNT_HW_CACHE_L2)
        fd_l2_refs_ = tryOpenCache(PERF_COUNT_HW_CACHE_L2,
                                   PERF_COUNT_HW_CACHE_RESULT_ACCESS);
        fd_l2_miss_ = tryOpenCache(PERF_COUNT_HW_CACHE_L2,
                                   PERF_COUNT_HW_CACHE_RESULT_MISS);
    #elif defined(PERF_COUNT_HW_CACHE_L2D)
        fd_l2_refs_ = tryOpenCache(PERF_COUNT_HW_CACHE_L2D,
                                   PERF_COUNT_HW_CACHE_RESULT_ACCESS);
        fd_l2_miss_ = tryOpenCache(PERF_COUNT_HW_CACHE_L2D,
                                   PERF_COUNT_HW_CACHE_RESULT_MISS);
    #endif

        fd_l3_refs_ = openCache(PERF_COUNT_HW_CACHE_LL,
                                PERF_COUNT_HW_CACHE_RESULT_ACCESS);
        fd_l3_miss_ = openCache(PERF_COUNT_HW_CACHE_LL,
                                PERF_COUNT_HW_CACHE_RESULT_MISS);

        fd_br_      = open(PERF_TYPE_HARDWARE,
                           PERF_COUNT_HW_BRANCH_INSTRUCTIONS);
        fd_br_miss_ = open(PERF_TYPE_HARDWARE,
                           PERF_COUNT_HW_BRANCH_MISSES);
    }
    ~PerfCounters()
    {
        for (int fd : {fd_refs_, fd_miss_,
                       fd_l1_refs_, fd_l1_miss_,
                       fd_l2_refs_, fd_l2_miss_,
                       fd_l3_refs_, fd_l3_miss_,
                       fd_br_, fd_br_miss_})
            if (fd != -1) close(fd);
    }

    void start() const
    {
        for (int fd : {fd_refs_, fd_miss_,
                       fd_l1_refs_, fd_l1_miss_,
                       fd_l2_refs_, fd_l2_miss_,
                       fd_l3_refs_, fd_l3_miss_,
                       fd_br_, fd_br_miss_})
            if (fd != -1) {
                ioctl(fd, PERF_EVENT_IOC_RESET, 0);
                ioctl(fd, PERF_EVENT_IOC_ENABLE, 0);
            }
    }
    void stop()
    {
        for (int fd : {fd_refs_, fd_miss_,
                       fd_l1_refs_, fd_l1_miss_,
                       fd_l2_refs_, fd_l2_miss_,
                       fd_l3_refs_, fd_l3_miss_,
                       fd_br_, fd_br_miss_})
            if (fd != -1) ioctl(fd, PERF_EVENT_IOC_DISABLE, 0);

        auto rd = [](int fd, long long& dst){
            if (fd != -1 && read(fd, &dst, sizeof dst) != sizeof dst)
                throw std::runtime_error("read perf counter failed");
        };
        rd(fd_refs_, refs_);      rd(fd_miss_, miss_);
        rd(fd_l1_refs_, l1_refs_); rd(fd_l1_miss_, l1_miss_);
        rd(fd_l2_refs_, l2_refs_); rd(fd_l2_miss_, l2_miss_);
        rd(fd_l3_refs_, l3_refs_); rd(fd_l3_miss_, l3_miss_);
        rd(fd_br_, br_);           rd(fd_br_miss_, br_miss_);
    }

    long long refs()  const { return refs_;  }
    long long misses()const { return miss_;  }

    long long l1_refs()   const { return l1_refs_;   }
    long long l1_misses() const { return l1_miss_;   }

    long long l2_refs()   const { return l2_refs_;   }
    long long l2_misses() const { return l2_miss_;   }

    long long l3_refs()   const { return l3_refs_;   }
    long long l3_misses() const { return l3_miss_;   }

    long long branches()       const { return br_;       }
    long long branch_misses()  const { return br_miss_;  }
};
