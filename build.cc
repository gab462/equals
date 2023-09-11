#include "data.hh"
#include "build.hh"
#include "args.hh"

auto
main (int argc, char** argv) -> int {
  core::arg_parser args;

  auto& type = args.string_option ('t', "build");

  args.parse (argc, argv);

  core::build_config build {"examples.cc"};

  build.compiler = "musl-gcc";

  build.flags.append ("-fno-rtti");
  build.flags.append ("-fno-exceptions");
  build.flags.append ("-static");

  build.define ("NO_LIBCPP");

  if (type == "build") {
    build.run ();
  }

  if (type == "self") {
    build.entry = "build.cc";

    build.flags.append ("-o");
    build.flags.append ("bld");

    build.run ();
  }

  if (type == "check")
    core::cmd {
      "cppcheck", "examples.cc", "--enable=all",
      "--suppress=noExplicitConstructor",
      "--suppress=useStlAlgorithm",
      "-I/usr/include/x86_64-linux-musl",
      "-D_DEFAULT_SOURCE"
    }.execute ();

  if (type == "valgrind")
    core::cmd {"valgrind", "./a.out", "one,two", "-o", "three"}.execute ();

  return 0;
}
