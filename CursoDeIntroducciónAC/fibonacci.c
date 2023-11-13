#include <stdio.h>

int main(){
    unsigned long long int a=0;
    unsigned long long int b=1;
    unsigned long long int c=0;
    int i;
    
    for(i=0;i<=999;i++){
        printf("Pareja: %d = (%llu,%llu)\n",i+1,a,b);
        c=a+b;
        a=b;
        b=c;
    }

    return 0;
}