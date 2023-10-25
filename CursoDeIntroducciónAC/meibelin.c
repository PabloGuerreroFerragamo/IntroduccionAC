#include <stdio.h>

int main(){
    float peso;
    int N;

    printf("Bienvenido al convertidor de Divisas\n Dame una cantidad en pesos para convertir: ");
    scanf("%f",&peso);
    printf("Selecciona una opcion\n1.- coronaDanesa\n2.- libraEsterlina\n");
    scanf("%d",&N);

    if(N==1)
        printf("%f MXN = %f coronaDanesa",peso,peso*0.39);

    if(N==2)
        printf("%f MXN = %f libraEsterlina",peso,peso*0.045);

    if(N<1 && N>2)
        printf("Esa no es una opcion");

    return 0;
}