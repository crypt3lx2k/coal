#! /usr/bin/env python
"""
Goes over .c, .h and .rep files and figures out their include
dependencies.
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

            diff = self[f] & children_dep

            if diff:
                print >> sys.stderr, 'removing edges from %s' % f
                for k in diff:
                    print >> sys.stderr, '\t%s' % k

            self[f] = self[f] - children_dep

            return children_dep | self[f]

        for f in self:
            rec(f)

    def str_tsort (self):
        s = ''

        for f in self:
            for h in self[f]:
                s += '%s %s\n' % (f, h)

        return s.rstrip('\n')

    def str_graphviz (self):
        s = 'strict digraph {\n'

        for f in self:
            s += '\t"%s" -> { %s }\n' % (
                f,
                ' '.join(['"%s"' % s for s in self[f]])
            )

        s += '}'
        return s

deps = DirectedAcyclicGraph()

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

        path = path.replace('.', 'coal', 1)

        for hit in include_re.findall(contents):
            dep.add_edge(path, hit)

os.path.walk('.', walker, deps)

deps.reduce()
print deps.str_graphviz()
