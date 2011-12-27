#include <coal/core/implementation.h>

#include <coal/lang/Error.h>
#include <coal/core/classes/subclass.h>

ExceptionDefinitionTemplate(lang,
			    LIBRARY_STR ".lang.OutOfMemoryError",
			    OutOfMemoryError,
			    lang(Error))
