#include <string.h>
#include <stdio.h>

extern int server_main(int argc, char* argv[]);
extern int client_main(int argc, char* argv[]);

int main(int argc, char* argv[])
{
  if(argc>0) {
    if(strcmp(argv[0], "unixserver")==0) {
      return server_main(argc, argv);
    }
    if(strcmp(argv[0], "unixclient")==0) {
      return client_main(argc, argv);
    }
  }
  fprintf(stderr, "ucspi-unix is documented at https://github.com/chonton/ucspi-unix-alpine\n"
	  "  ucspiunix should be invoked through unixclient or unixserver symbolic links");
  return 1;
}
