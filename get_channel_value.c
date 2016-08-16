#include<stdio.h>


//convert bytes to value
float getchannelvalue(char *bytes)
{
  int i=0;
  int flag=0;
  long tmpvalue;
  long value;
  float channelvalue; 
  char *errochar1;
   char *errochar2;
    char *str;
    char tmpp;
  char tmp[5];
   for(i=0;i<6;i=i+2){
         tmp[5-i]=bytes[i+1];
         tmp[4-i]=bytes[i];  
  }
    tmpp=tmp[0];
      str=&tmpp;
  tmpvalue= strtol(str,&errochar1,16);
   value=strtol(tmp,&errochar2,16);
     //printf("%d\n",tmpvalue);
    //printf("%d\n",value);
  //printf("%d",tmpvalue);
  if(tmpvalue<8){
         channelvalue=(float)value*4.096*2.979/1.25/8388607;     
    }else{
         channelvalue=((float)value-16777215)*4.096*2.979/1.25/8388607;
    }

    return channelvalue;
}
/*
int main(){
	unsigned char *bytes="7313F4";
	printf("%f",getchannelvalue(bytes));
	
}*/
