#ifndef FIND_POLICIES_H
#define FIND_POLICIES_H

#include <vector>

struct NC {
    static int find(int x, std::vector<int>& p, long& upd)
    {
        while (x != p[x]) x = p[x];
        return x;
    }
    static long updatesGivenDepth(int depth) { return 0; }
    static double followMult() { return 1.0; } 
};

struct FC {
    static int find(int x, std::vector<int>& p, long& upd)
    {
        if (p[x] != x) {
            p[x] = find(p[x], p, upd);
            ++upd;
        }
        return p[x];
    }
    static long updatesGivenDepth(int depth) { return depth; }
    static double followMult() { return 2.0; }  
};

struct PS {
    static int find(int x, std::vector<int>& p, long& upd)
    {
        while (p[x] != p[p[x]]) {
            int parent = p[x];
            p[x] = p[parent];
            ++upd;
            x = parent;
        }
        return p[x];
    }
    static long updatesGivenDepth(int depth) { return depth/2; }
    static double followMult() { return 1.0; }
};

struct PH {
    static int find(int x, std::vector<int>& p, long& upd)
    {
        while (p[x] != p[p[x]]) {
            p[x] = p[p[x]];
            ++upd;
            x = p[x];
        }
        return p[x];
    }
    static long updatesGivenDepth(int depth) { return (depth+1)/2; }
    static double followMult() { return 1.0; }
};
#endif
