#include <coal/core/implementation.h>

#include <coal/lang/Error.h>
#include <coal/core/classes/subclass.h>

ExceptionDefinitionTemplate(coal_lang_AbstractError,
			    LIBRARY_STR ".lang.AbstractError",
			    coal_lang_Error())
