#! /usr/bin/env python
"""
Goes over .c, .h and .rep files and figures out their include
dependencies in order to generate a Makefile.

Do not use this, use the autotools instead.
"""

import os
import re
import sys

import util

from DAG import DirectedAcyclicGraph

util.extension_whitelist.extend ([
    '.c',
    '.h'
])

util.directory_blacklist.extend ([
    '.git'
])

# This regex matches any C preprocessor include directive and
# extracts the file included. It assumes that the directive
# is correct and not on a form like #include "file.h> or
# some other evil form like that.
include_re = re.compile (
    r'\#\s*include\s*(?:\<|\")\s*(.*?)\s*(?:\>|\")'
)

PROJ = 'libcoal.so'
INSTALL_DIR = '/usr/lib'

makefile_template = \
'''CC = gcc
LD = $(CC)

RM = rm -f
CP = cp -f

COAL_DIR = .

DFLAGS = -DHAVE_EXECINFO_H=1 -DHAVE_PRINTF_H=1 -DHAVE_FEATURES_H=1
WFLAGS = -Wall -Wextra -Werror
BINFLAGS = -fPIC
LIBFLAGS = -shared $(BINFLAGS)
IFLAGS = -I$(COAL_DIR)
OPTFLAGS = -O2 -fomit-frame-pointer -funroll-loops

CFLAGS = -g -O0 -pthread $(DFLAGS) $(WFLAGS) $(BINFLAGS) $(IFLAGS)
LDFLAGS = -pthread $(LIBFLAGS)

OBJS = {objects}

PROJ = {project}

all :
\t$(MAKE) $(PROJ)

install : $(PROJ)
\t$(CP) $(PROJ) {installdir}

uninstall :
\t$(RM) {installdir}/{project}

{project} : $(OBJS)
\t$(LD) $(LDFLAGS) $(OBJS) -o $@

{compile_files}

.PHONY : clean
clean :
\t$(RM) $(OBJS) $(PROJ) $(shell find -name "*~")

.PHONY : distclean
distclean : clean
\t$(RM) Makefile'''

def cmp_headers_first (a, b):
    for extension in ('.h', '.rep', '.c', '.o'):
        if a.endswith(extension) and b.endswith(extension):
            return cmp(a, b)
        elif a.endswith(extension):
            return -1
        elif b.endswith(extension):
            return 1

    return cmp(a, b)

class DependencyGraph (DirectedAcyclicGraph):
    def __init__ (self):
        DirectedAcyclicGraph.__init__(self)
        self.cmp = cmp_headers_first

    def __iter__ (self):
        return iter(self.edges)

    def str_makefile (self):
        objects = filter(lambda n : n.endswith('.o'),
                         self.nodes)

        s = []
        for node in sorted(self, self.cmp):
            s.append('%s : %s' % (
                      node,
                      ' \\\n\t'.join(sorted(self[node]))
                    )
            )

            s.append('\t%s\n' % (
                      'touch $@'
                      if node not in objects else
                      '$(CC) $(CFLAGS) -c $< -o $@'
                    )
            ) 

        return makefile_template.format (
            project=PROJ,
            installdir=INSTALL_DIR,
            objects=' \\\n\t'.join(sorted(objects)),
            compile_files='\n'.join(s)
        )

deps = DependencyGraph()

def walker (path):
    contents = open(path).read()

    path = path.lstrip('./')
    deps.add_node(path)

    if path.endswith('.c'):
        deps.add_edge(path.replace('.c', '.o'), path)

    for hit in include_re.findall(contents):
        # ignore external/system headers
        if 'coal' not in hit:
            continue

        deps.add_edge(path, hit)

if __name__ == '__main__':
    util.stroll('.', walker)
    deps.reduce()
    print deps.str_makefile()
