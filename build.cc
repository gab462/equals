#include "data.hh"
#include "build.hh"

// cppcheck examples.cc --enable=all --suppress=noExplicitConstructor  --suppress=useStlAlgorithm --suppress=missingIncludeSystem
// valgrind ./a.out one,two -o three

auto
main () -> int {
  eq::build_config build {"examples.cc"};

  build.run();

  return 0;
}
