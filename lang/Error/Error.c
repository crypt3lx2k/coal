#include <coal/core/implementation.h>

#include <coal/lang/throwable.h>
#include <coal/core/classes/subclass.h>

ExceptionDefinitionTemplate(coal_lang_Error,
			    LIBRARY_STR ".lang.Error",
			    coal_lang_throwable())
