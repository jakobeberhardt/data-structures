#!/usr/bin/env bash
set -e
make
# forward every CLI param to the benchmark binary
perf stat -r 5 -e cache-references,cache-misses \
          ./bst-bench "$@"
