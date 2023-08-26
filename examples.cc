#include "eq.hh"

#include <cstdio>

auto
main () -> int {
  eq::list<int> l;

  l.append (0);
  l.append (1);
  l.append (2);

  l.remove (1);
  l.insert (1, 1);

  for (auto& e: l) {
    printf ("l: %d\n", e);
  }

  printf ("\n");

  eq::vector<int> v {3};

  v[0] = 0;
  v[1] = 1;
  v[2] = 2;

  for (auto& e: v) {
    printf ("v: %d\n", e);
  }

  printf ("\n");

  eq::array<int, 3> a = {0, 1, 2};

  for (auto& e: a) {
    printf ("a: %d\n", e);
  }

  printf ("\n");

  eq::pointer<int> i {3};

  printf ("i: %d\n", *i);

  printf ("\n");

  eq::optional<int> o = 4;

  printf ("o: %d\n", *o);
}
