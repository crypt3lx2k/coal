#include <coal/core/implementation.h>

#include <coal/lang/Error.h>
#include <coal/core/classes/subclass.h>

ExceptionDefinitionTemplate(coal_lang_AbstractInstantiationError,
			    LIBRARY_STR ".lang.AbstractInstantiationError",
			    coal_lang_Error())
