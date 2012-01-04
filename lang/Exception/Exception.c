#include <coal/core/implementation.h>

#include <coal/lang/throwable.h>
#include <coal/core/classes/subclass.h>

ExceptionDefinitionTemplate(coal_lang_Exception,
			    LIBRARY_STR ".lang.Exception",
			    coal_lang_throwable)
