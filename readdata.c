#include<stdio.h>
#include<stdlib.h>
#include<string.h>

extern float getchannelvalue(char *bytes);
void  readdata(FILE *writeData,FILE *valuefile)
{
	char *channel1;
      char *channel2;
      char *channel3;
      char *channel4;
      float channelvalue1;
      float channelvalue2;
      float channelvalue3;
      float channelvalue4;
      char *ctime;
	 char *p;
	 char StrLine[2538];
	 char *token;
	 int i;
	 while (fgets(StrLine,2538,writeData)!=NULL) 
	 {
	   p=StrLine;
		token =  strsep( &p, ";");
        ctime=token;
    
        //fprintf(valuefile," ct %s\n",ctime);
        for(i=0;i<90;i++){
		token=  strsep(&p, ";");
        channel1=token;
        channelvalue1=getchannelvalue(channel1);    
        fprintf(valuefile," %f",channelvalue1);
        printf(" %s",channel1);
        token =  strsep( &p, ";");
        channel2=token;
        channelvalue2=getchannelvalue(channel2);    
        fprintf(valuefile," %f",channelvalue2);
        printf(" %s",channel2);
        token =  strsep( &p, ";");
        channel3=token;
        channelvalue3=getchannelvalue(channel3);
               
        fprintf(valuefile," %f",channelvalue3);
        printf(" %s",channel3);
        token =  strsep( &p, ";");
        channel4=token;
        channelvalue4=getchannelvalue(channel4);    
        fprintf(valuefile," %f\n",channelvalue4);
        printf(" %s\n",channel4);
           }
           printf("\n");
        //printf("%s %s %s %s %s",channel1,channel2,channel3,channel4,ctime);
	 } 
	
}
int main()
{
	FILE *writeData=fopen("writedata.dat","r");
      FILE *valuefile=fopen("valeufile.dat","a");
	readdata(writeData,valuefile);
	fclose(writeData);
      fclose(valuefile);
	return 0;
}
