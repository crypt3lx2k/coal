#ifndef COAL_CORE_COMMON_H__
#define COAL_CORE_COMMON_H__

#ifndef COAL_IMPLEMENTATION_H__
# error "Never include <coal/core/common.h> directly; use <coal/implementation.h> instead."
#endif

#define STRINGIFY(macro) #macro

#define LIBRARY_NAME coal
#define LIBRARY_STR STRINGIFY(LIBRARY_NAME)

#endif /* COAL_CORE_COMMON_H__ */
