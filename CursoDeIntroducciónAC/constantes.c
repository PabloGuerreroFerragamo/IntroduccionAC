#include <stdio.h>

#define PIZZACOST 1.5

const char NEWLINE = '\n';

int main(){
    float costoPizzas;
    float numberOfSlices = 3;
    costoPizzas = PIZZACOST * numberOfSlices;

    printf("Total bill: %c%f", NEWLINE, costoPizzas);
    
    return 0;
}
