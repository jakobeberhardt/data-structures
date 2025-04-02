#include <unordered_map>
#include "DisjointSet.h"  // Assuming the abstract class is defined in this header.

class TrivialDisjointSet : public DisjointSet {
private:
    // Map element to parent, if parent[x] == x, x is the representative.
    std::unordered_map<int, int> parent;
    
public:
    void makeSet(int x) override {
        // If x isn't already present, initialize it as its own parent.
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
        }
    }
    

    int find(int x) override {
        // Ensure x exists in the set.
        if (parent.find(x) == parent.end()) {
            makeSet(x);
        }
        
        while (parent[x] != x) {
            x = parent[x];
        }
        return x;
    }
    
    // Merge the sets containing x and y.
    void unionSets(int x, int y) override {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }
};
