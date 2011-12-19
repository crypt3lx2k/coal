#include <stdlib.h>
#include <coal/implementation.h>

var lib(acquire) (var object) {
  INCREMENT_REFERENCE_COUNT(object);

  return object;
}

void lib(del) (var object) {
  DECREMENT_REFERENCE_COUNT(object);

  if (IS_GARBAGE(object))
    free(lang(destructor)(object));
}

var lib(new) (const var _class, ...) {
  const metaclass_t * class = _class;
  object_t          * object;
  va_list             ap;

  object = lib(malloc)(class->size);
  object->class = class;

  va_start(ap, _class);
  object = lang(constructor)(object, &ap);
  va_end(ap);

  return lib(acquire(object));
}
