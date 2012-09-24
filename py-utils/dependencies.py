#! /usr/bin/env python
"""
Goes over .c and .h files and figures out their include
dependencies in order to generate a Makefile.
"""

import util
import re

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

# name of library
library_name = 'coal'

Makefile_am_template = \
'''AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I build-aux/m4

lib_LTLIBRARIES = lib{libname}.la

lib{libname}_la_SOURCES = {sourcefiles}
nobase_lib{libname}_la_HEADERS = {headerfiles}
lib{libname}_ladir = $(includedir)

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = {libname}.pc'''

class DependencyGraph (DirectedAcyclicGraph):
    def str_makefile (self):
        headers = set (
            filter (
                lambda s : (
                    s.endswith('.h')    and
                    '.rep'     not in s and
                    'private/' not in s
                ),
                self.nodes
            )
        )

        for header in headers.copy():
            headers.update(self[header])

        sources = self.nodes - headers

        return Makefile_am_template.format (
            libname=library_name,
            sourcefiles=' '.join(sorted(sources)),
            headerfiles=' '.join(sorted(headers))
        )

deps = DependencyGraph()

def walker (path):
    contents = open(path).read()

    path = path.lstrip('./')
    deps.add_node(path)

    for hit in include_re.findall(contents):
        # ignore external/system headers
        if 'coal' not in hit:
            continue

        deps.add_edge(path, hit)

if __name__ == '__main__':
    util.stroll('.', walker)
    deps.expand()
    print deps.str_makefile()
