#ifndef COAL_IO_IOEXCEPTION_H__
#define COAL_IO_IOEXCEPTION_H__

#include <coal/coal.h>

/**
 * coal_io_IOException
 * Base class for exceptions
 * related to I/O routines.
 *
 * @extends coal_lang_Exception
 * @constructor takes a variable amount of arguments
 * @param (const char *) printf-like format string
 * @param (...) printf-like arguments
 */
cfundecl__ (const var coal_io_IOException (void))
  __attribute__ ((const));

#ifdef IO_NAMESPACE_POLLUTE
# define IOException coal_io_IOException
#endif

#endif /* COAL_IO_IOEXCEPTION_H__ */
