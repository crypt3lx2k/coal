#include <coal/core/implementation.h>

#include <coal/io/IOException.h>
#include <coal/core/classes/subclass.h>

ExceptionDefinitionTemplate(coal_io_FileNotFoundException,
			    LIBRARY_STR ".io.FileNotFoundException",
			    coal_io_IOException())
