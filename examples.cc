#include "data.hh"
#include "args.hh"
#include "print.hh"

auto
main (int argc, char** argv) -> int {
  eq::arg_parser args;

  auto& input = args.input ();
  auto& h = args.flag ('h');
  auto& c = args.int_option ('c', 10);
  auto& so = args.string_option ('o');

  args.parse (argc, argv);

  eq::println ("input:", input);
  eq::println ("-h:", h);
  eq::println ("-c:", c);
  eq::println ("-o:", so);

  eq::println ();

  eq::str s = "Hello, ";

  eq::str s2 = s.append ("World!");

  eq::println (s2, s2.length);

  eq::println ();

  eq::println ("equal:", s2 == input);
  eq::println ("contains:", s2.contains (input));

  eq::println ();

  for (auto s3: input.split (','))
    eq::println ("split:", s3.trim ());

  eq::println ();

  eq::lst<int> l;

  l.append (0);
  l.append (1);
  l.append (2);

  l.remove (1);
  l.insert (1, 1);

  for (auto& e: l) {
    eq::println ("l:", e);
  }

  eq::println ();

  eq::vec<int> v {0, 1, 2};

  for (auto& e: v) {
    eq::println ("v:", e);
  }

  eq::println ();

  eq::arr<int, 3> a {0, 1, 2};

  for (auto& e: a) {
    eq::println ("a:", e);
  }

  eq::println ();

  eq::ptr<int> i {3};

  eq::println ("i:", *i);

  eq::opt<int> o = 4;

  eq::println ("o:", *o);
}
