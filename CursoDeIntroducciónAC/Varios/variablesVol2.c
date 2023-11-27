#include <stdio.h>

//Variable Declarations
extern int a, b, c;

float f, g, h;

int main(){
//Variable definition
int a, b, c;//Dices en esta parte del programa voy a utilizar estas variables
//Variable Initialization
    a = 10;
    b = 2147483647;//Al pasarnos de los limites de la capacidad de el tipo de variable int se desvorda y el programa falla

    c = a + b;

    printf("Value of sum is: %d", c); //en donde pongas el %d es donde se imprimira la variable 
    return 0;
}