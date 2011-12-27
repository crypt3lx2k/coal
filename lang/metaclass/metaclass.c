#include <string.h>

#include <coal/core/implementation.h>
#include <coal/lang/NullPointerException.h>

int lang(cmp) (const var self, const var other) {
  const class(metaclass) * s_class;
  const class(metaclass) * o_class;

  /* identically the same */
  if (self == other)
    return 0;

  s_class = lang(getClass)(self);
  o_class = lang(getClass)(other);

  /* self instance of other's class? */
  if (lib(instanceof)(self, o_class))
    return o_class->cmp(self, other);
  /* other instance of self's class? */
  else if (lib(instanceof)(other, s_class))
    return s_class->cmp(self, other);
  /* completely different types,
     we compare the class names
     as done in Python. */
  else
    return strcmp(s_class->name, o_class->name);
}

var lang(constructor) (var self, va_list * app) {
  ClassCallTemplate(constructor, self, app);
}

var lang(destructor) (var self) {
  ClassCallTemplate(destructor, self);
}

bool lang(equals) (const var self, const var other) {
  const class(metaclass) * s_class;
  const class(metaclass) * o_class;

  /* identically the same */
  if (self == other)
    return true;

  s_class = lang(getClass)(self);
  o_class = lang(getClass)(other);

  /* self instance of other's class */
  if (lib(instanceof)(self, o_class))
    return o_class->cmp(self, other);
  /* other instance of self's class */
  else if (lib(instanceof)(other, s_class))
    return s_class->cmp(self, other);
  /* completely different types,
     can't be equal */
  else
    return false;
}

const var lang(getClass) (const var _self) {
  const class(object) * self = _self;

  if (self == NULL)
    lib(throw)(lib(new)(lang(NullPointerException)(),
			"lang(getClass): null object"));

  if (self->class == NULL)
    lib(throw)(lib(new)(lang(NullPointerException)(),
			"lang(getClass): null class description"));

  return self->class;
}

size_t lang(getSize) (const var self) {
  const class(metaclass) * class = lang(getClass)(self);

  return class->size;
}

int lang(hashCode) (const var self) {
  ClassCallTemplate(hashCode, self);
}

var lang(toString) (const var self) {
  ClassCallTemplate(toString, self);
}

/* The extern const var metaclass is instantiated
   in lang/object/object.c due to interdependency
   between object and metaclass */
