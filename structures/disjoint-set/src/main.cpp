#include "DisjointSet.h"
#include "QuickUnion.h"
#include <vector>
#include <random>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <fstream>
#include "json.hpp"
using json = nlohmann::json;

struct Metrics { long tpl = 0; long tpu = 0; };

Metrics measureMetrics(const DisjointSet& uf, int n)
{
    Metrics m;
    for (int v = 0; v < n; ++v) {
        m.tpl += uf.depth(v);
        m.tpu += uf.pointerUpdatesDuringFind(v);
    }
    return m;
}


inline std::pair<int,int> indexToPair(long long k)
{
    long long i = static_cast<long long>( (1 + std::sqrt(1 + 8.0*k)) / 2 );
    while (i*(i-1)/2 > k) --i;
    long long j = k - (i*(i-1))/2;
    return {static_cast<int>(i), static_cast<int>(j)};
}

class PairPermutation {
    public:
        PairPermutation(long long m, unsigned seed)
            : perm_(m), idx_(0)
        {
            for (long long i = 0; i < m; ++i) perm_[i] = i;
            std::shuffle(perm_.begin(), perm_.end(), std::mt19937_64(seed));
        }
    
        bool next(long long &k)
        {
            if (idx_ >= perm_.size()) return false;
            k = perm_[idx_++];
            return true;
        }
    private:
        std::vector<long long> perm_;
        size_t                 idx_;
    };


    void runExperiment(int n, int delta, int T,
        bool csv,
        double followMult,   
        double epsilon)  
{
const int steps = (n - 1) / delta + 1;
std::vector<long long> accTPL(steps,0), accTPU(steps,0);
std::vector<int>       accCnt(steps,0);

const unsigned baseSeed = 42;
for (int t = 0; t < T; ++t)
{
QuickUnion uf(n);

PairPermutation perm(1LL*n*(n-1)/2, baseSeed + t);
long long k;
int nextThresh = n - delta + 1;
int slot       = 0;

while (perm.next(k)) {
 auto [i,j] = indexToPair(k);
 uf.unionSets(i,j);

 if (uf.countSets() <= nextThresh) {
     Metrics m = measureMetrics(uf, n);
     accTPL[slot] += m.tpl;
     accTPU[slot] += m.tpu;
     accCnt[slot] += 1;

     nextThresh   = std::max(1, nextThresh - delta);
     ++slot;
     if (uf.countSets()==1) break;
 }
}
}

if (!csv) {
std::cout << std::left
       << std::setw(18) << "Number of Blocks"
       << std::setw(15) << "AvgTPL"
       << std::setw(15) << "AvgTPU"
       << std::setw(15) << "Cost"
       << std::setw(15) << "TPL/n"
       << std::setw(15) << "TPU/n"
       << std::setw(15) << "Cost/n" << '\n'
       << std::string(108,'-') << '\n';
}

for (int s = 0; s < steps; ++s) {
if (accCnt[s] < 5) continue;

int    blocks = (s < steps-1) ? n - delta + 1 - s*delta : 1;
double tpl    = double(accTPL[s]) / accCnt[s];
double tpu    = double(accTPU[s]) / accCnt[s];
double cost   = followMult * tpl + epsilon * tpu;

if (csv) {
 if (s == 0) 
     std::cout << "Blocks,AvgTPL,AvgTPU,Cost,TPL_per_n,TPU_per_n,Cost_per_n\n";
 std::cout << blocks  << ','
           << tpl     << ','
           << tpu     << ','
           << cost    << ','
           << tpl/n   << ','
           << tpu/n   << ','
           << cost/n  << '\n';
} else {
 std::cout << std::left
           << std::setw(18) << blocks
           << std::setw(15) << tpl
           << std::setw(15) << tpu
           << std::setw(15) << cost
           << std::setw(15) << tpl/n
           << std::setw(15) << tpu/n
           << std::setw(15) << cost/n << '\n';
}
}
}

int main(int argc, char* argv[])
{

    int     n          = 1000;
    int     delta      = 100;
    int     T          = 20;
    bool    csv        = false;
    double  epsilon    = 2.0;
    double  followMult = 1.0;


    if (argc == 2) {
        std::ifstream in(argv[1]);
        if (!in) { std::cerr << "Cannot open config file " << argv[1] << '\n'; return 1; }
        json cfg; in >> cfg;
        if (cfg.contains("n"))          n          = cfg["n"];
        if (cfg.contains("delta"))      delta      = cfg["delta"];
        if (cfg.contains("T"))          T          = cfg["T"];
        if (cfg.contains("csv"))        csv        = cfg["csv"];
        if (cfg.contains("epsilon"))    epsilon    = cfg["epsilon"];
        if (cfg.contains("followMult")) followMult = cfg["followMult"];
    }

    runExperiment(n, delta, T, csv, followMult, epsilon);
    return 0;
}