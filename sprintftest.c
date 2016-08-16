#include<stdio.h>
#include<stdlib.h>
int main()
{
	struct  timeval everytime;
	
	unsigned char tmp[14];
	int i;
   
    sprintf(tmp,"%d%d",everytime.tv_sec,everytime.tv_usec);
	
    for(i=0;i<14;i++){
		printf("%d",tmp[i]);
	}	
	return 0;
}
