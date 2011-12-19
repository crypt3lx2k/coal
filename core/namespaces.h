#ifndef __COAL_CORE_NAMESPACES_H
#define __COAL_CORE_NAMESPACES_H

#define namespace(namespace, identifier) \
  namespace ## _ ## identifier

#define __cfundecl(name, args) \
  extern inline name args

#endif /* __COAL_NAMESPACES */
