#include <stdlib.h>

#include <coal/core/implementation.h>
#include <coal/lang/OutOfMemoryError.h>

void * coal_core_malloc (size_t size) {
  void * block;

  block = malloc(size);

  if (block == NULL) 
    coal_throw(coal_new(coal_lang_OutOfMemoryError(),
			"coal_core_malloc: failed malloc of size %u.",
			size));

  return block;
}
