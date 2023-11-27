#include <stdio.h>

int i, j, k;
unsigned int minimunMinuts = 30;


char y = 'y';
unsigned char dailyWorkedHours = 0;

int main(){

    /*First hello world in C lenguage
    printf(Hello Platzi)*/
    printf("hello platzi");
    return 0;
}
Basic Types: 
    Aritmeticos (Tipos de datos númericos pero en forma fanzy o nice): 
    (A) Valores enteros
                    char 1 Byte -128 to 127 (Como es un byte tiene un total de 256 valores)
                    unsigned char 1 Byte 0 to 255
                    int 4 Bytes -2,147,483,648 to 2,147,483,647
                    unsigned int 4 Bytes 0 to 4,294,967,295

                    short 2 Bytes -32,768 to 32,767
                    unsigned short 2 bytes 0 to 65,535

                    long 8 bytes -mucho to mucho
                    unsigned long 0 to mucho

    (B) De punto flotante float

                    float 4 byte 1.2E-38 to 3.4E+38     6 decimal places
                    double 8 bytes 2.3E-308 to 1.7E+308 15 decimal places
                    long double 10 bytes 3.4E-4932  to 1.1E+4932 19 decimal places

                    void: Especifica que no hay valor disponible, se utiliza en 3 escenarios
                        1.- Funcion retorna un tipo de dato void
                        void function()
                        2.- Funcion tiene argumentos de tipo void
                        int rand(void)
    