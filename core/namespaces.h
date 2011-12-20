#ifndef COAL_CORE_NAMESPACES_H__
#define COAL_CORE_NAMESPACES_H__

#define namespace(namespace, identifier) \
  namespace ## _ ## identifier

#define cfundecl__(name, args) \
  extern inline name args

#endif /* COAL_NAMESPACES__ */
