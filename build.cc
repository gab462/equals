#include "data.hh"
#include "build.hh"
#include "arguments.hh"

auto
main (int argc, char** argv) -> int {
  eq::argument_parser args;

  auto& type = args.string_option ('t', "build");

  args.parse (argc, argv);

  if (type == "build") {
    eq::build_config build {"examples.cc"};

    build.run ();
  }

  if (type == "self") {
    eq::build_config build {"build.cc"};

    build.flags.append ("-o");
    build.flags.append ("build");

    build.run ();
  }

  if (type == "check")
    eq::command {
      "cppcheck", "examples.cc", "--enable=all",
      "--suppress=noExplicitConstructor",
      "--suppress=useStlAlgorithm",
      "--suppress=missingIncludeSystem"
    }.execute ();

  if (type == "valgrind")
    eq::command {"valgrind", "./a.out", "one,two", "-o", "three"}.execute ();

  return 0;
}
