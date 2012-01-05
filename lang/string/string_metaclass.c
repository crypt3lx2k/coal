#include <coal/core/implementation.h>

#include <coal/lang/iterable.h>
#include <coal/lang/string/string_metaclass.rep>

var string_metaclass_constructor (var _self, va_list * app) {
  class(string_metaclass) * self  = _self;
  const class(metaclass)  * class = coal_lang_string_metaclass();

  class->super->constructor(_self, app);

  OverrideMethod(self, concat);

  return _self;
}

const char * coal_lang_string_chars (const var _self) {
  const class(string) * self = _self;

  CheckAndThrowMissingMethodException("coal_lang_string_chars", _self, coal_lang_string());

  return self->str;
}

size_t coal_lang_string_length (const var _self) {
  const class(string) * self = _self;

  CheckAndThrowMissingMethodException("coal_lang_string_length", _self, coal_lang_string());

  return self->len;
}

var coal_lang_string_concat (const var self, const var other) {
  const class(string_metaclass) * s_class;
  const class(string_metaclass) * o_class;

  CheckAndThrowMissingMethodException("coal_lang_string_concat", self, coal_lang_string());
  CheckAndThrowMissingMethodException("coal_lang_string_concat", other, coal_lang_string());

  s_class = coal_lang_getClass(self);
  o_class = coal_lang_getClass(other);

  if (coal_instanceof(self, o_class))
    return o_class->concat(self, other);
  else
    return s_class->concat(self, other);
}

/* string_class class description */

static const var string_metaclass__ = NULL;

const var coal_lang_string_metaclass (void) {
  return string_metaclass__ != NULL ? string_metaclass__ :
    (string_metaclass__ = coal_new(coal_lang_metaclass(),
				   LIBRARY_STR ".lang.string.class",
				   coal_lang_iterable(),
				   sizeof(class(string_metaclass)),
				   INHERIT_METHOD,
				   string_metaclass_constructor,
				   INHERIT_METHOD,
				   INHERIT_METHOD,
				   INHERIT_METHOD,
				   INHERIT_METHOD));
}
