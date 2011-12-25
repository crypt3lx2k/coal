#include <stdlib.h>
#include <setjmp.h>

#include <coal/implementation.h>
#include <coal/io/io.h>

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

bool lib(instanceof) (const var object, const var class) {
  const class(metaclass) * current = lang(getClass)(object);

  if (current == class)
    return true;

  do {
    current = current->super;

    if (current == class)
      return true;
  } while (current != lang(object)());

  return false;
}

void lib(throw) (const var throwable) {
  if (utility_stack_is_empty(&exceptions_s__)) {
    fputs("unhandled exception ", stderr);
    io(fprintln)(throwable, stderr);

    exit(EXIT_FAILURE);
  } else {
    longjmp(utility_stack_peek(&exceptions_s__),
	    (int) throwable);
  }
}
