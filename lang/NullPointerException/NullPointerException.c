#include <coal/core/implementation.h>

#include <coal/lang/Exception.h>
#include <coal/core/classes/subclass.h>

ExceptionDefinitionTemplate(coal_lang_NullPointerException,
			    LIBRARY_STR ".lang.NullPointerException",
			    coal_lang_Exception())
