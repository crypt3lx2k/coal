#include <coal/core/implementation.h>

#include <coal/lang/throwable.h>
#include <coal/core/classes/subclass.h>

ExceptionDefinitionTemplate(lang,
			    LIBRARY_STR ".lang.Exception",
			    Exception,
			    lang(throwable))
