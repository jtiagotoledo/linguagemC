#include <stdio.h>
int num = 30;
int *numP = &num;

int main(){
    printf("%p",numP);
    return 0;
}