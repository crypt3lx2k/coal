#include <stdlib.h>
#include <coal/implementation.h>

void * lib(malloc) (size_t size) {
  return malloc(size);
}
