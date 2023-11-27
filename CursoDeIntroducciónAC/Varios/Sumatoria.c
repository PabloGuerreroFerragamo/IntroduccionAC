/*
    !   Realizar un programa que calcule la siguiente sumatoria
    
    *       ∞
    *   4 * ∑     (-1)
    *      n=0   (2*n)+1
*/

#include<stdio.h>

int main()
{
    int num,i;
    float valor=0;
    int bandera=0;

    printf("Ingresa el valor n: ");
    scanf("%d", &num);

    int aux[num];                                               //Creación de arreglo con los denominadores de la sumatoria
    printf("\n\n4 * [ ");
    
    for(i=0 ; i<=num ; i++)
    {
        aux[i] = (2*i)+1;

        if(i % 2 == 0)                                          //Potencias pares, el signo es positivo.
        {
            valor = valor + (1/(float)((2*i)+1));               //Guarda el valor de la fracción resultante
            printf("1/%d ", aux[i]);
        }
        else                                                    //Potencias impares, el signo es negativo.
        {
            valor = valor + (-1/(float)((2*i)+1));              //Guarda el valor de la fracción resultante
            
            printf("-1/%d ", aux[i]);
        }                       
    
    }
 
    printf("] = %.4f\n\n", 4*valor);

    return 0;
}

/*
    Se declaran las variables num para guardar el valor de cantidad de índices que se
    solicitan, la variable i para usar en el ciclo for 

    Se solicita el valor de num para crear el arreglo aux con capacidad num

    Se cicla con for usando como límite a num.

    Para fines visuales, en aux se guarda el valor entero del denomiador para
    posteriormente ser utilizado.

    La sumatoria cambia el signo del numerador si es par o impar, por lo que haciendo
    uso de la comparativa de if, se tiene que si i%2 == 0, es decir, 
    si i al dividirse entre 2 no tiene residuo, o sea, es par y con ello el numerador queda
    positivo. En caso contrario, es negativo.

    valor va acumulando hasta llegar al límite de índices indicado por el usuario.

    Al imprimir, haciendo uso del aux, queda

    4 * [1/1 -1/3 +1/5 . . . hasta num] = al valor resultante.

*/