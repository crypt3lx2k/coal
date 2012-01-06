#ifndef COAL_CORE_CDEFS_H__
#define COAL_CORE_CDEFS_H__

/* this is here in case we
   need to change how every
   function is declared
   in the future */
#define cfundecl__(cfundecl) \
  extern inline cfundecl

/**
 * Object variable type
 */
/* not a typedef so `const var'
   behaves nicely */
#define var void *

#endif /* COAL_CORE_CDEFS_H__ */
