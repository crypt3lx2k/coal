#ifndef COAL_IO_IO_H__
#define COAL_IO_IO_H__

#include <stdio.h>

#include <coal/coal.h>
#include <coal/io/namespace.h>

cfundecl__ (int io(fprint), (const var object, FILE * stream));

cfundecl__ (int io(fprintln), (const var object, FILE * stream));

cfundecl__ (int io(print), (const var object));

cfundecl__ (int io(println), (const var object));

#ifdef IO_NAMESPACE_POLLUTE
# define fprint   io(fprint)
# define fprintln io(fprintln)
# define print    io(prin)
# define println  io(println)
#endif

#endif /* COAL_IO_IO_H__ */
