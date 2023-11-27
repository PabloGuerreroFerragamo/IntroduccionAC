#include <stdio.h>

enum weekDays {Monday, Tusday, Wednesday, Thursday, Friday, Saturday, Sunday};

int main(){
    enum weekDays today;
    today = Sunday;
    printf("Day %d", today+1);
    return 0;
}