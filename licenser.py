#! /usr/bin/env python

import os
import re

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

def ignore_file (path):
    """
    Returns whether this script should
    ignore the file given by path or not.
    """
    return not any(map(lambda ext : path.endswith(ext),
                       extension_whitelist))

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

license_body = comment(open('LICENSE', 'r').read())
license_data = license_re.match(license_body).groupdict()

def walker (data, dirname, fnames):
    # ignore .git directory if any
    if '.git' in dirname:
        return

    for fname in fnames:
        path = os.path.sep.join((dirname, fname))

        if os.path.isdir(path):
            continue

        if ignore_file(path):
            continue

        contents = open(path).read().lstrip('\n')
        header = comment_re.match(contents)

        if header:
            old_license = license_re.match(contents)

            if old_license:
                old_license_body = old_license.group(0)
                old_data = old_license.groupdict()

                if ((data['authors'] !=
                     old_data['authors']) or
                    (data['description'] !=
                     old_data['description'])):
                    continue

                contents = contents.lstrip(old_license_body)
                contents = contents.lstrip('\n')

        contents = license_body + '\n\n' + contents
        open(path, 'w').write(contents)

if __name__ == '__main__':
    os.path.walk('.', walker, license_data)
