#include <stddef.h> // size_t
#include <assert.h> // assert

#ifdef NO_LIBCPP

#include <stdlib.h>

auto
operator new (size_t n) -> void* {
	return malloc (n);
}

auto
operator new[] (size_t n) -> void* {
	return malloc (n);
}

auto
operator delete (void* ptr) -> void {
	free (ptr);
}

auto
operator delete (void* ptr, size_t n) -> void {
	(void) n;
	free (ptr);
}

auto
operator delete[] (void* ptr) -> void {
	free (ptr);
}

auto
operator delete[] (void* ptr, size_t n) -> void {
	(void) n;
	free (ptr);
}

#endif

namespace eq {

#include "data/ptr.hh"
#include "data/opt.hh"
#include "data/arr.hh"
#include "data/vec.hh"
#include "data/lst.hh"
#include "data/str.hh"

#include "data/ptr.cc"
#include "data/opt.cc"
#include "data/arr.cc"
#include "data/vec.cc"
#include "data/lst.cc"
#include "data/str.cc"

}
