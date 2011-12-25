CC = gcc
COAL = ../
IFLAGS = -I$(COAL)
CFLAGS = -O2 -DNDEBUG -fomit-frame-pointer
DBFLAGS = -g -O0 -rdynamic
LDFLAGS = 
WFLAGS = -Wall -Wextra
LIBFLAGS = -shared -fPIC

DOLLAR = $
RM = rm -f
CP = cp -f

FILES = $(shell find -name "*.c")
OBJS  = $(shell find -name "*.c" | sed "s/\.c/\.o/")
PROJ = libcoal.so

build:
	$(MAKE) $(PROJ)

debug:
	$(MAKE) $(PROJ) \
	CFLAGS="$(DBFLAGS)"

install: build
	$(CP) libcoal.so /usr/lib/

debug-install: debug
	$(CP) libcoal.so /usr/lib/

.c.o:
	$(CC) $(CFLAGS) $(IFLAGS) $(WFLAGS) -c $<

libcoal.so: $(OBJS)
	$(CC) $(IFLAGS) *.o $(LDFLAGS) $(CFLAGS) $(LIBFLAGS) -o libcoal.so

clean-obj:
	$(RM) $(shell find -name "*.o")

clean-emacs-autosave:
	$(RM) $(shell find -name "*~")

clean:
	$(MAKE) clean-obj
	$(MAKE) clean-emacs-autosave
	$(RM) libcoal.so
