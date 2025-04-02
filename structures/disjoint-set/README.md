# Disjoin Set (or Union Find)

## Problem 
Keep a family of disjoint sets under the following operations:

### Create
make-set(x): Create a set with element x. x will also be the represent of this set

### Find
find(x): Finds all sets which include x and return their represent

### Union
union(M1, M2): Union the two sets M1, M2 and return a represent for M1 U M2 


## Canonical Element
Set M is represented my its canonical element e

## Versions
The Quick Union algorithm without path compression is essentially the trivial or basic version of the disjoint set (union–find) data structure. In this implementation, each set is represented as a tree where each element points to its parent, and the root of the tree serves as the representative. Without path compression, the find operation simply follows parent pointers, which can result in tall trees and slower performance over time. Optimizations like path compression and union by rank/size are added later to improve efficiency.