#include <stdio.h>

int main()
{
    int numeros[3];

    for (int i = 0; i < 3; i++){
        printf("Digite o %d numero", i);
        scanf("%d", &numeros[i]);
    }
    for(int i =0;i<3;i++){
        printf("Posicao %d vale: %d\n",i,numeros[i]);
    }
    return 0;
}