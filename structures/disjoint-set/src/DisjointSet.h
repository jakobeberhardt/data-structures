#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

class DisjointSet {
public:
    virtual ~DisjointSet() {}

    virtual void makeSet(int x) = 0;
    
    virtual int find(int x) = 0;
    
    virtual void unionSets(int x, int y) = 0;
};

#endif // DISJOINT_SET_H
