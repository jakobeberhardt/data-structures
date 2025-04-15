#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

class DisjointSet {
public:
    virtual ~DisjointSet() {}

    // Initialize element x to be its own set.
    virtual void makeSet(int x) = 0;
    
    // Find the representative of the set containing x.
    // (May or may not compress paths.)
    virtual int find(int x) = 0;
    
    // Merge the sets containing x and y.
    virtual void unionSets(int x, int y) = 0;
    
    // --- Extensions for experimental measurements ---
    
    // Return the parent of x (without performing a full find).
    // For a tree-based implementation, this is simply the parent pointer.
    virtual int getParent(int x) const = 0;
    
    // Count how many disjoint sets remain.
    // (E.g., by counting the number of x such that getParent(x) == x.)
    virtual int countSets() const = 0;
};

#endif // DISJOINT_SET_H
