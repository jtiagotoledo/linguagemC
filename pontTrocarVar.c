#include <stdio.h>

void trocar(int *p1, int *p2){
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main()
{
    int a = 5, b=10;
    printf("O valor de a=%d e o valor de b=%d\n",a,b);
    trocar(&a,&b);
    printf("Valores apos troca:\n");
    printf("O valor de a=%d e o valor de b=%d\n",a,b);
    return 0;
}