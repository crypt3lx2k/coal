#include <stdlib.h>
#include <coal/errors/OutOfMemoryError.h>

void * coal_private_malloc (size_t size) {
  void * block;

  block = malloc(size);

  if (block == NULL)
    coal_throw(coal_new(coal_errors_OutOfMemoryError(),
			"coal_private_malloc: malloc of %zu bytes failed",
			size));

  return block;
}

void * coal_private_realloc (void * ptr, size_t size) {
  void * block;

  block = realloc(ptr, size);

  if (block == NULL)
    coal_throw(coal_new(coal_errors_OutOfMemoryError(),
			"coal_private_realloc: realloc on %p of %zu bytes failed",
			ptr, size));

  return block;
}
