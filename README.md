# ucspi-unix-alpine

UNIX-domain socket client-server command-line tools in an alpine image

**unixclient** and **unixserver** are command-line tools for building UNIX domain client-server
applications.

**unixclient** connects to a UNIX domain socket and runs a program of your choice.

**unixserver** creates a UNIX domain socket, waits for incoming connections and, for each
connection, runs a program of your choice.

**unixclient** and **unixserver** conform to **UCSPI**, the UNIX Client-Server Program Interface,
using UNIX domain sockets.

**UCSPI** was defined by [djb](http://cr.yp.to/proto/ucspi.txt)

**UCSPI** implementations were documented by [jdebp](https://jdebp.uk/FGA/UCSPI.html)

This program is Copyright(C) 2015 Bruce Guenter, and may be copied
according to the GNU GENERAL PUBLIC LICENSE (GPL) Version 2 or a later
version. A copy of this license is included with this package. This
package comes with no warranty of any kind.
