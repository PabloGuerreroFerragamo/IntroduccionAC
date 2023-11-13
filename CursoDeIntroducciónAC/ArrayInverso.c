#include <stdio.h>
#include <string.h>

int main(){
    int i = 0;
    char cadenita[] = "hola";
    char partes;
    int papu=0;

    for (i = 0; i < strlen(cadenita); i++) {
        partes=cadenita[strlen(cadenita)-1-i];
        printf("%c",partes);
    }

    return 0;
}