#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([coal], [0.0.1], [trulses@gmail.com], [coal], [https://github.com/crypt3lx2k/coal])
AC_CONFIG_SRCDIR([coal/coal.c])

AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([build-aux/m4])

LT_INIT
AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL

# Checks for libraries.
AX_PTHREAD([], [AC_MSG_ERROR([can't compile coal without pthreads])])

CC="$PTHREAD_CC"
CFLAGS="$PTHREAD_CFLAGS $CFLAGS"
LIBS="$PTHREAD_LIBS $LIBS"

# Checks for header files.
AC_CHECK_HEADERS([limits.h stdarg.h stddef.h stdint.h stdlib.h string.h], [], [AC_MSG_ERROR([required headers not found])])
AC_CHECK_HEADERS([features.h], [], [AC_MSG_WARN([features.h not found, glibc specific stuff will not be available])])

if test "$ac_cv_header_features_h" = "yes" ; then
   AC_CHECK_HEADERS([printf.h], [], [AC_MSG_WARN([printf.h not found, %O printf specifier will not be available])])
   AC_CHECK_HEADERS([execinfo.h], [], [AC_MSG_WARN([execinfo.h not found, detailed backtrace will not be available])])
fi

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_SIZE_T
AC_CHECK_TYPES([ptrdiff_t])

CX_HAVE_SYNC_ATOMICS([], [AC_MSG_ERROR([can't compile coal without atomic builtins, see coal/private/atomic.h for details])])

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC

AC_CONFIG_FILES([Makefile coal.pc])
AC_OUTPUT
