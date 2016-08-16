#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include  <stdio.h>
#include <strings.h>
#include <string.h>
//extern char  firstchar(unsigned char data);
//extern char  secondchar(unsigned char data);
void  recevice_data_write(int client_sock,FILE *writeData,FILE* data)
{
	unsigned char recvBuf[1500],tmpBuf[1500],writeBuf[3000],dataBuf[3000];
	//unsigned char *str;
	
    struct  timeval everytime;
	int length=0;
	int counter=0;
	int i;
	int a;
	int c;
      while(1){
	length=recv(client_sock,recvBuf,1441,0);
	
	if(length<1441){
            printf("error");
              // return -1;
         }
	
	
	 gettimeofday(&everytime,0);
	 
	 sprintf(writeBuf,"%d%d",everytime.tv_sec,everytime.tv_usec);
	for(i=1;i<1441;i=i++)
	{
        c=2*(i-1);
		sprintf(dataBuf+c,"%02X",recvBuf[i]);
	   	if((i-1)%4==0){
			writeBuf[(i-1)/4*7+16]=';';
		}else{
                  a=(i-1)/4*7+((i-1)%4*2-1)+16;
			//writeBuf[(i-1)/4+(i-1)%4*2-1]=firstchar(tmpBuf[i]);
			//writeBuf[(i-1)/4+(i-1)%4*2]=secondchar(tmpBuf[i]);
			sprintf(writeBuf+a,"%02X",recvBuf[i]);
			

		}
        }     
      writeBuf[2536]='\n';
        dataBuf[2882]='\n';
	fputs(dataBuf,data);
        //printf("%s",dataBuf);
      fputs(writeBuf,writeData);
        sleep(1);
     }
}
