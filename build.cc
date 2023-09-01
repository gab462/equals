#include "data.hh"
#include "build.hh"

// cppcheck examples.cc --enable=all --suppress=noExplicitConstructor  --suppress=useStlAlgorithm --suppress=missingIncludeSystem
// valgrind ./a.out one,two -o three

auto
main () -> int {
  // eq::command build {"c++", "-std=c++17", "-Wall", "-Wextra", "-pedantic", "examples.cc"};

  eq::build_config build;

  build.set_compiler ("c++");

  build.add_flag ("std=c++17");
  build.add_flag ("Wall");
  build.add_flag ("Wextra");
  build.add_flag ("pedantic");

  build.add_file ("examples.cc");

  build.run();

  return 0;
}
