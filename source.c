#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Width  100
#define Hieght 30







int main(){
	int statu = 0;
	float distance = 0;
	int radius = 0;
	 printf("Entre radius of the circle : ");
	 scanf("%d",&radius );
        for(int y = 0 ; y <= Hieght ; ++y){
          for(int x = 0 ; x <= Width  ; ++x){
	     int Center_x = Width /2;
	     int Center_y = Hieght /2; 
	     distance =((x - Center_x )*( x - Center_x) + (y - Center_y ) * ( y - Center_y)) ;
	     if(fabs(distance - radius) < 1.0){
	      printf("*");
	     }else{
	       printf(".");
	     }
	   }
	  printf("\n");
	}



	return statu;


}






















