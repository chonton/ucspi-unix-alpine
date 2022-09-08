SHELL=/bin/sh

DEFAULT: all

all: ucspiunix unixcat

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

ucspiunix: ucspiunix.o load unixclient.o unixserver.o env.o utoa.o socket.lib
	./load ucspiunix unixclient.o unixserver.o env.o utoa.o  `cat socket.lib`

ucspiunix.o: compile ucspiunix.c
	./compile ucspiunix.c

unixclient.o: compile unixclient.c
	./compile unixclient.c

unixserver.o: compile unixserver.c haswaitp.h
	./compile unixserver.c

utoa.o: compile utoa.c
	./compile utoa.c

