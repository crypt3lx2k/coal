#! /usr/bin/env python

from collections import defaultdict

class DirectedAcyclicGraph (object):
    def __init__ (self):
        self.nodes = set()
        self.edges = defaultdict(set)
        self.cmp   = cmp

    def __contains__ (self, node):
        return node in self.nodes

    def __getitem__ (self, node):
        return self.edges.get(node, set())

    def __iter__ (self):
        return iter(self.nodes)

    def add_edge (self, node, child):
        [self.nodes.add(n) for n in (node, child)]
        self.edges[node].add(child)

    def add_node (self, node):
        self.nodes.add(node)

    def remove_edge (self, node, child):
        self.edges[node].remove(child)

    def remove_node (self, node):
        self.nodes.remove(node)

    def expand (self):
        def recurse (node):
            # get a copy of every child
            children = self[node].copy()

            for child in children:
                # update our children with every childrens
                # children.
                self[node].update(recurse(child))

            return self[node]

        for node in self:
            recurse(node)

    def reduce (self):
        def recurse (node):
            other_children = set()

            for child in self[node]:
                # find every sub-child's children
                other_children.update(recurse(child))

            # our new children are our current children minus
            # the children provided by sub-children
            self[node].difference_update(other_children)

            # we return every child we provide through either
            # our current children or sub-children's children
            return other_children | self[node]

        for node in self:
            recurse(node)

    def str_graphviz (self):
        s = ['strict digraph {']

        for node in sorted(self, self.cmp):
            children = ['"%s"' % c for c in sorted(self[node],
                                                   self.cmp)]

            s.append(
                '\t"%s" -> { %s }' % (
                    node, ' '.join(children)
                )
            )

        s.append('}')
        return '\n'.join(s)

    def str_tsort (self):
        s = []

        for node in sorted(self, self.cmp):
            for child in self[node]:
                s.append('%s %s' % (node, child))

        return '\n'.join(s)
