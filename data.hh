#include <stddef.h> // size_t
#include <assert.h> // assert

#ifdef _NO_LIBCPP

#include <stdlib.h>

auto operator new(size_t n) -> void* {
	return malloc (n);
}

auto operator new[](size_t n) -> void* {
	return malloc (n);
}

auto operator delete(void* ptr) -> void {
	free (ptr);
}

auto operator delete(void* ptr, size_t n) -> void {
	(void) n;
	free (ptr);
}

auto operator delete[](void* ptr) -> void {
	free (ptr);
}

auto operator delete[](void* ptr, size_t n) -> void {
	(void) n;
	free (ptr);
}

#endif

namespace eq {

#include "data/pointer.hh"
#include "data/optional.hh"
#include "data/array.hh"
#include "data/vector.hh"
#include "data/list.hh"
#include "data/string.hh"

#include "data/pointer.cc"
#include "data/optional.cc"
#include "data/array.cc"
#include "data/vector.cc"
#include "data/list.cc"
#include "data/string.cc"

}
