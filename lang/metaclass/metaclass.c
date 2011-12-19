#include <coal/implementation.h>

int lang(cmp) (const var self, const var other) {
  ClassCallTemplate(cmp, self, other);
}

var lang(constructor) (var self, va_list * app) {
  ClassCallTemplate(constructor, self, app);
}

var lang(destructor) (var self) {
  ClassCallTemplate(destructor, self);
}

bool lang(equals) (const var self, const var other) {
  ClassCallTemplate(equals, self, other);
}

const var lang(getClass) (const var _self) {
  const object_t * self = _self;

  return self->class;
}

size_t lang(getSize) (const var self) {
  const metaclass_t * class = lang(getClass)(self);

  return class->size;
}

int lang(hashCode) (const var self) {
  ClassCallTemplate(hashCode, self);
}

var lang(toString) (const var self) {
  ClassCallTemplate(toString, self);
}

/* The extern const var metaclass is instansiated
   in lang/object/object.c due to interdependency
   between object and metaclass */
