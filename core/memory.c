#include <stdlib.h>
#include <coal/implementation.h>

void * core(malloc) (size_t size) {
  return malloc(size);
}
