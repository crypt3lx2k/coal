#! /usr/bin/env python

import sys
import random
import re
import os

from DAG import DirectedAcyclicGraph

colors = [
    'snow', 'seashell', 'AntiqueWhite', 'bisque', 'PeachPuff',
    'Navajowhite', 'LemonChiffon', 'cornsilk', 'ivory',
    'honeydew', 'LavenderBlush', 'MistyRose', 'azure',
    'SlateBlue', 'RoyalBlue', 'blue', 'DodgerBlue',
    'SteelBlue', 'DeepSkyBlue', 'SkyBlue', 'LightSkyBlue',
    'SlateGray', 'LightSteelBlue', 'LightBlue', 'LightCyan',
    'PaleTurquoise', 'CadetBlue', 'turquoise', 'cyan',
    'DarkSlateGray', 'aquamarine', 'DarkSeaGreen', 'SeaGreen',
    'PaleGreen', 'SpringGreen', 'green', 'chartreuse',
    'OliveDrab', 'DarkOliveGreen', 'khaki', 'LightGoldenrod',
    'LightYellow', 'yellow', 'gold', 'goldenrod',
    'DarkGoldenrod', 'RosyBrown', 'IndianRed', 'sienna',
    'burlywood', 'wheat', 'tan', 'chocolate', 'firebrick',
    'brown', 'salmon', 'LightSalmon', 'orange', 'DarkOrange',
    'coral', 'tomato', 'OrangeRed', 'red', 'DeepPink',
    'HotPink', 'pink', 'LightPink', 'PaleVioletRed', 'maroon',
    'VioletRed', 'magenta', 'orchid', 'plum', 'MediumOrchid',
    'DarkOrchid', 'purple', 'MediumPurple', 'thistle'
]

relaxed_colors = [
    'antiquewhite', 'beige', 'bisque'
]

def indent (lines):
    indented_lines = []

    for line in lines:
        if line:
            indented_lines.append('\t' + line)
        else:
            indented_lines.append(line)

    return indented_lines

class ClassTree (DirectedAcyclicGraph):
    def __init__ (self):
        DirectedAcyclicGraph.__init__(self)

        self.palette = []
        self.colors  = []

    def getBaseColor (self):
        if not self.palette:
            choice = random.randrange(len(colors))

            for i in range(len(colors)):
                i = (i + choice) % len(colors)
                self.palette.append(colors[i])

        return self.palette.pop()

    def getColor (self):
        if not self.colors:
            base_color = self.getBaseColor()

            self.colors.extend ([
                '%s%d' % (base_color, i)
                for i in range(1, 4)
            ])

        return self.colors.pop()

    def getHierarchy (self):
        hierarchy = {}

        for klass in self:
            namespaces = klass.split('.')
            category = hierarchy

            for namespace in namespaces:
                category = category.setdefault(namespace, {})

        return hierarchy

    def subgraph (self, this, categories):
        s = []

        if categories:
            s.append (
                'subgraph cluster_%s {' %
                  this.replace('.', '_')
            )

            color = self.getColor()
            print >> sys.stderr, 'Setting %s to color %s' % (this, color)

            s.append('\tlabel="%s";' % this)
            s.append('\tcolor="%s";' % color)

            # we are a namespace but also a class, e.g.
            # coal.base.String and coal.base.String.Metaclass
            if this in self:
                s.append('\t"%s";' % this)

            for category in sorted(categories):
                child = '.'.join((this, category))

                # we want every child to have the same color
                # with relation to us, therefore we save the
                # current palette
                old_colors = self.colors[:]

                subgraph = \
                    self.subgraph(child, categories[category])

                # here we restore the old palette
                self.colors = old_colors

                s.extend(indent(subgraph))

            s.append('}')
        else:
            s.append('"%s";' % this)

        return s

    def graph_edges (self):
        s = []

        for node in self:
            # we only care about classes that actually have
            # other classes inheriting from it
            if not self[node]:
                continue

            s.append(
                '{ %s } -> "%s";' % (
                    ' '.join (
                        ['"%s"' % c for c in self[node]]
                    ),
                    node
                )
            )

        return s

    def str_graphviz (self):
        hierarchy = self.getHierarchy()

        s = ['strict digraph {']

        # put everyone in the correct subgraph
        for category in hierarchy:
            # give major namespaces like these relaxed colors
            self.colors = random.sample(relaxed_colors, 1)

            subgraph = self.subgraph (
                category,
                hierarchy[category]
            )

            s.extend (
                indent(subgraph)
            )

        # resolve edges
        s.extend(indent(self.graph_edges()))

        s.append('}')
        return '\n'.join(s)

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

        if not path.endswith('.h'):
            continue

        contents = open(path).read()

        for description in description_r.finditer(contents):
            c, s = description.groups()

            # avoid objects that point to themselves
            if c == s:
                continue

            c = c.replace('_', '.')
            s = s.replace('_', '.')

            # the end result will have classes pointing to
            # the class they extend, but for brevity we need
            # every superclass to have an edge to every class
            # that extends it
            classes.add_edge(s, c)

classes = ClassTree()
os.path.walk('.', walker, classes)
print classes.str_graphviz()
