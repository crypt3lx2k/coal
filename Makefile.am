AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I m4

lib_LTLIBRARIES = libcoal.la

libcoal_la_SOURCES = coal/base/String/String.c coal/base/Throwable/Throwable.rep.h coal/private/classes/Subclass/Subclass.c coal/private/reference_counting.h coal/testing/AssertionError/AssertionError.c coal/error/NullPointerException/NullPointerException.c coal/private/virtual_methods.h coal/error/NoSuchMethodError/NoSuchMethodError.c coal/private/object_orientation.h coal/coal.c coal/base/Metaclass/Metaclass.c coal/error/Exception/Exception.c coal/private/reference_type.h coal/error/Error/Error.c coal/io/printf.c coal/private/memory.c coal/io/io.c coal/error/OutOfMemoryError/OutOfMemoryError.c coal/private/memory.h coal/error/IllegalStateException/IllegalStateException.c coal/base/Object/Object.c coal/base/Throwable/Throwable.c coal/base/String/String.rep.h coal/base/Object/Object.rep.h coal/private/atomic.h coal/private/library.h coal/private/classes/Subclass.h coal/base/Metaclass/Metaclass.rep.h
nobase_libcoal_la_HEADERS = coal/error/Exception.h coal/base/Object.h coal/testing/assert.h coal/error/OutOfMemoryError.h coal/io/io.h coal/error/NoSuchMethodError.h coal/testing/AssertionError.h coal/error/Error.h coal/coal.h coal/error/NullPointerException.h coal/private/preprocessor.h coal/base/String.h coal/private/cdefs.h coal/private/branching.h coal/error/IllegalStateException.h coal/base/Throwable.h coal/base/Metaclass.h
libcoal_ladir = $(includedir)

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = coal.pc
