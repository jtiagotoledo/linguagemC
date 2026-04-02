#include <stdio.h>

int main(){
    FILE *arquivo;
    arquivo = fopen("arquivoTeste.txt","w");
    if(arquivo == NULL){
        printf("erro ao abrir o arquivo /n");
        return 1;
    }
    fprintf(arquivo,"Texto de teste");
    fclose(arquivo);
    printf("Sucesso ao criar o arquivo");
    return 0;
}