#include <coal/core/implementation.h>
#include <coal/lang/AbstractMethodError.h>

void coal_core_abstract_method () {
  coal_throw(coal_new(coal_lang_AbstractMethodError(),
		      "a call was made to an abstract method."));
}
