#include <stdio.h>
#include <string.h>

int invertidor(){
    int i = 0;
    char cadenita[] = "Miguel";
    char newCadenita[100]="";
    int lon=strlen(cadenita);

    for (i = 0; i < lon; i++) {
        newCadenita[i]=cadenita[lon-1-i];
    }

    printf("%s",newCadenita);

    return 0;
}

int main(){
    invertidor();

    return 0;
}