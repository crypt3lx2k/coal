#include <coal/core/implementation.h>

#include <coal/lang/AbstractError.h>
#include <coal/core/classes/subclass.h>

ExceptionDefinitionTemplate(coal_lang_AbstractMethodError,
			    LIBRARY_STR ".lang.AbstractMethodError",
			    coal_lang_AbstractError());
