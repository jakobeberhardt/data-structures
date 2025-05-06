#ifndef UNION_FIND_H
#define UNION_FIND_H

#include "DisjointSet.h"

template<class U, class F>
class UnionFind : public DisjointSet
{
public:
    explicit UnionFind(int n)
        : parent_(n), size_(n,1), rank_(n,0)
    { for (int i=0;i<n;++i) parent_[i]=i; }

    void makeSet(int x) override {
        if (x >= (int)parent_.size()) {
            int old = parent_.size();
            parent_.resize(x+1);
            size_.resize(x+1,1);
            rank_.resize(x+1,0);
            for (int i=old;i<=x;++i) parent_[i]=i;
        } else {
            parent_[x]=x; size_[x]=1; rank_[x]=0;
        }
    }

    int find(int x) override {
        long upd=0;
        return F::find(x,parent_,upd);
    }

    void unionSets(int a,int b) override {
        int r1=find(a), r2=find(b);
        if (r1==r2) return;
        U::unite(r1,r2,parent_,size_,rank_);
    }

    int  getParent(int x) const override { return parent_[x]; }
    int  countSets()        const override {
        int c=0; for (size_t i=0;i<parent_.size();++i) if (parent_[i]==(int)i) ++c; return c;
    }
    int  depth(int x) const override {
        int d=0; while (x!=parent_[x]){x=parent_[x];++d;} return d;
    }
    long pointerUpdatesDuringFind(int x) const override {
        return F::updatesGivenDepth(depth(x));
    }

    static double followMultiplier() { return F::followMult(); }

private:
    std::vector<int> parent_, size_, rank_;
};

#endif
