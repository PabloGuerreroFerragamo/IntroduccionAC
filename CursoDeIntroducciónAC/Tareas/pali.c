#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(){
    char cadenita[100]="osó";
    char newCadenita[100]="";
    int i,j,contador=0,lon=strlen(cadenita);

    for(i=0;i<lon;i++){
        newCadenita[i]=cadenita[lon-1-i];
        if((cadenita[lon-1-i]==cadenita[i])){
                contador++;
            }
    }
    printf("%s", toupper(cadenita));
    if(contador==lon)
        printf("Es palindormo");
    else
        printf("No es palindromo");

    return 0;
}