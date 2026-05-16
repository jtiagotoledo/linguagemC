#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Quantas notas voce quer registrar?\n");
    scanf("%d",&n);
    
    int *notas = (int*) malloc(n*sizeof(int));

    if (notas == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }
    
    for(int i=0; i<n; i++){
        printf("Digite a nota %d: ",i+1);
        scanf("%d",&notas[i]);
    }

    for(int j=0; j<n; j++){
        printf("A nota %d:%d\n",j+1,notas[j]);
    }
    free(notas);
    return 0;
}