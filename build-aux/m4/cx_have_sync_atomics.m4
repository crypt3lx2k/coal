#
# SYNOPSIS
#
#   CX_HAVE_SYNC_ATOMICS([ACTION-IF-FOUND[, ACTION-IF-NOT-FOUND]])
#
# DESCRIPTION
#
#   This macro attempts to determine whether the __sync_* family of extensions
#   for atomic memory access are available. See
#   (http://gcc.gnu.org/onlinedocs/gcc-4.7.1/gcc/_005f_005fsync-Builtins.html)
#   for a summary of their usage.
#
#   On success this defines HAVE_SYNC_ATOMICS to 1. The result of this macro is
#   cached in the cx_cv_have_sync_atomics variable with either the value "yes"
#   (successful) or "no" (unsuccessful).
#
# LICENSE
#
#   Copyright (c) 2012 Truls Edvard Stokke
#
#   Copying and distribution of this file, with or without modification, are
#   permitted in any medium without royalty provided the copyright notice
#   and this notice are preserved. This file is offered as-is, without any
#   warranty.
#

#serial 1

AC_DEFUN([CX_HAVE_SYNC_ATOMICS], [
  AC_CACHE_CHECK([for gcc atomic builtins], [cx_cv_have_sync_atomics], [
    AC_REQUIRE([AC_PROG_CC])
    AC_LANG_PUSH([C])
    AC_TRY_RUN([
      int main(void) {
        int m = 1;
        int n = 2;

        if (! __sync_bool_compare_and_swap(&m, 1, 3))
          return 1;

        if (__sync_add_and_fetch(&m, n) != 5)
          return 1;

        if (__sync_sub_and_fetch(&m, n) != 3)
          return 1;

        return 0;
      }],
      [cx_cv_have_sync_atomics="yes"],
      [cx_cv_have_sync_atomics="no"],
      [AC_TRY_COMPILE(
         [], [
         int m = 1;
         int n = 2;

         __sync_bool_compare_and_swap(&m, 1, 3);
         __sync_add_and_fetch(&m, n);
         __sync_sub_and_fetch(&m, n);],
         [cx_cv_have_sync_atomics="yes"],
         [cx_cv_have_sync_atomics="no"]
       )]
    )
    AC_LANG_POP([C])]
  )

  if test "$cx_cv_have_sync_atomics" = "yes" ; then
    AC_DEFINE([HAVE_SYNC_ATOMICS], [1], [gcc atomic builtin support])
  fi

  if test "$cx_cv_have_sync_atomics" = "yes" ; then
    ifelse([$1], [], [:], [$1])
  else
    ifelse([$2], [], [:], [$2])
  fi
])
