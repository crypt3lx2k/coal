#ifndef COAL_IO_IO_H__
#define COAL_IO_IO_H__

#include <stdio.h>

#include <coal/coal.h>
#include <coal/io/namespace.h>

/**
 * io(fprint)
 * Prints object to stream.
 *
 * @param  (const var) object to be printed
 * @param  (FILE *) stream to print to
 * @return (int) the number of characters printed
 */
cfundecl__ (int io(fprint) (const var object, FILE * stream));

/**
 * io(fprintln)
 * Prints object to stream
 * with a trailing newline.
 *
 * @param  (const var) object to be printed
 * @param  (FILE *) stream to print to
 * @return (int) the number of characters printed
 */
cfundecl__ (int io(fprintln) (const var object, FILE * stream));

/**
 * io(print)
 * Prints object to stdout.
 *
 * @param  (const var) object to be printed
 * @return (int) the number of characters printed
 */
cfundecl__ (int io(print) (const var object));

/**
 * io(println)
 * Prints object to stdout
 * with a trailing newline.
 *
 * @param  (const var) object to be printed
 * @return (int) the number of characters printed
 */
cfundecl__ (int io(println) (const var object));

#ifdef IO_NAMESPACE_POLLUTE
# define fprint   io(fprint)
# define fprintln io(fprintln)
# define print    io(prin)
# define println  io(println)
#endif

#endif /* COAL_IO_IO_H__ */
