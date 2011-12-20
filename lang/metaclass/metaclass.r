#ifndef COAL_LANG_METACLASS_R__
#define COAL_LANG_METACLASS_R__

#include <coal/implementation.h>
#include <coal/lang/object/object.r>

class (metaclass) {
  extends(object);

  const char * name;
  const class(metaclass) * super;
  size_t size;

  int (*cmp)(const var self, const var other);
  var (*constructor)(var self, va_list * app);
  var (*destructor)(var self);
  bool (*equals)(const var self, const var other);
  int (*hashCode)(const var self);
  var (*toString)(const var self);
};

#endif /* COAL_LANG_METACLASS_R__ */
