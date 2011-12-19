CC = gcc
COAL = ../
IFLAGS = -I$(COAL)
CFLAGS = -O2 -DNDEBUG -fomit-frame-pointer
DBFLAGS = -g -rdynamic
LDFLAGS = 
WFLAGS = -Wall -Wextra
LIBFLAGS = -shared -fPIC

DOLLAR = $
RM = rm -f

FILES = $(shell find | grep "\.c")
OBJS  = $(shell find | grep "\.c" | sed "s/\.c/\.o/")
PROJ = libcoal.so

build:
	$(MAKE) $(PROJ) \
	LDFLAGS="$(LDFLAGS)"

debug:
	$(MAKE) $(PROJ) \
	CFLAGS="$(DBFLAGS)" \
	LDFLAGS="$(LDFLAGS)"

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
