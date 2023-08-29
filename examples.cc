#include "equals.hh"

#include <cstdio>

auto
main (int argc, char** argv) -> int {
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

  printf ("i: %d\n\n", *i);

  eq::optional<int> o = 4;

  printf ("o: %d\n\n", *o);

  eq::string s = "Hello, ";

  eq::string s2 = s.append("World!");

  printf ("%s: %zu\n\n", s2.with_null ().data, s2.length);

  eq::argument_parser args;

  auto& input = args.input ();
  auto& h = args.flag ('h');
  auto& c = args.int_option ('c', 10);
  auto& so = args.string_option ('o');

  args.parse (argc, argv);

  printf ("input: %s\n", input.with_null ().data);
  printf ("-h: %d\n", h);
  printf ("-c: %d\n", c);
  printf ("-o: %s\n", so.with_null ().data);

  printf ("\n");

  printf ("equal: %d\n", s2 == input);
  printf ("contains: %d\n", s2.contains(input));

  printf("\n");

  for (auto s3: input.split(','))
    printf("split: %s \n", s3.with_null ().data);

  printf("\n");
}
