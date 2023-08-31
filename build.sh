#!/bin/sh

CFLAGS="-std=c++17 -Wall -Wextra -Wshadow -pedantic"

c++ $CFLAGS examples.cc -g

# cppcheck examples.cc --enable=all --suppress=noExplicitConstructor  --suppress=useStlAlgorithm --suppress=missingIncludeSystem
# valgrind ./a.out one,two -o three
