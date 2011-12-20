#ifndef COAL_LANG_NAMESPACE_H__
#define COAL_LANG_NAMESPACE_H__

#include <coal/core/namespaces.h>
#include <coal/namespace.h>

#define lang(identifier) \
  lib(namespace(lang, identifier))

#endif /* COAL_LANG_NAMESPACE_H__ */
