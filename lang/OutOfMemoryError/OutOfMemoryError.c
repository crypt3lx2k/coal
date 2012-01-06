#include <coal/core/implementation.h>

#include <coal/lang/Error.h>
#include <coal/core/classes/subclass.h>

ExceptionDefinitionTemplate(coal_lang_OutOfMemoryError,
			    LIBRARY_STR ".lang.OutOfMemoryError",
			    coal_lang_Error())
