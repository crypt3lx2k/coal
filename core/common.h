#ifndef __COAL_CORE_COMMON_H
#define __COAL_CORE_COMMON_H

#ifndef __COAL_IMPLEMENTATION_H
# error "Never include <coal/core/common.h> directly; use <coal/implementation.h> instead."
#endif

#define STRINGIFY(macro) #macro

#define _LIBRARY_NAME coal
#define _LIBRARY_STR STRINGIFY(_LIBRARY_NAME)

#endif /* __COAL_CORE_COMMON_H */
