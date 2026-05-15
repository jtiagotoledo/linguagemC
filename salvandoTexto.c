#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Quantas notas voce quer registrar?\n");
    scanf("%d",&n);
    
    int *notas = (int*) malloc(n*sizeof(int));
    FILE *arquivo = fopen("minhas_notas.txt","w");

    if (notas == NULL || arquivo == NULL ) {
        printf("Erro na memória ou no arquivo!\n");
        return 1;
    }
    
    for(int i=0; i<n; i++){
        printf("Digite a nota %d: ",i+1);
        scanf("%d",&notas[i]);
        fprintf(arquivo,"A nota %d:%d\n",i+1,notas[i]);
    }

    printf("Notas salvas com sucesso");

    fclose(arquivo);
    free(notas);
    return 0;
}