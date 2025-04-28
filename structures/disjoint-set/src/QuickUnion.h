#ifndef QUICK_UNION_H
#define QUICK_UNION_H

#include <vector>
#include "DisjointSet.h"

class QuickUnion : public DisjointSet {
public:
    explicit QuickUnion(int n) : parent_(n)
    { for (int i=0;i<n;++i) parent_[i]=i; }

    void makeSet(int x) override
    {
        if (static_cast<std::size_t>(x) >= parent_.size())
            parent_.resize(static_cast<std::size_t>(x) + 1, x);
        parent_[x] = x;
    }
    int  find(int x)    override { while (x!=parent_[x]) x=parent_[x]; return x; }
    void unionSets(int a,int b)  override {
        int r1=find(a), r2=find(b); if(r1!=r2) parent_[r1]=r2;
    }

    /* ─ instrumentation ─ */
    int  getParent(int x) const override { return parent_[x]; }
    int  countSets()      const override {
        int c=0; for(size_t i=0;i<parent_.size();++i) if(parent_[i]==(int)i) ++c; return c;
    }
    int  depth(int x)     const override {
        int d=0; while(x!=parent_[x]){x=parent_[x];++d;} return d;
    }
    long pointerUpdatesDuringFind(int) const override { return 0; }

private:
    std::vector<int> parent_;
};
#endif
