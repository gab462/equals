#include "data.hh"
#include "arguments.hh"
#include "print.hh"

auto
main (int argc, char** argv) -> int {
  eq::argument_parser args;

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

  eq::string s = "Hello, ";

  eq::string s2 = s.append ("World!");

  eq::println (s2, s2.length);

  eq::println ();

  eq::println ("equal:", s2 == input);
  eq::println ("contains:", s2.contains (input));

  eq::println ();

  for (auto s3: input.split (','))
    eq::println ("split:", s3.trim ());

  eq::list<int> l;

  l.append (0);
  l.append (1);
  l.append (2);

  l.remove (1);
  l.insert (1, 1);

  for (auto& e: l) {
    eq::println ("l:", e);
  }

  eq::println ();

  eq::vector<int> v {3};

  v[0] = 0;
  v[1] = 1;
  v[2] = 2;

  for (auto& e: v) {
    eq::println ("v:", e);
  }

  eq::println ();

  eq::array<int, 3> a = {0, 1, 2};

  for (auto& e: a) {
    eq::println ("a:", e);
  }

  eq::println ();

  eq::pointer<int> i {3};

  eq::println ("i:", *i);

  eq::optional<int> o = 4;

  eq::println ("o:", *o);
}
