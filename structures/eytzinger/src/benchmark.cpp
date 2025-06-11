#include "IBST.h"
#include "BSTVEB.h"
#include "BSTEyt.h"
#include "BSTEytPrefetch.h"
#include "BSTEytPrefetchTwo.h"
#include "BSTEytPrefetchThree.h"
#include "BSTEytPrefetchFour.h"
#include "PerfCounters.h"
#include <vector>
#include <random>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <functional>
#include <chrono>
#include "util/json.hpp"

using json  = nlohmann::json;
using Clock = std::chrono::steady_clock;

struct Metrics {
    long long ns = 0, ops = 0;

    long long c_refs = 0, c_miss = 0;
    long long l1_refs = 0, l1_miss = 0;
    long long l2_refs = 0, l2_miss = 0;
    long long l3_refs = 0, l3_miss = 0;

    long long branches = 0, br_miss = 0;
};

template<class Key>
Metrics benchOnce(IBST<Key>& tree,
                  const std::vector<Key>& lookups,
                  const std::vector<Key>& inserts,
                  bool       measure_construction)
{
    for (const auto& k : inserts) tree.insert(k);

    if (!measure_construction && !lookups.empty()) (void)tree.contains(lookups[0]);

    PerfCounters pc; pc.start();
    auto t0 = Clock::now();
    for (const auto& k : lookups) (void)tree.contains(k);
    auto t1 = Clock::now();
    pc.stop();

    Metrics m;
    m.ns       = std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count();
    m.ops      = lookups.size();

    m.c_refs   = pc.refs();       m.c_miss   = pc.misses();
    m.l1_refs  = pc.l1_refs();    m.l1_miss  = pc.l1_misses();
    m.l2_refs  = pc.l2_refs();    m.l2_miss  = pc.l2_misses();
    m.l3_refs  = pc.l3_refs();    m.l3_miss  = pc.l3_misses();
    m.branches = pc.branches();   m.br_miss  = pc.branch_misses();
    return m;
}

using Factory = std::function<std::unique_ptr<IBST<int>>()>;
struct Variant { std::string name; Factory make; };

const std::vector<Variant> variants = {
    {"BST_VEB",      [] { return std::make_unique<BSTVEB<int>>(); }},
    {"BST_EYT",      [] { return std::make_unique<BSTEyt<int>>(); }},
    {"BST_EYT_PREF", [] { return std::make_unique<BSTEytPref<int>>(); }},
    {"BST_EYT_PREF_TWO", [] { return std::make_unique<BSTEytPrefTwo<int>>(); }},
    {"BST_EYT_PREF_THREE", [] { return std::make_unique<BSTEytPrefThree<int>>(); }},
    {"BST_EYT_PREF_FOUR", [] { return std::make_unique<BSTEytPrefFour<int>>(); }},
};

