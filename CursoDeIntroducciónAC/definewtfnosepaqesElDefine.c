#include<stdio.h>
#include<stdlib.h>

#define PIZZACOST 1.5
#define p printf 

const char NEWLINE = '\n';

intmain(int argc, const char* argv[])
{
    float costPizza;
    float numberOfSlices = 3;

    costPizza = PIZZACOST * numberOfSlices;

    p("%.2f", costPizza);
    p("%c", NEWLINE);

    return 0;
}