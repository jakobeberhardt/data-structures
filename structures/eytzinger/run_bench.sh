#!/bin/bash

make

IMPLS=("BST_VEB" "BST_EYT" "BST_EYT_PREF" "BST_EYT_PREF_TWO" "BST_EYT_PREF_THREE" "BST_EYT_PREF_FOUR" "BST_EYT_PREF_PROB")    

for impl in "${IMPLS[@]}"; do
  ./bst-bench "$1" "$impl"
done
