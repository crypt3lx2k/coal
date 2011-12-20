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
  const class(metaclass) * class = lang(getClass)(self);

  return lib(new)(lang(string)(), "%s@%x",
		  class->name,
		  lang(hashCode)(self));
}

var metaclass_constructor (var _self, va_list * app) {
  class(metaclass) * self = _self;
  size_t offset = offsetof(class(metaclass), cmp);

  self->name  = va_arg(*app, char *);
  self->super = va_arg(*app, class(metaclass) *);
  self->size  = va_arg(*app, size_t);

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

#define _metaclass (_objs + 1)
#define _object    (_objs)

static const class(metaclass) _objs [] = {
  {
    {
      _metaclass,
      1
    },
    LIBRARY_STR ".lang.object",
    _object,
    sizeof(class(object)),
    object_cmp,
    object_constructor,
    object_destructor,
    object_equals,
    object_hashCode,
    object_toString
  },
  {
    {
      _metaclass,
      1
    },
    LIBRARY_STR ".lang.metaclass",
    _object,
    sizeof(class(metaclass)),
    object_cmp,
    metaclass_constructor,
    metaclass_destructor,
    object_equals,
    object_hashCode,
    object_toString
  }
};

const var lang(object) (void) {
  return _object;
}

const var lang(metaclass) (void) {
  return _metaclass;
}

#undef _object
#undef _metaclass
