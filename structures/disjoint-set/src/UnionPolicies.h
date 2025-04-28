#ifndef UNION_POLICIES_H
#define UNION_POLICIES_H

#include <vector>

struct QU {
    static void unite(int r1,int r2,
                      std::vector<int>& parent,
                      std::vector<int>& size,
                      std::vector<int>& rank)
    { parent[r1] = r2; }
};

struct UW {
    static void unite(int r1,int r2,
                      std::vector<int>& parent,
                      std::vector<int>& size,
                      std::vector<int>& rank)
    {
        if (size[r1] < size[r2]) std::swap(r1,r2);
        parent[r2] = r1;
        size[r1]  += size[r2];
    }
};

struct UR {
    static void unite(int r1,int r2,
                      std::vector<int>& parent,
                      std::vector<int>& size,
                      std::vector<int>& rank)
    {
        if (rank[r1] < rank[r2]) std::swap(r1,r2);
        parent[r2] = r1;
        if (rank[r1] == rank[r2]) ++rank[r1];
    }
};
#endif
