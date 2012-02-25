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

var coal_lang_string_concat (var self, const var other) {
  const class(string_metaclass) * class;

  CheckAndThrowMissingMethodException("coal_lang_string_concat", self, coal_lang_string());
  CheckAndThrowMissingMethodException("coal_lang_string_concat", other, coal_lang_string());

  class = coal_lang_getClass(self);

  return class->concat(self, other);
}

/* string_class class description */
SETUP_CLASS_DESCRIPTION(coal_lang_string_metaclass,
			coal_lang_metaclass(),
			LIBRARY_STR ".lang.string.class",
			coal_lang_iterable(),
			sizeof(class(string_metaclass)),
			INHERIT_METHOD,
			string_metaclass_constructor,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD);
