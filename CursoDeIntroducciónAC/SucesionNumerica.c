#include <stdio.h>

int main(){
    int i,thunder=7,signo=0;
    float k,operacion=0;

    for(i=1;i<=(2*thunder)-1;i+=2){

        printf("1/%d ",i);

        if((signo==0)&&i!=(2*thunder)-1){
            printf("- ");
            signo++;
        }
        else if ((signo==1)&&i!=(2*thunder)-1){
            printf("+ ");
            signo=0;
        }    
        if(i==(2*thunder)-1){
            printf("= ");
            signo=0;
        }          
    }

        signo=0;

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

        printf("%f",operacion);   
  
    return 0;
}