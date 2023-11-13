#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int i=0;
    int aleatoriedad[1000];
    int impares[1000];
    int imparesNum=0;
    int pares[1000];
    int paresNum=0;

    srand(time(NULL));

    for(i=0;i<1000;i++){
        aleatoriedad[i]=rand()%100;
        if((aleatoriedad[i])%2){
            impares[imparesNum]=aleatoriedad[i];
            imparesNum++;
        }
        else{
            pares[paresNum]=aleatoriedad[i];
            paresNum++;
        }
    }

        printf("Impares: ");

    for(i=0;i<imparesNum;i++)
        printf("%d ",impares[i]);

        printf("\n\nPares: ");

    for(i=0;i<paresNum;i++)
        printf("%d ",pares[i]);
    
    return 0;
    
}