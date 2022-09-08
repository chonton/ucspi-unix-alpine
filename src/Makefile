SHELL=/bin/sh

DEFAULT: all

all: unixclient unixserver unixcat

clean: TARGETS
	rm -f `cat TARGETS`

clean-spac: clean AUTOFILES
	rm -f `cat AUTOFILES`

compile: conf-cc
	( echo '#!/bin/sh'; \
	  echo 'source=$$1; shift'; \
	  echo 'base=`echo "$$source" | sed -e s:\\\\.c$$::`'; \
	  echo exec `head -n 1 conf-cc` -I.  '-o $${base}.o -c $$source $${1+"$$@"}'; \
	) >compile
	chmod 755 compile

env.o: compile env.c haspeercred.h
	./compile env.c

haspeercred.h: compile load haspeercred.h0 haspeercred.h1 trypeercred.c
	( ( ./compile trypeercred.c && ./load trypeercred; ) && cat haspeercred.h1 || cat haspeercred.h0 ) > $@
	@rm -f trypeercred.o trypeercred

haswaitp.h: compile load haswaitp.h0 haswaitp.h1 trywaitp.c
	( ( ./compile trywaitp.c && ./load trywaitp; ) && cat haswaitp.h1 || cat haswaitp.h0 ) > $@
	@rm -f trywaitp.o trywaitp

install: 
	install -d $(or $(prefix),/usr/local)/$(or $(bindir),bin)
	install -m 755 unixcat unixclient unixserver $(or $(prefix),/usr)/$(or $(bindir),bin)
	install -d $(or $(prefix),/usr/local)/$(or $(mandir),man)/man1
	install -m 644 unixclient.1 unixserver.1 $(or $(prefix),/usr)/$(or $(mandir),man)/man1

load: conf-ld
	( echo '#!/bin/sh';\
	  echo 'main="$$1"; shift';\
	  echo exec `head -n 1 conf-ld` -L. '-o "$$main" "$$main.o" $${1+"$$@"}'; \
	) >load
	chmod 755 load

socket.lib: compile load
	@echo -n 'Checking for socket libraries: '
	@echo 'main() { ; }' >trylib-lsocket.c
	@{ ./compile trylib-lsocket.c && ./load trylib-lsocket -lsocket -lnsl; } >/dev/null 2>&1 \
	  && { echo -lsocket -lnsl >socket.lib; echo -lsocket -lnsl; } \
	  || { : >socket.lib; echo no; }
	@rm -f trylib-lsocket.c trylib-lsocket.o trylib-lsocket

unixcat: warn-auto.sh unixcat.sh
	cat warn-auto.sh unixcat.sh >unixcat
	chmod 755 unixcat

unixclient: unixclient.o load env.o utoa.o socket.lib
	./load unixclient env.o utoa.o  `cat socket.lib`

unixclient.o: compile unixclient.c
	./compile unixclient.c

unixserver: unixserver.o load env.o utoa.o socket.lib
	./load unixserver env.o utoa.o  `cat socket.lib`

unixserver.o: compile unixserver.c haswaitp.h
	./compile unixserver.c

utoa.o: compile utoa.c
	./compile utoa.c

