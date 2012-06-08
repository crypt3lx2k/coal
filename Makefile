CC = gcc

RM = rm -f
CP = cp -f

COAL_DIR = ../

WFLAGS = -Wall -Wextra -Werror
BINFLAGS = -fPIC
LIBFLAGS = -shared $(BINFLAGS)
IFLAGS = -I$(COAL_DIR)
OPTFLAGS = -O2 -fomit-frame-pointer -funroll-loops

CFLAGS = -g -O0 $(WFLAGS) $(BINFLAGS) $(IFLAGS)
LDFLAGS = $(LIBFLAGS)

OBJS = ./base/Metaclass/Metaclass.o \
	./base/Object/Object.o \
	./base/String/String.o \
	./base/Throwable/Throwable.o \
	./coal.o \
	./error/Error/Error.o \
	./error/Exception/Exception.o \
	./error/IllegalStateException/IllegalStateException.o \
	./error/NoSuchMethodError/NoSuchMethodError.o \
	./error/NullPointerException/NullPointerException.o \
	./error/OutOfMemoryError/OutOfMemoryError.o \
	./io/io.o \
	./io/printf.o \
	./private/classes/Subclass/Subclass.o \
	./private/memory.o

PROJ = libcoal.so

build :
	$(MAKE) $(PROJ)

install : $(PROJ)
	$(CP) $(PROJ) /usr/lib/

libcoal.so : $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

./base/Metaclass.h : ./base/Object.h
	touch $@

./base/Object.h : ./coal.h
	touch $@

./base/String.h : ./base/Object.h
	touch $@

./base/Throwable.h : ./base/Object.h
	touch $@

./coal.h : ./private/cdefs.h
	touch $@

./error/Error.h : ./base/Throwable.h
	touch $@

./error/Exception.h : ./base/Throwable.h
	touch $@

./error/IllegalStateException.h : ./error/Exception.h
	touch $@

./error/NoSuchMethodError.h : ./error/Error.h
	touch $@

./error/NullPointerException.h : ./error/Exception.h
	touch $@

./error/OutOfMemoryError.h : ./error/Error.h
	touch $@

./io/io.h : ./coal.h
	touch $@

./private/classes/Subclass.h : ./base/Metaclass.h \
	./private/object_orientation.h
	touch $@

./private/memory.h : ./private/cdefs.h
	touch $@

./private/object_orientation.h : ./private/atomic.h
	touch $@

./private/reference_counting.h : ./base/Object/Object.rep
	touch $@

./private/reference_type.h : ./private/atomic.h
	touch $@

./private/virtual_methods.h : ./error/NoSuchMethodError.h
	touch $@

./base/Metaclass/Metaclass.rep : ./base/Object/Object.rep
	touch $@

./base/Object/Object.rep : ./private/object_orientation.h \
	./private/reference_type.h
	touch $@

./base/String/String.rep : ./base/Object/Object.rep
	touch $@

./base/Throwable/Throwable.rep : ./base/Object/Object.rep
	touch $@

./base/Metaclass/Metaclass.c : ./base/Metaclass/Metaclass.rep \
	./error/NullPointerException.h
	touch $@

./base/Object/Object.c : ./base/Metaclass.h \
	./base/Metaclass/Metaclass.rep \
	./base/String.h \
	./private/library.h \
	./private/virtual_methods.h
	touch $@

./base/String/String.c : ./base/Metaclass.h \
	./base/String.h \
	./base/String/String.rep \
	./error/OutOfMemoryError.h \
	./private/library.h \
	./private/memory.h
	touch $@

./base/Throwable/Throwable.c : ./base/Metaclass.h \
	./base/Metaclass/Metaclass.rep \
	./base/String.h \
	./base/Throwable/Throwable.rep \
	./error/OutOfMemoryError.h \
	./private/library.h \
	./private/virtual_methods.h
	touch $@

./coal.c : ./base/Metaclass.h \
	./base/Metaclass/Metaclass.rep \
	./error/IllegalStateException.h \
	./error/NullPointerException.h \
	./io/io.h \
	./private/memory.h \
	./private/reference_counting.h \
	./private/virtual_methods.h
	touch $@

./error/Error/Error.c : ./private/classes/Subclass.h \
	./private/library.h \
	./private/virtual_methods.h
	touch $@

./error/Exception/Exception.c : ./private/classes/Subclass.h \
	./private/library.h \
	./private/virtual_methods.h
	touch $@

./error/IllegalStateException/IllegalStateException.c : ./error/Exception.h \
	./private/classes/Subclass.h \
	./private/library.h \
	./private/virtual_methods.h
	touch $@

./error/NoSuchMethodError/NoSuchMethodError.c : ./private/classes/Subclass.h \
	./private/library.h \
	./private/virtual_methods.h
	touch $@

./error/NullPointerException/NullPointerException.c : ./error/Exception.h \
	./private/classes/Subclass.h \
	./private/library.h \
	./private/virtual_methods.h
	touch $@

./error/OutOfMemoryError/OutOfMemoryError.c : ./private/classes/Subclass.h \
	./private/library.h \
	./private/virtual_methods.h
	touch $@

./io/io.c : ./base/Object.h \
	./base/String/String.rep \
	./io/io.h
	touch $@

./io/printf.c : ./base/Object.h \
	./io/io.h
	touch $@

./private/classes/Subclass/Subclass.c : ./base/Metaclass/Metaclass.rep \
	./private/classes/Subclass.h \
	./private/library.h \
	./private/virtual_methods.h
	touch $@

./private/memory.c : ./error/OutOfMemoryError.h \
	./private/memory.h
	touch $@

./base/Metaclass/Metaclass.o : ./base/Metaclass/Metaclass.c
	$(CC) $(CFLAGS) -c $< -o $@

./base/Object/Object.o : ./base/Object/Object.c
	$(CC) $(CFLAGS) -c $< -o $@

./base/String/String.o : ./base/String/String.c
	$(CC) $(CFLAGS) -c $< -o $@

./base/Throwable/Throwable.o : ./base/Throwable/Throwable.c
	$(CC) $(CFLAGS) -c $< -o $@

./coal.o : ./coal.c
	$(CC) $(CFLAGS) -c $< -o $@

./error/Error/Error.o : ./error/Error/Error.c
	$(CC) $(CFLAGS) -c $< -o $@

./error/Exception/Exception.o : ./error/Exception/Exception.c
	$(CC) $(CFLAGS) -c $< -o $@

./error/IllegalStateException/IllegalStateException.o : ./error/IllegalStateException/IllegalStateException.c
	$(CC) $(CFLAGS) -c $< -o $@

./error/NoSuchMethodError/NoSuchMethodError.o : ./error/NoSuchMethodError/NoSuchMethodError.c
	$(CC) $(CFLAGS) -c $< -o $@

./error/NullPointerException/NullPointerException.o : ./error/NullPointerException/NullPointerException.c
	$(CC) $(CFLAGS) -c $< -o $@

./error/OutOfMemoryError/OutOfMemoryError.o : ./error/OutOfMemoryError/OutOfMemoryError.c
	$(CC) $(CFLAGS) -c $< -o $@

./io/io.o : ./io/io.c
	$(CC) $(CFLAGS) -c $< -o $@

./io/printf.o : ./io/printf.c
	$(CC) $(CFLAGS) -c $< -o $@

./private/classes/Subclass/Subclass.o : ./private/classes/Subclass/Subclass.c
	$(CC) $(CFLAGS) -c $< -o $@

./private/memory.o : ./private/memory.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : clean
clean :
	$(RM) $(OBJS) $(PROJ) $(shell find -name "*~")
