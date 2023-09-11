#include <stdio.h>
#define TRES 3

int main(){
char men1[] = "Hola ";
char men3[] = " todos";
printf("%s%c%s\n", men1, men3[TRES]-TRES,men3);
return 0;
}
