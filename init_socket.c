#include<stdlib.h> 
#include<stdio.h>
#include<string.h>   
#include<sys/socket.h>
#include<arpa/inet.h>
int init_socket(int port)
{
	int socket_desc,client_sock,re,sizeofsockaddr_in;
	struct sockaddr_in server , client;
	
	//create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }
	//set port can use when port  release
	int opt=1;
	re=setsockopt( socket_desc,SOL_SOCKET,SO_REUSEADDR,(char*)&opt,sizeof(opt));
	
	//Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);
	//bind port
	re=bind(socket_desc,(struct sockaddr *)&server , sizeof(server));
	if(re!=0){
		printf("Bind Error");
	}
	puts("Bind Done");
	//Listen
	listen(socket_desc,3);
	
	puts("Waiting for incoming connections...");
	sizeofsockaddr_in=sizeof(struct sockaddr_in);
	
	//Accept
	//accept connection from an incoming client
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&sizeofsockaddr_in);
	if (client_sock < 0)
    {
        perror("accept failed");
        return 1;
    }
	puts("Connection");
	return client_sock;
}
/*
 int main()
 {
	init_socket(6007) ;
 }*/
