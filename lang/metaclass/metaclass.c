#include <string.h>

#include <coal/core/implementation.h>
#include <coal/lang/NullPointerException.h>

intptr_t coal_lang_cmp (const var self, const var other) {
  const class(metaclass) * s_class;
  const class(metaclass) * o_class;

  /* identically the same */
  if (self == other)
    return 0;

  s_class = coal_lang_getClass(self);
  o_class = coal_lang_getClass(other);

  /* self instance of other's class? */
  if (coal_instanceof(self, o_class))
    return o_class->cmp(self, other);
  /* other instance of self's class? */
  else if (coal_instanceof(other, s_class))
    return s_class->cmp(self, other);
  /* completely different types,
     we compare the class names
     as done in Python. */
  else
    return strcmp(s_class->name, o_class->name);
}

var coal_lang_constructor (var self, va_list * app) {
  ClassCallTemplate(constructor, metaclass, self, app);
}

var coal_lang_destructor (var self) {
  ClassCallTemplate(destructor, metaclass, self);
}

bool coal_lang_equals (const var self, const var other) {
  const class(metaclass) * s_class;
  const class(metaclass) * o_class;

  /* identically the same */
  if (self == other)
    return true;

  s_class = coal_lang_getClass(self);
  o_class = coal_lang_getClass(other);

  /* self instance of other's class */
  if (coal_instanceof(self, o_class))
    return o_class->equals(self, other);
  /* other instance of self's class */
  else if (coal_instanceof(other, s_class))
    return s_class->equals(self, other);
  /* completely different types,
     can't be equal */
  else
    return false;
}

const var coal_lang_getClass (const var _self) {
  const class(object) * self = _self;

  if (self == NULL)
    coal_throw(coal_new(coal_lang_NullPointerException(),
			"coal_lang_getClass: null object"));

  if (self->class == NULL)
    coal_throw(coal_new(coal_lang_NullPointerException(),
			"coal_lang_getClass: null class description"));

  return self->class;
}

size_t coal_lang_getSize (const var self) {
  const class(metaclass) * class = coal_lang_getClass(self);

  return class->size;
}

intptr_t coal_lang_hashCode (const var self) {
  ClassCallTemplate(hashCode, metaclass, self);
}

var coal_lang_toString (const var self) {
  ClassCallTemplate(toString, metaclass, self);
}

/* The extern const var metaclass is instantiated
   in lang/object/object.c due to interdependency
   between object and metaclass */
