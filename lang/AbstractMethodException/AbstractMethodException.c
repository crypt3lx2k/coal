#include <coal/core/implementation.h>

#include <coal/lang/Exception.h>
#include <coal/core/classes/subclass.h>

ExceptionDefinitionTemplate(coal_lang_AbstractMethodException,
			    LIBRARY_STR ".lang.AbstractMethodException",
			    coal_lang_Exception());
