#ifndef COAL_LANG_ABSTRACT_H__
#define COAL_LANG_ABSTRACT_H__

#include <coal/coal.h>

/**
 * coal_lang_abstract
 * Base class for abstract classes.
 *
 * @extends coal_lang_object
 * @constructor takes 0 arguments
 */
cfundecl__ (const var coal_lang_abstract (void))
  __attribute__ ((const));

#ifdef LANG_NAMESPACE_POLLUTE
# define abstract coal_lang_abstract
#endif

#endif /* COAL_LANG_ABSTRACT_H__ */
