#include <stdio.h>
#include <stdlib.h>

int main()
{
    int largura = 200;
    int altura = 200;

    FILE *arquivo = fopen("arquivo.ppm", "w");
    if (arquivo == NULL)
    {
        printf("Não foi possível criar arquivo\n");
        return 1;
    }
    
    fprintf(arquivo,"P3\n%d %d\n255\n",largura,altura);

    for (int y = 0; y < altura; y++)
    {
        for (int x = 0; x < largura; x++)
        {
            if (x >= 50 && x <= 150 && y >= 50 && y <= 150)
            {
                fprintf(arquivo, "255 0 0 ");
            }
            else
            {
                fprintf(arquivo, "255 255 255 ");
            }
        }
        fprintf(arquivo, "\n");
    }
    fclose(arquivo);
    printf("arquivo gravado com sucesso!\n");
    return 0;
}