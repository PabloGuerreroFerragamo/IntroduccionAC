#include <stdio.h>

int mensaje(char* s){//'*' indica que s es un puntero, que apunta a una dirección de memoria (secuencia de caracteres)
    printf("%s\n",s);
    return 0;
}

int main(){
    mensaje("Hola a todos");
    return 0;
}