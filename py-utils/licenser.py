#! /usr/bin/env python
"""
Goes over .c, .h and .rep files and adds a license if it's not
already present.
"""

import os
import re
import sys

import util

util.extension_whitelist.extend ([
    '.c',
    '.h'
])

util.directory_blacklist.extend ([
    '.git'
])

# This is the license this script currently expects the
# LICENSE file to contain.
#
# If you want to change this you have to modify this string
# and the license_re regex.
LICENSE_VERSION = 'LGPL v2.1'

def comment (s):
    """
    Puts a C-style comment around a multi-line string.
    """
    result = ['/*']

    for line in s.strip().split('\n'):
        result.append((' * %s' % line) if line else ' *')

    result.append(' */')

    return '\n'.join(result)

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

any_license_re = re.compile (
    r'\s*(?:\/\*|\*|\/\/)*.*?(?:copyright|li(?:c|s)ense|merchantability|warranty|machine|generated?|do not edit|don\'t edit).*',
    re.I
)

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

data = license_m.groupdict()

def walker (path):
    contents = open(path).read().lstrip('\n')
    header = comment_re.match(contents)
    write_license = False

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
                return

            # if every detail is the same we ignore the
            # file as there is nothing new to do.
            if data['year'] == old_data['year']:
                return

            contents = contents.lstrip(old_license_body)
            contents = contents.lstrip('\n')

            # We passed all the logic, write license.
            write_license = True

    # We're not sure if we're supposed to write the license
    # yet, search for any license anywhere in the file.
    if not write_license:
        old_license = any_license_re.search(contents)

        if old_license:
            print >> sys.stderr, 'unknown license in `%s\' based on `%s\'' % (
                path,
                old_license.group(0).strip()
            )
            return

    # We've either decided to write the license earlier
    # or we haven't found any license at all.
    print >> sys.stderr, 'editing file: %s' % path

    contents = license_body + '\n\n' + contents
    open(path, 'w').write(contents)

if __name__ == '__main__':
    util.stroll('.', walker)
