#include "data.hh"
#include "args.hh"
#include "print.hh"

auto
main (int argc, char** argv) -> int {
  core::arg_parser args;

  auto& input = args.input ();
  auto& h = args.flag ('h');
  auto& c = args.int_option ('c', 10);
  auto& so = args.string_option ('o');

  args.parse (argc, argv);

  core::println ("input:", input);
  core::println ("-h:", h);
  core::println ("-c:", c);
  core::println ("-o:", so);

  core::println ();

  core::str s = "Hello, ";

  core::str s2 = s.append ("World!");

  core::println (s2, s2.length);

  core::println ();

  core::println ("equal:", s2 == input);
  core::println ("contains:", s2.contains (input));

  core::println ();

  for (auto s3: input.split (','))
    core::println ("split:", s3.trim ());

  core::println ();

  core::lst<int> l;

  l.append (0);
  l.append (1);
  l.append (2);

  l.remove (1);
  l.insert (1, 1);

  for (auto& e: l) {
    core::println ("l:", e);
  }

  core::println ();

  core::vec<int> v {0, 1, 2};

  for (auto& e: v) {
    core::println ("v:", e);
  }

  core::println ();

  core::arr<int, 3> a {0, 1, 2};

  for (auto& e: a) {
    core::println ("a:", e);
  }

  core::println ();

  core::ptr<int> i {3};

  core::println ("i:", *i);

  core::opt<int> o = 4;

  core::println ("o:", *o);
}
