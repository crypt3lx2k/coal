#include <coal/core/implementation.h>

#include <coal/lang/Exception.h>
#include <coal/core/classes/subclass.h>

ExceptionDefinitionTemplate(lang,
			    LIBRARY_STR ".lang.NullPointerException",
			    NullPointerException,
			    lang(Exception))
