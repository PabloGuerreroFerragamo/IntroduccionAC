#include <stdio.h>

int main(){
    int i,thunder=10000,signo=0;
    float k,operacion=0;

        for(k=1;k<=(2*thunder);k+=2){
            if((signo==0)&&k!=(2*thunder)){
            operacion=operacion+(1/k);
            signo++;
            }
            else if ((signo==1)&&k!=(2*thunder)){
            operacion=operacion-(1/k);
            signo=0;
            }   
        }

        printf("%f",4*operacion);   
  
    return 0;
}