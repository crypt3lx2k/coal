#! /usr/bin/env python

import os
import re
import sys

# This list defines which filetypes
# are affected by the script.
#
# If a file ends with an extension
# that isn't in this list this
# script ignores it.
extension_whitelist = [
    '.c',
    '.h',
    '.rep'
]

# This is the license this script
# currently expects the LICENSE file
# to contain.
#
# If you want to change this you
# have to modify this string and
# the license_re regex.
LICENSE_VERSION = 'LGPL v2.1'

def comment (s):
    """
    Puts a C-style comment
    around a multi-line string.
    """
    result = ['/*']

    for line in s.strip().split('\n'):
        result.append((' * %s' % line) if line else ' *')

    result.append(' */')

    return '\n'.join(result)

def ignore_file (path):
    """
    Returns whether this script should
    ignore the file given by path or not.
    """
    return not any(map(lambda ext : path.endswith(ext),
                       extension_whitelist))

license_re = re.compile(
r'''\/\*
 \* (?P<description>.+)
 \* Copyright \(C\) (?P<year>[0-9\-\,]+)\s+(?P<authors>.+)
 \*
 \* This library is free software; you can redistribute it and\/or
 \* modify it under the terms of the GNU Lesser General Public
 \* License as published by the Free Software Foundation; either
 \* version 2\.1 of the License, or \(at your option\) any later version\.
 \*
 \* This library is distributed in the hope that it will be useful,
 \* but WITHOUT ANY WARRANTY; without even the implied warranty of
 \* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE\.  See the GNU
 \* Lesser General Public License for more details\.
 \*
 \* You should have received a copy of the GNU Lesser General Public
 \* License along with this library; if not, write to the Free Software
 \* Foundation, Inc\., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 \*\/''')

comment_re = re.compile(r'''
\/\*\n
.*?\n
\ \*\/
''', re.VERBOSE | re.DOTALL)

if not os.path.exists('LICENSE'):
    print >> sys.stderr, 'no LICENSE file in root directory'
    exit(1)

license_body = comment(open('LICENSE', 'r').read())
license_m = license_re.match(license_body)

if license_m is None:
    print >> sys.stderr, 'LICENSE file malformed, must be %s, see the LICENSE_VERSION variable in this file (%s) for more details' % (LICENSE_VERSION, __file__)
    exit(1)

license_data = license_m.groupdict()

def walker (data, dirname, fnames):
    # ignore .git directory if any
    if '.git' in dirname:
        return

    for fname in fnames:
        path = os.path.sep.join((dirname, fname))

        if os.path.isdir(path) or ignore_file(path):
            continue

        contents = open(path).read().lstrip('\n')
        header = comment_re.match(contents)

        if header:
            old_license = license_re.match(contents)

            if old_license:
                old_license_body = old_license.group(0)
                old_data = old_license.groupdict()

                # if author list or description is different
                # we ignore this file, since we assume it's
                # from a different project.
                if ((data['authors']     != old_data['authors']) or
                    (data['description'] != old_data['description'])):
                    continue

                # if every detail is the same we ignore the
                # file as there is nothing new to do.
                if data['year'] == old_data['year']:
                    continue                    

                contents = contents.lstrip(old_license_body)
                contents = contents.lstrip('\n')

        contents = license_body + '\n\n' + contents
        open(path, 'w').write(contents)

if __name__ == '__main__':
    os.path.walk('.', walker, license_data)
