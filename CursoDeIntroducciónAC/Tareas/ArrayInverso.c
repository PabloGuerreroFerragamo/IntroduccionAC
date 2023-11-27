#include <stdio.h>
#include <string.h>

int invertidor(){
    int i = 0;
    char cadenita[] = "Miguel";
    char partes;
    int lon=strlen(cadenita);

    for (i = 0; i < lon; i++) {
        partes=cadenita[lon-1-i];
        printf("%c",partes);
    }

    return 0;
}

int main(){
    invertidor();

    return 0;
}