#! /usr/bin/env python
"""
Basic common functionality for the python scripts in this
directory.
"""

import os

# This list defines which filetypes are affected by the
# script, if a file ends with an extension that isn't in this
# list the script will ignore it.
extension_whitelist = []

# This list defines which directories the script will not
# traverse.
directory_blacklist = []

def _ignore_file (path):
    """
    Returns whether the script should ignore the file given
    by path or not.
    """
    # We don't use os.path.splitext since that only returns
    # the last extension, for instance tarball.tar.gz will
    # be split into ('tarball.tar', '.gz').
    return not any (
        map (
          lambda ext : path.endswith(ext),
          extension_whitelist
        )
    )

def _ignore_dir (path):
    """
    Returns whether the script should ignore the directory
    given by path or not.
    """
    return not all (
        map (
          lambda dirname : dirname not in path,
          directory_blacklist
        )
    )

def _walker (user_fn, dirname, fnames):
    if _ignore_dir(dirname):
        return

    for fname in fnames:
        path = os.path.sep.join((dirname, fname))

        if os.path.isdir(path) or _ignore_file(path):
            continue

        user_fn(path)

def stroll(base, user_fn):
    """
    Calls a user defined function on every file accepted by
    the extension whitelist and directory blacklist.
    """
    os.path.walk(base, _walker, user_fn)
