#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([coal], [0.0.1], [trulses@gmail.com], [coal], [https://github.com/crypt3lx2k/coal])
AC_CONFIG_SRCDIR([coal/coal.c])
LT_INIT
AM_INIT_AUTOMAKE

AC_CONFIG_MACRO_DIR([m4])

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([limits.h stdarg.h stddef.h stdint.h stdlib.h string.h], [], [AC_MSG_ERROR([required headers not found])])
AC_CHECK_HEADERS([printf.h features.h], [], [AC_MSG_WARN([printf.h or features.h not found, %O printf specifier will not be available])])

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
