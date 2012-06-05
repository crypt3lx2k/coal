#! /usr/bin/env python
"""
Goes over .c, .h and .rep files and figures out their include
dependencies in order to generate a Makefile.
"""

import os
import re
import sys

from DAG import DirectedAcyclicGraph

# This list defines which filetypes are affected by the
# script.
#
# If a file ends with an extension that isn't in this list
# this script will ignore it.
extension_whitelist = [
    '.c',
    '.h',
    '.rep'
]

# This script ignores directories listed in here.
directory_blacklist = [
    '.git',
]

# This regex matches any C preprocessor include directive and
# extracts the file included. It assumes that the directive
# is correct and not on a form like #include "file.h> or
# some other evil form like that.
include_re = re.compile (
    r'\#\s*include\s+(?:\<|\")\s*(.*?)\s*(?:\>|\")'
)

PROJ = 'libcoal.so'

makefile_template = \
'''CC = gcc

RM = rm -f
CP = cp -f

COAL_DIR = ../

WFLAGS = -Wall -Wextra -Werror
BINFLAGS = -fPIC
LIBFLAGS = -shared $(BINFLAGS)
IFLAGS = -I$(COAL_DIR)
OPTFLAGS = -O2 -fomit-frame-pointer -funroll-loops

CFLAGS = -g -O0 $(WFLAGS) $(BINFLAGS) $(IFLAGS)
LDFLAGS = $(LIBFLAGS)

%s
.PHONY : clean
clean :
\t$(RM) $(OBJS) $(PROJ) $(shell find -name "*~")'''

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
        objs = filter(lambda n : n.endswith('.o'), self.nodes)

        s = ['OBJS = %s\n' % ' \\\n\t'.join(sorted(objs))]
        s.append('PROJ = %s\n' % PROJ)

        s.append('build :\n\t$(MAKE) $(PROJ)\n')
        s.append('install : $(PROJ)\n\t$(CP) $(PROJ) /usr/lib/\n')

        s.append('%s : %s' % (PROJ, '$(OBJS)'))
        s.append('\t$(CC) $(LDFLAGS) $(OBJS) -o $@\n')

        for node in sorted(self, self.cmp):
            s.append('%s : %s' % (
                      node,
                      ' \\\n\t'.join(sorted(self[node]))
                    )
            )

            s.append('\t%s\n' % (
                      'touch $@'
                      if not node.endswith('.o') else
                      '$(CC) $(CFLAGS) -c $< -o $@'
                    )
            ) 

        return makefile_template % '\n'.join(s)

deps = DependencyGraph()

def ignore_file (path):
    """
    Returns whether this script should
    ignore the file given by path or not.
    """
    return not any(map(lambda ext : path.endswith(ext),
                       extension_whitelist))

def ignore_dir (path):
    """
    Returns whether this script should
    ignore the directory given by path
    or not.
    """
    return not all(map(lambda dirname : dirname not in path,
                       directory_blacklist))

def walker (deps, dirname, fnames):
    # ignore blacklisted directories
    if ignore_dir(dirname):
        return

    for fname in fnames:
        path = os.path.sep.join((dirname, fname))

        if os.path.isdir(path) or ignore_file(path):
            continue

        contents = open(path).read()

        for hit in include_re.findall(contents):
            # ignore external/system headers
            if 'coal' not in hit:
                continue

            hit = hit.replace('coal', '.', 1)

            deps.add_edge(path, hit)

            if path.endswith('.c'):
                deps.add_edge(path.replace('.c', '.o'), path)

os.path.walk('.', walker, deps)

if __name__ == '__main__':
    deps.reduce()
    print deps.str_makefile()
