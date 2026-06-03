#!/usr/bin/env bash
# Usage: ./run.sh path/to/file.cpp
set -e

# Compile to a quick binary named 'a.out' and run it right away if successful
g++-15 -std=c++23 -O2 "$1" && ./a.out

# Clean up the binary immediately after it finishes running
rm -f ./a.out