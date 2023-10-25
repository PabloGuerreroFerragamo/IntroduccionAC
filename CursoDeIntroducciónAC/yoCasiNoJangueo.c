#include <stdio.h>

int main(){
    unsigned long long int a=0;
    unsigned long long int b=1;
    unsigned long long int c=0;
    int i;
    int contador=0;
    
    for(i=2;i<=999;i++){
        if(contador<1){
            printf("Posicion: %llu = %llu\n",a);
            printf("Posicion: %llu = %llu\n",b);
            contador++;
        }
        c=a+b;
        printf("Posicion: %d = %llu\n",i,c);
        a=b;
        b=c;
    }

    return 0;
}