#include <stdio.h>
int idade;

int main(){
    printf("Qual a sua idade?");
    scanf("%d",&idade);
    if(idade>=18){
        printf("Voce eh maior de idade");
    }else{
        printf("Voce eh menor de idade");
    }
    return 0;
}