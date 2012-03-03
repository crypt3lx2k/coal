#include <coal/core/implementation.h>

#include <coal/lang/Error.h>
#include <coal/core/classes/subclass.h>

ExceptionDefinitionTemplate(coal_lang_NoSuchMethodError,
			    LIBRARY_STR ".lang.NoSuchMethodError",
			    coal_lang_Error())
