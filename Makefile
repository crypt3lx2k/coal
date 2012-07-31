CC = gcc

RM = rm -f
CP = cp -f

COAL_DIR = .

WFLAGS = -Wall -Wextra -Werror
BINFLAGS = -fPIC
LIBFLAGS = -shared $(BINFLAGS)
IFLAGS = -I$(COAL_DIR)
OPTFLAGS = -O2 -fomit-frame-pointer -funroll-loops

CFLAGS = -g -O0 $(WFLAGS) $(BINFLAGS) $(IFLAGS)
LDFLAGS = $(LIBFLAGS)

OBJS = ./coal/base/Metaclass/Metaclass.o \
	./coal/base/Object/Object.o \
	./coal/base/String/String.o \
	./coal/base/Throwable/Throwable.o \
	./coal/coal.o \
	./coal/error/Error/Error.o \
	./coal/error/Exception/Exception.o \
	./coal/error/IllegalStateException/IllegalStateException.o \
	./coal/error/NoSuchMethodError/NoSuchMethodError.o \
	./coal/error/NullPointerException/NullPointerException.o \
	./coal/error/OutOfMemoryError/OutOfMemoryError.o \
	./coal/io/io.o \
	./coal/io/printf.o \
	./coal/private/classes/Subclass/Subclass.o \
	./coal/private/memory.o \
	./coal/testing/AssertionError/AssertionError.o

PROJ = libcoal.so

build :
	$(MAKE) $(PROJ)

install : $(PROJ)
	$(CP) $(PROJ) /usr/lib/

libcoal.so : $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

./coal/base/Metaclass.h : coal/base/Object.h
	touch $@

./coal/base/Object.h : coal/coal.h
	touch $@

./coal/base/String.h : coal/base/Object.h
	touch $@

./coal/base/Throwable.h : coal/base/Object.h
	touch $@

./coal/coal.h : coal/private/cdefs.h
	touch $@

./coal/error/Error.h : coal/base/Throwable.h
	touch $@

./coal/error/Exception.h : coal/base/Throwable.h
	touch $@

./coal/error/IllegalStateException.h : coal/error/Exception.h
	touch $@

./coal/error/NoSuchMethodError.h : coal/error/Error.h
	touch $@

./coal/error/NullPointerException.h : coal/error/Exception.h
	touch $@

./coal/error/OutOfMemoryError.h : coal/error/Error.h
	touch $@

./coal/io/io.h : coal/coal.h
	touch $@

./coal/private/classes/Subclass.h : coal/base/Metaclass.h \
	coal/private/object_orientation.h
	touch $@

./coal/private/memory.h : coal/private/cdefs.h
	touch $@

./coal/private/object_orientation.h : coal/private/atomic.h
	touch $@

./coal/private/reference_counting.h : coal/base/Object/Object.rep \
	coal/private/atomic.h
	touch $@

./coal/private/reference_type.h : coal/private/atomic.h
	touch $@

./coal/private/virtual_methods.h : coal/error/NoSuchMethodError.h
	touch $@

./coal/testing/AssertionError.h : coal/error/Error.h
	touch $@

./coal/base/Metaclass/Metaclass.rep : coal/base/Object/Object.rep
	touch $@

./coal/base/Object/Object.rep : coal/private/object_orientation.h \
	coal/private/reference_type.h
	touch $@

./coal/base/String/String.rep : coal/base/Object/Object.rep
	touch $@

./coal/base/Throwable/Throwable.rep : coal/base/Object/Object.rep
	touch $@

./coal/base/Metaclass/Metaclass.c : coal/base/Metaclass/Metaclass.rep \
	coal/base/Object.h \
	coal/error/NullPointerException.h
	touch $@

./coal/base/Object/Object.c : coal/base/Metaclass.h \
	coal/base/Metaclass/Metaclass.rep \
	coal/base/Object.h \
	coal/base/Object/Object.rep \
	coal/base/String.h \
	coal/private/library.h \
	coal/private/virtual_methods.h
	touch $@

./coal/base/String/String.c : coal/base/Metaclass.h \
	coal/base/Object.h \
	coal/base/String.h \
	coal/base/String/String.rep \
	coal/error/OutOfMemoryError.h \
	coal/private/library.h \
	coal/private/memory.h \
	coal/private/object_orientation.h
	touch $@

./coal/base/Throwable/Throwable.c : coal/base/Metaclass.h \
	coal/base/Metaclass/Metaclass.rep \
	coal/base/Object.h \
	coal/base/String.h \
	coal/base/Throwable.h \
	coal/base/Throwable/Throwable.rep \
	coal/error/OutOfMemoryError.h \
	coal/private/library.h \
	coal/private/object_orientation.h \
	coal/private/virtual_methods.h
	touch $@

