#include <coal/core/implementation.h>

#include <coal/lang/iterable.h>
#include <coal/lang/string/string_metaclass.rep>

var string_metaclass_constructor (var _self, va_list * app) {
  class(string_metaclass) * self  = _self;
  const class(metaclass)  * class = coal_lang_string_metaclass();

  class->super->constructor(_self, app);

  OverrideMethod(self, concat);
  OverrideMethod(self, join);

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

var coal_lang_string_concat (var self, var other) {
  const class(string_metaclass) * s_class;
  const class(string_metaclass) * o_class;
  var ret;

  CheckAndThrowMissingMethodException("coal_lang_string_concat", self, coal_lang_string());
  CheckAndThrowMissingMethodException("coal_lang_string_concat", other, coal_lang_string());

  s_class = coal_lang_getClass(self);
  o_class = coal_lang_getClass(other);

  if (coal_instanceof(self, o_class))
    ret = o_class->concat(self, other);
  else if (coal_instanceof(other, s_class))
    ret = s_class->concat(self, other);
  else {
    s_class = coal_lang_string();
    ret = s_class->concat(self, other);
  }

  coal_del(other);
  return ret;
}

var coal_lang_string_join (var self, const var iterable) {
  const class(string_metaclass) * class;
  const class(metaclass) * i_class = coal_lang_getClass(iterable);
  var ret;

  CheckAndThrowMissingMethodException("coal_lang_string_join", self, coal_lang_string());
  CheckAndThrowMissingMethodException("coal_lang_string_join", i_class, coal_lang_iterable());

  class = coal_lang_getClass(self);
  ret = class->join(self, iterable);

  coal_del(self);
  return ret;
}

/* string_class class description */
SETUP_CLASS_DESCRIPTION(coal_lang_string_metaclass,
			coal_lang_metaclass(),
			LIBRARY_STR ".lang.string.class",
			coal_lang_metaclass(),
			sizeof(class(string_metaclass)),
			INHERIT_METHOD,
			string_metaclass_constructor,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD);
