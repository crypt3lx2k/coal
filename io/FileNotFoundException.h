#ifndef COAL_IO_FILENOTFOUNDEXCEPTION_H__
#define COAL_IO_FILENOTFOUNDEXCEPTION_H__

#include <coal/coal.h>

/**
 * coal_io_FileNotFoundException
 * Exception that indicates something
 * went wrong when attempting to open
 * a file.
 *
 * @extends coal_io_IOException
 * @constructor takes a variable amount of arguments
 * @param (const char *) printf-like format string
 * @param (...) printf-like arguments
 */
cfundecl__ (const var coal_io_FileNotFoundException (void))
  __attribute__ ((const));

#ifdef IO_NAMESPACE_POLLUTE
# define FileNotFoundException coal_io_FileNotFoundException
#endif

#endif /* COAL_IO_FILENOTFOUNDEXCEPTION_H__ */
