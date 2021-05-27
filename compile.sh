#!/bin/sh
g++ -std=c++20 -Wall -Wextra -Wpedantic -O3 -march=native -fno-exceptions -flto "$@"
