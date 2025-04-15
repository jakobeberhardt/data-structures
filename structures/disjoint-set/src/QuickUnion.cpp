#include <vector>
#include "DisjointSet.h"

class QuickUnion : public DisjointSet {
public:
    QuickUnion(int n) : parent(n, -1), n_(n) {
        for (int i = 0; i < n; ++i) {
            makeSet(i);
        }
    }

    void makeSet(int x) override {
        if (x >= static_cast<int>(parent.size())) {
            parent.resize(x + 1, -1);
        }
        parent[x] = x;
    }
    
    int find(int x) override {
        // (Naive find without path compression)
        while (x != parent[x]) {
            x = parent[x];
        }
        return x;
    }
    
    void unionSets(int x, int y) override {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;
        parent[rootX] = rootY;
    }
    
    int getParent(int x) const override {
        return parent[x];
    }
    
    int countSets() const override {
        int count = 0;
        for (int i = 0; i < n_; i++) {
            if (parent[i] == i) ++count;
        }
        return count;
    }

private:
    std::vector<int> parent;
    int n_;
};
