#include <stdlib.h> 
#include<stdio.h>

int   timeval_subtract(struct   timeval*   result,   struct   timeval*   x,   struct   timeval*   y)  //¼ÆËãlinuxÊ±²îº¯Êı 
  {   
        int   nsec;   
    
        if   (   x->tv_sec>y->tv_sec   )   
                  return   -1;   
    
        if   (   (x->tv_sec==y->tv_sec)   &&   (x->tv_usec>y->tv_usec)   )   
                  return   -1;   
    
        result->tv_sec   =   (   y->tv_sec-x->tv_sec   );   
        result->tv_usec   =   (   y->tv_usec-x->tv_usec   );   
    
        if   (result->tv_usec<0)   
        {   
                  result->tv_sec--;   
                  result->tv_usec+=1000000;   
        }   
    
        return   0; 		
  }  
//test 
/*  int main(){
	  struct   timeval start;
	  gettimeofday(&start,0);
	  printf("%d",start.tv_sec);
	  
	  
  }*/
