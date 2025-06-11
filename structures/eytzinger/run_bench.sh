#!/bin/bash

make

IMPLS=("BST_VEB" "BST_EYT" "BST_EYT_PREF")    

for impl in "${IMPLS[@]}"; do
  ./bst-bench "$1" "$impl"
  echo
   
  echo
done
