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

    def __iter__ (self):
        return iter(self.deps)

    def __getitem__ (self, f):
        return self.deps[f]

    def add_edge(self, f, t):
        self.deps[f].add(t)

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
            dep[path]
            dep.add_edge(hit, path)

os.path.walk('.', walker, deps)

for f in deps:
    for h in deps[f]:
        print '%s %s' % (f, h)
