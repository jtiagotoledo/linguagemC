#include <stdio.h>

int main(){
    FILE *arquivo;
    char linha[100];
    arquivo = fopen("arquivoTeste.txt","r");
    if(arquivo == NULL){
        printf("o qrquivo não existe ou não pode ser aberto /n");
        return 1;
    }
    printf("Conteúdo do arquivo\n\n");
    while(fgets(linha,100,arquivo)!=NULL){
        printf("%s",linha);
    }
    fclose(arquivo);
    return 0;
}