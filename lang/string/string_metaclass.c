#include <coal/core/implementation.h>
#include <coal/lang/string/string_metaclass.rep>

var string_metaclass_constructor (var _self, va_list * app) {
  class(string_metaclass) * self  = _self;
  const class(metaclass)  * class = lang(string_metaclass)();

  class->super->constructor(_self, app);

  OverrideMethod(self, concat);

  return _self;
}

const char * lang(string_chars) (const var _self) {
  const class(string) * self = _self;

  CheckAndThrowMissingMethodException("lang(string_chars)", _self, lang(string)());

  return self->str;
}

size_t lang(string_length) (const var _self) {
  const class(string) * self = _self;

  CheckAndThrowMissingMethodException("lang(string_length)", _self, lang(string)());

  return self->len;
}

var lang(string_concat) (const var self, const var other) {
  const class(string_metaclass) * s_class;
  const class(string_metaclass) * o_class;

  CheckAndThrowMissingMethodException("lang(string_concat)", self, lang(string)());
  CheckAndThrowMissingMethodException("lang(string_concat)", other, lang(string)());

  s_class = lang(getClass)(self);
  o_class = lang(getClass)(other);

  if (lib(instanceof)(self, o_class))
    return o_class->concat(self, other);
  else
    return s_class->concat(self, other);
}

/* string_class class description */

static const var string_metaclass__ = NULL;

const var lang(string_metaclass) (void) {
  return string_metaclass__ != NULL ? string_metaclass__ :
    (string_metaclass__ = lib(new)(lang(metaclass)(),
				   LIBRARY_STR ".lang.string_class",
				   lang(metaclass)(),
				   sizeof(class(string_metaclass)),
				   INHERIT_METHOD,
				   string_metaclass_constructor,
				   INHERIT_METHOD,
				   INHERIT_METHOD,
				   INHERIT_METHOD,
				   INHERIT_METHOD));
}
