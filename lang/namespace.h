#ifndef __COAL_LANG_NAMESPACE_H
#define __COAL_LANG_NAMESPACE_H

#include <coal/core/namespaces.h>
#include <coal/namespace.h>

#define lang(identifier) \
  lib(namespace(lang, identifier))

#endif /* __COAL_LANG_NAMESPACE_H */