./coal/coal.c : coal/base/Metaclass.h \
	coal/base/Metaclass/Metaclass.rep \
	coal/base/Object.h \
	coal/base/Object/Object.rep \
	coal/coal.h \
	coal/error/IllegalStateException.h \
	coal/error/NullPointerException.h \
	coal/io/io.h \
	coal/private/memory.h \
	coal/private/reference_counting.h \
	coal/private/virtual_methods.h
	touch $@

./coal/error/Error/Error.c : coal/base/Throwable.h \
	coal/private/classes/Subclass.h \
	coal/private/library.h \
	coal/private/virtual_methods.h
	touch $@

./coal/error/Exception/Exception.c : coal/base/Throwable.h \
	coal/private/classes/Subclass.h \
	coal/private/library.h \
	coal/private/virtual_methods.h
	touch $@

./coal/error/IllegalStateException/IllegalStateException.c : coal/error/Exception.h \
	coal/private/classes/Subclass.h \
	coal/private/library.h \
	coal/private/virtual_methods.h
	touch $@

./coal/error/NoSuchMethodError/NoSuchMethodError.c : coal/error/Error.h \
	coal/private/classes/Subclass.h \
	coal/private/library.h \
	coal/private/virtual_methods.h
	touch $@

./coal/error/NullPointerException/NullPointerException.c : coal/error/Exception.h \
	coal/private/classes/Subclass.h \
	coal/private/library.h \
	coal/private/virtual_methods.h
	touch $@

./coal/error/OutOfMemoryError/OutOfMemoryError.c : coal/error/Error.h \
	coal/private/classes/Subclass.h \
	coal/private/library.h \
	coal/private/virtual_methods.h
	touch $@

./coal/io/io.c : coal/base/Object.h \
	coal/base/String/String.rep \
	coal/io/io.h
	touch $@

./coal/io/printf.c : coal/base/Object.h \
	coal/io/io.h
	touch $@

./coal/private/classes/Subclass/Subclass.c : coal/base/Metaclass/Metaclass.rep \
	coal/base/Object.h \
	coal/private/classes/Subclass.h \
	coal/private/library.h \
	coal/private/virtual_methods.h
	touch $@

./coal/private/memory.c : coal/error/OutOfMemoryError.h \
	coal/private/memory.h
	touch $@

./coal/testing/AssertionError/AssertionError.c : coal/error/Error.h \
	coal/private/classes/Subclass.h \
	coal/private/library.h \
	coal/private/virtual_methods.h
	touch $@

./coal/base/Metaclass/Metaclass.o : ./coal/base/Metaclass/Metaclass.c
	$(CC) $(CFLAGS) -c $< -o $@

./coal/base/Object/Object.o : ./coal/base/Object/Object.c
	$(CC) $(CFLAGS) -c $< -o $@

./coal/base/String/String.o : ./coal/base/String/String.c
	$(CC) $(CFLAGS) -c $< -o $@

./coal/base/Throwable/Throwable.o : ./coal/base/Throwable/Throwable.c
	$(CC) $(CFLAGS) -c $< -o $@

./coal/coal.o : ./coal/coal.c
	$(CC) $(CFLAGS) -c $< -o $@

./coal/error/Error/Error.o : ./coal/error/Error/Error.c
	$(CC) $(CFLAGS) -c $< -o $@

./coal/error/Exception/Exception.o : ./coal/error/Exception/Exception.c
	$(CC) $(CFLAGS) -c $< -o $@

./coal/error/IllegalStateException/IllegalStateException.o : ./coal/error/IllegalStateException/IllegalStateException.c
	$(CC) $(CFLAGS) -c $< -o $@

./coal/error/NoSuchMethodError/NoSuchMethodError.o : ./coal/error/NoSuchMethodError/NoSuchMethodError.c
	$(CC) $(CFLAGS) -c $< -o $@

./coal/error/NullPointerException/NullPointerException.o : ./coal/error/NullPointerException/NullPointerException.c
	$(CC) $(CFLAGS) -c $< -o $@

./coal/error/OutOfMemoryError/OutOfMemoryError.o : ./coal/error/OutOfMemoryError/OutOfMemoryError.c
	$(CC) $(CFLAGS) -c $< -o $@

./coal/io/io.o : ./coal/io/io.c
	$(CC) $(CFLAGS) -c $< -o $@

./coal/io/printf.o : ./coal/io/printf.c
	$(CC) $(CFLAGS) -c $< -o $@

./coal/private/classes/Subclass/Subclass.o : ./coal/private/classes/Subclass/Subclass.c
	$(CC) $(CFLAGS) -c $< -o $@

./coal/private/memory.o : ./coal/private/memory.c
	$(CC) $(CFLAGS) -c $< -o $@

./coal/testing/AssertionError/AssertionError.o : ./coal/testing/AssertionError/AssertionError.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : clean
clean :
	$(RM) $(OBJS) $(PROJ) $(shell find -name "*~")
