#!/bin/sh

CFLAGS="-std=c++17 -Wall -Wextra -Wshadow -pedantic"

c++ $CFLAGS examples.cc -g
