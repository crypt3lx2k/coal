AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I m4

lib_LTLIBRARIES = libcoal.la

libcoal_la_SOURCES = coal/error/Exception/Exception.c coal/error/IllegalStateException/IllegalStateException.c coal/error/Error/Error.c coal/error/NoSuchMethodError/NoSuchMethodError.c coal/error/OutOfMemoryError/OutOfMemoryError.c coal/error/NullPointerException/NullPointerException.c coal/testing/AssertionError/AssertionError.c coal/base/Metaclass/Metaclass.c coal/base/Object/Object.c coal/base/Throwable/Throwable.c coal/base/String/String.c coal/coal.c coal/io/io.c coal/io/printf.c coal/private/memory.c coal/private/classes/Subclass/Subclass.c
nobase_libcoal_la_HEADERS = coal/error/NoSuchMethodError.h coal/error/Exception.h coal/error/OutOfMemoryError.h coal/error/IllegalStateException.h coal/error/NullPointerException.h coal/error/Error.h coal/testing/AssertionError.h coal/base/Object.h coal/base/Metaclass.h coal/base/Metaclass/Metaclass.rep.h coal/base/Object/Object.rep.h coal/base/Throwable/Throwable.rep.h coal/base/String.h coal/base/String/String.rep.h coal/base/Throwable.h coal/io/io.h coal/private/reference_counting.h coal/private/library.h coal/private/classes/Subclass.h coal/private/atomic.h coal/private/memory.h coal/private/virtual_methods.h coal/private/cdefs.h coal/private/reference_type.h coal/private/object_orientation.h coal/coal.h
libcoal_ladir = $(includedir)

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = coal.pc
