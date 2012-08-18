AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I build-aux/m4

lib_LTLIBRARIES = libcoal.la

libcoal_la_SOURCES = coal/base/Metaclass/Metaclass.c coal/base/Metaclass/Metaclass.rep.h coal/base/Object/Object.c coal/base/Object/Object.rep.h coal/base/String/String.c coal/base/String/String.rep.h coal/base/Throwable/Throwable.c coal/base/Throwable/Throwable.rep.h coal/coal.c coal/collections/Iterator/Iterator.c coal/collections/Iterator/Iterator.rep.h coal/error/Error/Error.c coal/error/Exception/Exception.c coal/error/IllegalStateException/IllegalStateException.c coal/error/NoSuchMethodError/NoSuchMethodError.c coal/error/NullPointerException/NullPointerException.c coal/error/OutOfMemoryError/OutOfMemoryError.c coal/io/io.c coal/io/printf.c coal/private/atomic.h coal/private/classes/Subclass.h coal/private/classes/Subclass/Subclass.c coal/private/library.h coal/private/memory.c coal/private/memory.h coal/private/object_orientation.h coal/private/reference_counting.h coal/private/reference_type.h coal/private/stack.c coal/private/try_catch.c coal/private/virtual_methods.h coal/testing/AssertionError/AssertionError.c coal/throw.c
nobase_libcoal_la_HEADERS = coal/base/Metaclass.h coal/base/Object.h coal/base/String.h coal/base/Throwable.h coal/coal.h coal/collections/Iterator.h coal/error/Error.h coal/error/Exception.h coal/error/IllegalStateException.h coal/error/NoSuchMethodError.h coal/error/NullPointerException.h coal/error/OutOfMemoryError.h coal/io/io.h coal/private/branching.h coal/private/cdefs.h coal/private/preprocessor.h coal/private/stack.h coal/private/thread_local.h coal/private/try_catch.h coal/testing/AssertionError.h coal/testing/assert.h coal/try_catch.h
libcoal_ladir = $(includedir)

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = coal.pc
