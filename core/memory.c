#include <stdlib.h>
#include <coal/core/implementation.h>

void * core(malloc) (size_t size) {
  return malloc(size);
}
