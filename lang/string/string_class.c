#include <coal/core/implementation.h>
#include <coal/lang/string/string_class.rep>

var string_class_constructor (var _self, va_list * app) {
  class(string_class)    * self  = _self;
  const class(metaclass) * class = string_class();

  class->super->constructor(_self, app);

  OverrideMethod(self, concat);

  return _self;
}

const char * lang_string(chars) (const var _self) {
  const class(string) * self = _self;

  return self->str;
}

size_t lang_string(length) (const var _self) {
  const class(string) * self = _self;

  return self->len;
}

var lang_string(concat) (const var self, const var other) {
  ClassCallTemplate(concat, string_class, self, other);
}

/* string_class class description */

static const var string_class__ = NULL;

const var string_class (void) {
  return string_class__ ? string_class__ :
    (string_class__ = lib(new)(lang(metaclass)(),
			       LIBRARY_STR ".lang.string_class",
			       lang(metaclass)(),
			       sizeof(class(string_class)),
			       INHERIT_METHOD,
			       string_class_constructor,
			       INHERIT_METHOD,
			       INHERIT_METHOD,
			       INHERIT_METHOD,
			       INHERIT_METHOD));
}
