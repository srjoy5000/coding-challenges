#!/usr/bin/env bash
# Usage: ./run.sh path/to/file.cpp [< input.txt]
set -e
FILE="$1"
BIN=$(mktemp /tmp/sol_XXXXXX)
g++ -std=c++17 -O2 -o "$BIN" "$FILE"
"$BIN"
rm -f "$BIN"
