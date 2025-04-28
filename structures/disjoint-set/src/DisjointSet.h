#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

#include <cstddef>


class DisjointSet {
public:
    virtual ~DisjointSet() = default;

    virtual void makeSet(int x)                       = 0;
    virtual int  find(int x)                          = 0;
    virtual void unionSets(int x, int y)              = 0;

    virtual int  getParent(int x)               const = 0;
    virtual int  countSets()                    const = 0;
    virtual int  depth(int x)                   const = 0;
    virtual long pointerUpdatesDuringFind(int x)const = 0;
};

#endif // DISJOINT_SET_H
