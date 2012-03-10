#include <stddef.h> /* offsetof */
#include <stdint.h> /* intptr_t */
#include <string.h> /* memcpy */
#include <coal/core/implementation.h>

int object_cmp (const var self, const var other) {
  return (intptr_t) self - (intptr_t) other;
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
  return (intptr_t) self;
}

var object_toString (const var self) {
  const class(metaclass) * class = coal_lang_getClass(self);

  return coal_new(coal_lang_string(), "%s@%x",
		  class->name,
		  coal_lang_hashCode(self));
}

var metaclass_constructor (var _self, va_list * app) {
  class(metaclass) * self = _self;
  size_t offset = offsetof(class(metaclass), cmp);

  self->name  = va_arg(*app, char *);
  self->super = va_arg(*app, class(metaclass) *);
  self->size  = va_arg(*app, size_t);

  memcpy((char *) self + offset,
	 (char *) self->super + offset,
	 coal_lang_getSize(self->super) - offset);

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
  return NULL;
}

var metaclass_toString (const var _self) {
  const class(metaclass) * self = _self;

  return coal_new(coal_lang_string(),
		  "class %s",
		  self->name);
}

/* we instantiate both of these at the same
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
    metaclass_toString
  }
};

const var coal_lang_object (void) {
  return _object;
}

const var coal_lang_metaclass (void) {
  return _metaclass;
}

#undef _object
#undef _metaclass
