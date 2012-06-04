#! /usr/bin/env python
"""
Goes over .c, .h and .rep files and figures out their include
dependencies in order to generate a Makefile.
"""

import os
import re
import sys

from collections import defaultdict

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

# This regex matches any C preprocessor include directive and
# extracts the file included. It assumes that the directive
# is correct and not on a form like #include "file.h> or
# some other evil form like that.
include_re = re.compile (
    r'\#include\s+(?:\<|\")\s*(.*?)\s*(?:\>|\")'
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

class DirectedAcyclicGraph (object):
    def __init__ (self):
        self.deps = defaultdict(set)

    def __contains__ (self, f):
        return f in self.deps

    def __getitem__ (self, f):
        return self.deps[f]

    def __iter__ (self):
        return iter(self.deps)

    def __setitem__ (self, f, s):
        self.deps[f] = s

    def add_edge (self, f, t):
        self.deps[f].add(t)

    def remove_edge (self, f, t):
        self.deps[f].remove(t)

    def expand (self):
        def rec (f):
            if f not in self:
                return set()

            old = self[f].copy()

            for h in old:
                self[f].update(rec(h))

            return self[f]

        for f in self:
            rec(f)

    def reduce (self):
        def rec (f):
            if f not in self:
                return set()

            children_dep = set()

            for h in self[f]:
                children_dep.update(rec(h))

            self[f] = self[f] - children_dep

            return children_dep | self[f]

        for f in self:
            rec(f)

    def str_graphviz (self):
        s = ['strict digraph {']

        for f in sorted(self, cmp_headers_first):
            s.append('\t"%s" -> { %s }' % (
                f,
                ' '.join(['"%s"' % d for d in sorted(self[f])])
            ))

        s.append('}')
        return '\n'.join(s)

    def str_makefile (self, objs):
        s = ['OBJS = %s\n' % ' \\\n\t'.join(sorted(objs))]
        s.append('PROJ = %s\n' % PROJ)

        s.append('build :\n\t$(MAKE) $(PROJ)\n')
        s.append('install : $(PROJ)\n\t$(CP) $(PROJ) /usr/bin/\n')

        s.append('%s : %s' % (PROJ, '$(OBJS)'))
        s.append('\t$(CC) $(LDFLAGS) $(OBJS) -o $@\n')

        for f in sorted(self, cmp_headers_first):
            s.append('%s : %s' % (
                      f,
                      ' \\\n\t'.join(sorted(self[f]))
                    )
            )

            s.append('\t%s\n' % (
                      'touch $@'
                      if not f.endswith('.o') else
                      '$(CC) $(CFLAGS) -c $< -o $@'
                    )
            ) 

        return makefile_template % '\n'.join(s)

    def str_tsort (self):
        s = []

        for f in self:
            for h in self[f]:
                s.append('%s %s\n' % (f, h))

        return '\n'.join(s)


deps = DirectedAcyclicGraph()
objs = set()

def ignore_file (path):
    """
    Returns whether this script should
    ignore the file given by path or not.
    """
    return not any(map(lambda ext : path.endswith(ext),
                       extension_whitelist))

def walker (dep, dirname, fnames):
    # ignore .git directory if any
    if '.git' in dirname:
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

            dep.add_edge(path, hit)

            if path.endswith('.c'):
                obj = path.replace('.c', '.o')
                dep.add_edge(obj, path)
                objs.add(obj)

os.path.walk('.', walker, deps)

deps.reduce()
print deps.str_makefile(objs)
