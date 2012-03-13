#ifndef COAL_IO_FILE_H__
#define COAL_IO_FILE_H__

#include <coal/coal.h>

/**
 * coal_io_File
 * Class representing a file object.
 *
 * See fopen(3) for details on modes.
 *
 * @extends coal_lang_object
 * @constructor takes 2 arguments
 * @param (const char *) path of file
 * @param (const char *) mode to open file with
 */
cfundecl__ (const var coal_io_File (void))
  __attribute__ ((const));

#ifdef IO_NAMESPACE_POLLUTE
# define File coal_io_File
#endif

#endif /* COAL_IO_FILE_H__ */
