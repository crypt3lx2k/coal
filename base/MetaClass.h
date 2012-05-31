#ifndef COAL_BASE_METACLASS_H
#define COAL_BASE_METACLASS_H

#include <coal/coal.h>
#include <coal/base/Object.h>

/**
 * coal_base_MetaClass
 *
 * Root of the entire coal interface hierarchy.
 *
 * @extends coal_base_Object
 * @constructor takes an unknown amount of arguments (whelp!)
 */
coal_cfunspec val coal_base_MetaClass (void) coal_funattr_const;

#ifndef COAL_BASE_NAMESPACE_POLLUTE
# define MetaClass() coal_base_MetaClass()
#endif

#endif /* COAL_BASE_METACLASS_H */
