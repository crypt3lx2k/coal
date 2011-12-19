#include <string.h> /* memcpy */
#include <stddef.h> /* offsetof */
#include <coal/implementation.h>

int object_cmp (const var self, const var other) {
  return (int) self - (int) other;
}

var object_constructor (var self, va_list * app __attribute__ ((unused))) {
  return self;
}

var object_destructor (var self) {
  return self;
}

bool object_equals (const var self, const var other) {
  return self == other;
}

int object_hashCode (const var self) {
  return (int) self;
}

var object_toString (const var self __attribute__ ((unused))) {
  /* TODO: make a string class */
  return null;
}

var metaclass_constructor (var _self, va_list * app) {
  struct metaclass_t * self = _self;
  size_t offset = offsetof(struct metaclass_t, cmp);

  memcpy((char *) self + offset,
	 (char *) self->super + offset,
	 lang(getSize)(self->super) - offset);

  OverrideMethod(self, cmp);
  OverrideMethod(self, constructor);
  OverrideMethod(self, destructor);
  OverrideMethod(self, equals);
  OverrideMethod(self, hashCode);
  OverrideMethod(self, toString);

  return _self;
}

var metaclass_destructor (var self __attribute__ ((unused))) {
  /* we make sure that a class description
     isn't deallocated */
  /* I consider this a hack, I might change
     it so that the reference count of a
     class description is the amount of instances */
  return null;
}

/* we instansiate both of these at the same
   place since metaclass extends object,
   while objects class description is
   metaclass */

#define __metaclass (_objs + 1)
#define __object    (_objs)

static const metaclass_t _objs [] = {
  {
    {
      __metaclass,
      1
    },
    _LIBRARY_STR ".lang.object",
    __object,
    sizeof(struct object_t),
    object_cmp,
    object_constructor,
    object_destructor,
    object_equals,
    object_hashCode,
    object_toString
  },
  {
    {
      __metaclass,
      1
    },
    _LIBRARY_STR ".lang.metaclass",
    __object,
    sizeof(struct metaclass_t),
    object_cmp,
    metaclass_constructor,
    metaclass_destructor,
    object_equals,
    object_hashCode,
    object_toString
  }
};

const var lang(object)    = __object;
const var lang(metaclass) = __metaclass;

#undef __object
#undef __metaclass
