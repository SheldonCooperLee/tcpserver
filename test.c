#include <stdbool.h>
#include <netinet/in.h>    // for sockaddr_in
#include <sys/types.h>    // for socket
#include <sys/socket.h>    // for socket
#include <stdio.h>        // for printf
#include <stdlib.h>        // for exit
#include <string.h>        // for bzero
#include <errno.h>
extern int init_socket(int port);
extern void recevice_data_write(int client_sock,FILE *writeData,FILE* data);
int main()
{
	int port=6007;
	int client_socket=init_socket(6007);
        int length;
	FILE *writeData=fopen("./writedata.dat","a");
	FILE *data=fopen("./handledata.dat","a");
      recevice_data_write(client_socket,writeData,data);
        //printf("length:%d\n",length);
      fclose(writeData);
	  fclose(data);
	return 0;
	
}
