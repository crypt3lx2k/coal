#include <coal/core/implementation.h>

#include <coal/lang/Exception.h>
#include <coal/core/classes/subclass.h>

ExceptionDefinitionTemplate(coal_lang_IllegalStateException,
			    LIBRARY_STR ".lang.IllegalStateException",
			    coal_lang_Exception())