void runExperiment(int n, int q, int T, bool csv,
                   const Factory& make, unsigned seed,
                   const std::string& impl, bool measure_construction)
{
    std::mt19937 rng(seed);
    std::uniform_int_distribution<int> dist(1, n * 10);

    std::vector<int> inserts(n);
    for (int& x : inserts) x = dist(rng);
    std::vector<int> lookups(q);
    for (int& x : lookups) x = dist(rng);

    long long acc_ns = 0,
              acc_c_refs = 0,  acc_c_miss = 0,
              acc_l1_refs = 0, acc_l1_miss = 0,
              acc_l2_refs = 0, acc_l2_miss = 0,
              acc_l3_refs = 0, acc_l3_miss = 0,
              acc_br = 0,      acc_br_miss = 0;

    std::size_t bytes_used = 0;

    for (int t = 0; t < T; ++t) {
        auto tree = make();
        Metrics m = benchOnce(*tree, lookups, inserts, measure_construction);

        acc_ns      += m.ns;
        acc_c_refs  += m.c_refs;  acc_c_miss  += m.c_miss;
        acc_l1_refs += m.l1_refs; acc_l1_miss += m.l1_miss;
        acc_l2_refs += m.l2_refs; acc_l2_miss += m.l2_miss;
        acc_l3_refs += m.l3_refs; acc_l3_miss += m.l3_miss;
        acc_br      += m.branches;acc_br_miss += m.br_miss;

        if (t == 0) bytes_used = tree->size_bytes();
    }

    auto avgLL = [T](long long v){ return double(v) / T; };

    double avg_ns       = avgLL(acc_ns),   ns_per_op = avg_ns / q, avg_s = avg_ns / 1e9;
    double avg_c_refs   = avgLL(acc_c_refs),  avg_c_miss = avgLL(acc_c_miss);
    double avg_l1_refs  = avgLL(acc_l1_refs), avg_l1_miss = avgLL(acc_l1_miss);
    double avg_l2_refs  = avgLL(acc_l2_refs), avg_l2_miss = avgLL(acc_l2_miss);
    double avg_l3_refs  = avgLL(acc_l3_refs), avg_l3_miss = avgLL(acc_l3_miss);
    double avg_br       = avgLL(acc_br),      avg_br_miss = avgLL(acc_br_miss);

    auto rate = [](double miss, double ref){ return ref ? miss / ref : 0.0; };

    double miss_per_op  = avg_c_miss / q;
    double miss_rate    = rate(avg_c_miss, avg_c_refs);
    double l1_rate      = rate(avg_l1_miss, avg_l1_refs);
    double l2_rate      = rate(avg_l2_miss, avg_l2_refs);
    double l3_rate      = rate(avg_l3_miss, avg_l3_refs);
    double br_rate      = rate(avg_br_miss, avg_br);

    double bytes_mb     = bytes_used / 1024.0 / 1024.0;

    if (csv) {
        std::cout << impl << ','
                  << n << ',' << q << ','
                  << avg_ns << ',' << avg_s << ','
                  << ns_per_op << ','
                  << avg_c_refs << ',' << avg_c_miss << ','
                  << miss_per_op << ',' << miss_rate << ','
                  << bytes_used << ','
                  << avg_l1_refs << ',' << avg_l1_miss << ',' << l1_rate << ','
                  << avg_l2_refs << ',' << avg_l2_miss << ',' << l2_rate << ','
                  << avg_l3_refs << ',' << avg_l3_miss << ',' << l3_rate << ','
                  << avg_br << ',' << avg_br_miss << ',' << br_rate
                  << '\n';
    } else {
    std::cout << std::left << std::fixed <<  std::setprecision(2)
              << std::setw(22)  << impl
              << std::setw(8)  << n
              << std::setw(8)  << q
              << std::setw(14) << std::setprecision(0) << avg_ns
              << std::setw(8)  << std::setprecision(2) << avg_s
              << std::setw(14) << std::setprecision(6) << ns_per_op
              << std::setw(12) << std::setprecision(0) << avg_c_refs
              << std::setw(12) << avg_c_miss
              << std::setw(12) << miss_per_op
              << std::setw(10) << std::setprecision(6) << miss_rate
              << std::setw(6)  << std::setprecision(1) << bytes_mb
              << std::setw(12) << std::setprecision(0) << avg_l1_refs
              << std::setw(12) << avg_l1_miss
              << std::setw(10) << std::setprecision(6) << l1_rate
              << std::setw(12) << std::setprecision(0) << avg_l2_refs
              << std::setw(12) << avg_l2_miss
              << std::setw(10) << std::setprecision(6) << l2_rate
              << std::setw(12) << std::setprecision(0) << avg_l3_refs
              << std::setw(12) << avg_l3_miss
              << std::setw(10) << std::setprecision(6) << l3_rate
              << std::setw(12) << std::setprecision(0) << avg_br
              << std::setw(12) << avg_br_miss
              << std::setw(10) << std::setprecision(6) << br_rate
              << '\n';
}
}

int main(int argc, char* argv[])
{
    int  n = 10000, q = 10000, T = 1;
    bool csv = false;
    unsigned seed = 42;
    std::string impl = "ALL";
    bool measure_construction = true;

    if (argc >= 2) {
        std::ifstream in(argv[1]);
        if (!in) { std::cerr << "Cannot open " << argv[1] << '\n'; return 1; }
        json cfg; in >> cfg;
        if (cfg.contains("n"))    n    = cfg["n"];
        if (cfg.contains("q"))    q    = cfg["q"];
        if (cfg.contains("T"))    T    = cfg["T"];
        if (cfg.contains("csv"))  csv  = cfg["csv"];
        if (cfg.contains("seed")) seed = cfg["seed"];
        if (cfg.contains("impl")) impl = cfg["impl"];
        if (cfg.contains("measure_construction")) measure_construction = cfg["measure_construction"];
    }
    if (argc == 3) impl = argv[2];

    if (!csv) {
    std::cout << std::left
              << std::setw(22)  << "impl"
              << std::setw(8)  << "n"
              << std::setw(8)  << "q"
              << std::setw(14) << "total_ns"
              << std::setw(8)  << "total_s"
              << std::setw(14) << "ns/search"
              << std::setw(12) << "c_refs"
              << std::setw(12) << "c_miss"
              << std::setw(12) << "miss/sea"
              << std::setw(10) << "missRate"
              << std::setw(6)  << "MB"
              << std::setw(12) << "L1_refs"
              << std::setw(12) << "L1_miss"
              << std::setw(10) << "L1rate"
              << std::setw(12) << "L2_refs"
              << std::setw(12) << "L2_miss"
              << std::setw(10) << "L2rate"
              << std::setw(12) << "L3_refs"
              << std::setw(12) << "L3_miss"
              << std::setw(10) << "L3rate"
              << std::setw(12) << "branches"
              << std::setw(12) << "br_miss"
              << std::setw(10) << "brRate"
              << '\n'
              << std::string(255, '-') << '\n';
}else {
        std::cout << "impl,n,q,total_ns,total_s,ns_per_search,"
                     "cache_refs,cache_misses,misses_per_search,miss_rate,bytes,"
                     "l1_refs,l1_misses,l1_rate,"
                     "l2_refs,l2_misses,l2_rate,"
                     "l3_refs,l3_misses,l3_rate,"
                     "branches,branch_misses,branch_rate\n";
    }

    for (const auto& v : variants) {
        if (impl != "ALL" && impl != v.name) continue;
        runExperiment(n, q, T, csv, v.make, seed, v.name, measure_construction);
    }
    return 0;
}
