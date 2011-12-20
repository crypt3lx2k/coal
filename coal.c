#include <stdlib.h>
#include <coal/implementation.h>

var lib(acquire) (var object) {
  return INCREMENT_REFERENCE_COUNT(object);
}

void lib(del) (var object) {
  DECREMENT_REFERENCE_COUNT(object);

  if (IS_GARBAGE(object))
    free(lang(destructor)(object));
}

var lib(new) (const var _class, ...) {
  const class(metaclass) * class = _class;
  class(object) * object;
  va_list ap;

  object = core(malloc)(class->size);
  object->class = class;

  va_start(ap, _class);
  object = lang(constructor)(object, &ap);
  va_end(ap);

  return lib(acquire(object));
}
