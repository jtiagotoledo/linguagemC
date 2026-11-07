#include <stdio.h>
int num = 30;
int *numP = &num;

int main(){
    putchar('*');
    printf("\n");
    printf("%d \n",num);
    printf("%p",numP);
    putchar('*');
    printf("\n");

    printf("%d",*numP);
    return 0;
}