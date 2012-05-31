#! /usr/bin/env python

import random
import re
import os

from collections import defaultdict

class ClassTree (object):
    colors = [
        'aquamarine', 'antiquewhite',
        'lightblue', 'palegreen', 'thistle',
        'cadetblue', 'lightpink', 'lightsalmon',
        'lavenderblush', 'lemonchiffon',
        'turquoise', 'honeydew'
    ]

    def __init__ (self):
        self.hierarchy = defaultdict(list)
        self.reverse = {}
        self.majors = {}
        self.all = set()

        self.cmp = lambda coll : lambda a, b : (
            (coll[b] - coll[a]) or cmp(a, b)
        )

    def _addMajor (self, klass):
        modes = klass.split('.')[:-1]
        node = self.majors

        absmode = ''
        for mode in modes:
            absmode += mode
            node = node.setdefault(absmode, {})
            absmode += '.'

    def push (self, klass, subklass):
        if klass != subklass:
            self.hierarchy[klass].append(subklass)
            self.reverse[subklass] = klass

        self.all.add(klass)
        self.all.add(subklass)

        self._addMajor(klass)
        self._addMajor(subklass)

    def _totalSubclasses (self, klass):
        classes = 0
        
        for subklass in self.hierarchy[klass]:
            if subklass != klass:
                classes += self._totalSubclasses(subklass)
                classes += 1

        return classes

    def _indent (self, string):
        lines = string.split('\n')
        indented_lines = []

        for line in lines:
            if line:
                indented_lines.append('\t' + line)
            else:
                indented_lines.append(line)

        return '\n'.join(indented_lines)

    def _belongsToMajor (self, klass, major):
        if not klass.startswith(major):
            return False

        if klass == major:
            return True

        if klass.startswith(major + '.'):
            return True

        return False

    def _formatMajors (self, majors, colors=None):
        s = ''
        re_empty = False

        for major in sorted(majors):
            if not colors:
                re_empty = True
                colors = [self.palette.pop()]
                colors.extend(['%s%d' % (colors[0], i) for i in range(1,4)])

            s += '\tsubgraph "cluster_%s" {\n' % major
            s += '\t\tlabel="%s";\n' % major
            s += '\t\tlabelloc=b;\n'
            s += '\t\tcolor=%s;\n' % colors.pop()
            s += '\t\tstyle=filled;\n'

            s += self._indent(self._formatMajors(majors[major], colors))

            for klass in sorted(self.copy, self.cmp(self.counts)):
                if self._belongsToMajor(klass, major):
                    subklasses = filter(lambda s : s.startswith(major),
                                        self.hierarchy[klass])

                    subklasses = sorted(subklasses, self.cmp(self.counts))

                    s += '\t\t"%s" -> { %s };\n' % (
                        klass,
                        ' '.join(['"%s"' % s for s in subklasses])
                    )

                    for subklass in subklasses:
                        self.hierarchy[klass].remove(subklass)
                    self.copy.remove(klass)
            s += '\t}\n'

            if re_empty:
                colors = []

        return s

    def __str__ (self):
        self.palette = random.sample (
            ClassTree.colors,
            len(ClassTree.colors)
        )

        self.counts = {}
        for klass in self.all:
            self.counts[klass] = self._totalSubclasses(klass)

        self.copy = self.all.copy()

        s = 'strict digraph {\n'
        s += '\tnode [shape=box,style=filled,color=white];\n'

        s += self._formatMajors(self.majors, ['antiquewhite'])

        for klass in sorted(self.hierarchy, self.cmp(self.counts)):
            if klass == 'coal.lang.object':
                s += '\tedge [color=transparent];\n'

            subklasses = sorted(self.hierarchy[klass], self.cmp(self.counts))
            if subklasses:
                s += '\t"%s" -> { %s };\n' % (
                    klass,
                    ' '.join(['"%s"' % s for s in subklasses])
                )

            if klass == 'coal.lang.object':
                s += '\tedge [color=black];\n'

        s += '}\n'
        return s

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

            classes.push(s, c)

classes = ClassTree()
os.path.walk(".", walker, classes)
print classes
