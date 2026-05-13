#include <stdio.h>
int opcao = 0;

int main(){
    switch(opcao){
        case 1:
        printf("Voce escolheu Cafe\n");
        break;
        case 2:
        printf("Voce escolheu Suco\n");
        break;
        default:
        printf("Opcao invalida\n");
    }
    return 0;
}