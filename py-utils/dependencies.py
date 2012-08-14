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
    '.h'
]

# This script ignores directories listed in here.
directory_blacklist = [
    '.git'
]

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

        path = path.lstrip('./')
        deps.add_node(path)

        for hit in include_re.findall(contents):
            # ignore external/system headers
            if 'coal' not in hit:
                continue

            deps.add_edge(path, hit)

os.path.walk('.', walker, deps)

if __name__ == '__main__':
    deps.expand()
    print deps.str_makefile()
