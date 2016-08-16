#include<stdio.h>
#include<stdlib.h>
int main(){
	
	char a[4]="1234";
      char *str;
      str=a;
	FILE *file =fopen("test.dat","a");
      fputs(str,file);
      fclose(file);
	
}
