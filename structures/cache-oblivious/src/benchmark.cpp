#include "IBST.h"
#include "BSTPtr.h"
#include "BSTVEB.h"
#include "PerfCounters.h"
#include <vector>
#include <random>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "util/json.hpp"
#include <functional>
#include <chrono>

using json = nlohmann::json;
using Clock = std::chrono::steady_clock;

struct Metrics {
    long long ns          = 0;  
    long long ops         = 0;   
    long long cache_refs  = 0;
    long long cache_miss  = 0;
};

template<class Key>
Metrics benchOnce(IBST<Key>& tree,
                  const std::vector<Key>& lookups,
                  const std::vector<Key>& inserts)
{
    for (const auto& k : inserts) tree.insert(k);

    PerfCounters pc;
    pc.start();

    auto start = Clock::now();
    for (const auto& k : lookups)
        (void)tree.contains(k);
    auto end   = Clock::now();

    pc.stop();

    Metrics m;
    m.ns         = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
    m.ops        = lookups.size();
    m.cache_refs = pc.refs();
    m.cache_miss = pc.misses();
    return m;
}


using Factory = std::function<std::unique_ptr<IBST<int>>(void)>;
struct Variant { std::string name; Factory make; };

const std::vector<Variant> variants = {
    {"BST_PTR", []{ return std::make_unique<BSTPtr<int>>(); }},
    {"BST_VEB", []{ return std::make_unique<BSTVEB<int>>(); }},

};

void runExperiment(int n, int q, int T, bool csv,
                   const Factory& make, unsigned seed, std::string impl)
{
    std::mt19937 rng(seed);
    std::uniform_int_distribution<int> dist(1, n*10);

    std::vector<int> inserts(n);
    for (int& x : inserts) x = dist(rng);

    std::vector<int> lookups(q);
    for (int& x : lookups) x = dist(rng);

    long long acc_ns   = 0;
    long long acc_refs = 0, acc_miss = 0;
    
    for (int t = 0; t < T; ++t) {
        auto tree = make();
        Metrics m = benchOnce(*tree, lookups, inserts);
        acc_ns   += m.ns;
        acc_refs += m.cache_refs;
        acc_miss += m.cache_miss;
    }

    double avg_ns      = double(acc_ns)   / T;
    double ns_per_op   = avg_ns / q;

    double avg_refs    = double(acc_refs) / T;
    double avg_miss    = double(acc_miss) / T;
    double miss_per_op = avg_miss / q;
    double avg_s       = avg_ns / 1e9;

    if (csv) {
              std::cout << impl << ',' 
              << n << ',' << q << ','
              << avg_ns << ',' 
              << std::fixed << std::setprecision(2)  
              << avg_s << ','                       
              << std::defaultfloat                 
              << ns_per_op << ','
              << avg_refs << ',' << avg_miss << ','
              << miss_per_op << '\n';
    } else {
            std::cout << std::fixed << std::setprecision(2);

        std::cout << std::left
          << std::setw(10) << impl
          << std::setw(10) << n
          << std::setw(10) << q
          << std::setw(15) << avg_ns
          << std::setw(10) << avg_s        
          << std::defaultfloat << std::setprecision(6)
          << std::setw(15) << ns_per_op
          << std::setw(15) << avg_refs
          << std::setw(15) << avg_miss
          << std::setw(12) << miss_per_op
          << '\n';

    }
}

int main(int argc, char* argv[])
{
    int n      = 10000;   
    int q      = 10000;   
    int T      = 1;      
    bool csv   = false;
    unsigned seed = 42;
    std::string impl = "ALL";

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
    }

    if (argc == 3) impl = argv[2];

    if (!csv) {
    std::cout << std::left
        << std::setw(10) << "impl"
          << std::setw(10) << "n"
          << std::setw(10) << "q"
          << std::setw(15) << "total_ns"
          << std::setw(10) << "total_s"    
          << std::setw(15) << "ns/search"
          << std::setw(15) << "cache_refs"
          << std::setw(15) << "cache_miss"
          << std::setw(12) << "miss/search" << '\n'
          << std::string(101,'-') << '\n';
} else {
    std::cout << "impl,n,q,total_ns,total_s,ns_per_search,cache_refs,cache_misses,misses_per_search\n";
}
    for (const auto& v : variants) {
        if (impl != "ALL" && impl != v.name) continue;
        runExperiment(n, q, T, csv, v.make, seed, v.name);
    }
    return 0;
}
