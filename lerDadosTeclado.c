#include <stdio.h>

int main() {
    int num; 

    printf("Digite um numero: ");
    
    if (scanf("%d", &num) == 1) {
        printf("O numero digitado foi: %d\n", num);
    } else {
        printf("Erro: Voce nao digitou um numero inteiro.\n");
    }

    return 0;
}