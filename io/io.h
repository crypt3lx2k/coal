#ifndef COAL_IO_IO_H__
#define COAL_IO_IO_H__

#include <stdio.h> /* FILE */
#include <coal/coal.h>

/**
 * coal_io_fprint
 * Prints object to stream.
 *
 * @param  (const var) object to be printed
 * @param  (FILE *) stream to print to
 * @return (int) the number of characters printed
 */
cfundecl__ (int coal_io_fprint (const var object, FILE * stream));

/**
 * coal_io_fprintln
 * Prints object to stream
 * with a trailing newline.
 *
 * @param  (const var) object to be printed
 * @param  (FILE *) stream to print to
 * @return (int) the number of characters printed
 */
cfundecl__ (int coal_io_fprintln (const var object, FILE * stream));

/**
 * coal_io_print
 * Prints object to stdout.
 *
 * @param  (const var) object to be printed
 * @return (int) the number of characters printed
 */
cfundecl__ (int coal_io_print (const var object));

/**
 * coal_io_println
 * Prints object to stdout
 * with a trailing newline.
 *
 * @param  (const var) object to be printed
 * @return (int) the number of characters printed
 */
cfundecl__ (int coal_io_println (const var object));

#ifdef IO_NAMESPACE_POLLUTE
# define fprint   coal_io_fprint
# define fprintln coal_io_fprintln
# define print    coal_io_prin
# define println  coal_io_println
#endif

#endif /* COAL_IO_IO_H__ */
