#include <coal/core/implementation.h>

#include <coal/lang/Exception.h>
#include <coal/core/classes/subclass.h>

ExceptionDefinitionTemplate(coal_lang_IndexOutOfBoundsException,
			    LIBRARY_STR ".lang.IndexOutOfBoundsException",
			    coal_lang_Exception())
