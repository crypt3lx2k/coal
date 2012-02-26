#! /usr/bin/env python

import re
import os

description_r = re.compile(r'''
\/\*\*\n
\s*\*\s*(.*?)\n
.+?
@extends\s*(.*?)\n
.+?
\*\/
''', re.VERBOSE | re.DOTALL)

def walker (classes, dirname, fnames):
    if '.git' in dirname:
        return

    for fname in fnames:
        path = os.path.sep.join((dirname, fname))

        if not (path.endswith('.h') or
                path.endswith('.rep')):
            continue

        contents = open(path).read()

        for description in description_r.finditer(contents):
            c, s = description.groups()

            c = c.replace("_", ".")
            s = s.replace("_", ".")

            classes[c] = s

classes = {}
os.path.walk(".", walker, classes)

print 'digraph hierarchy {'

for key in sorted(classes):
    print '"%s" -> "%s";' % (
        classes[key],
        key
    )

print '}'
