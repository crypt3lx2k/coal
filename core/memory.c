#include <stdlib.h>

#include <coal/core/implementation.h>
#include <coal/lang/OutOfMemoryError.h>

void * core(malloc) (size_t size) {
  void * block;

  block = malloc(size);

  if (block == NULL) 
    lib(throw)(lib(new)(lang(OutOfMemoryError)(),
			"core(malloc): failed malloc of size %u.",
			size));

  return block;
}
