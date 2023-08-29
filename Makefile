CFLAGS := -std=c++17 -Wall -Wextra -Wshadow -pedantic

a.out: $(wildcard *.cc) $(wildcard *.hh)
	c++ $(CFLAGS) `sdl2-config --cflags` examples.cc `sdl2-config --libs` -o $@ -g
