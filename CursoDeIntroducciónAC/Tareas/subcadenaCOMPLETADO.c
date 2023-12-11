#include <stdio.h>
#include <string.h>

int main(){
    
    int i,j,k,N,B,E,opcion=0,contador=0,finalizador=0;
    char L[100] = "";
    char c[10] = "";

    printf("Bienvenido, seleccione una opcion: \n");

    while(finalizador<1){
        printf("1.- Imprimir cadena\n");
        printf("2.- Extender cadena\n");
        printf("3.- Salir\n");

        scanf("%d",&opcion);

        if(opcion==1){
            if(L[0]== '\0')
                printf("La cadena esta vacia\n");
            
            else
                printf("%s\n",L);  
        }

        if(opcion==2){
            char *apuntador=L;
            printf("Dame el numero de veces que se anadira la cadena: ");
            scanf("%d",&N);
            printf("Dame el caracter: ");
            scanf("%s",c);

            for(i=0;i<N;i++)
                strcat(apuntador, c);

            contador++;        
        }

        if(opcion==3){
            printf("Programa finalizado con exito");
            finalizador++;
        }

        if((contador==2)&&(finalizador<1)){
            int lon=strlen(L);
            printf("Dame un numero entre 1 y %d\n",lon);
            scanf("%d",&B);
            printf("Dame otro numero entre 1 y %d\n",lon);
            scanf("%d",&E);

            if(B<E){
                for(j=B-1;j<=E;j++){
                printf("%c",L[j]);
            }
            printf("\n");
        }
        else{
            for(k=E-1;k<=B;k++){
                printf("%c",L[k]);
            }
            printf("\n");
        }           
        }
    }
    return 0;
}