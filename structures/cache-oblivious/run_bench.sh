#!/bin/bash

make

IMPLS=("BST_PTR" "BST_VEB")    

for impl in "${IMPLS[@]}"; do
  ./bst-bench "$1" "$impl"
  echo
   
  echo
done
