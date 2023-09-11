#include <stdio.h>

int main(){
    char* x ="Ejemplo:Hola a todos";//se declara un puntero a una cadena de caracteres llamado x
    printf("%s",x+8);//x+8 es una operación de puntero que desplaza el puntero x hacia adelante
    return 0;
}