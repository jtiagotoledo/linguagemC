#include <stdio.h>
#include <stdint.h>

int main() {
    int largura = 200;
    int altura = 200;
    int tamanho_dados = largura * altura * 3; 
    int tamanho_arquivo = 54 + tamanho_dados;  

    FILE *arquivo = fopen("imagem.bmp", "wb"); 
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo BMP!\n");
        return 1;
    }

    unsigned char cabecalho_arquivo[14] = {
        'B', 'M',                         
        tamanho_arquivo & 0xFF,           
        (tamanho_arquivo >> 8) & 0xFF,
        (tamanho_arquivo >> 16) & 0xFF,
        (tamanho_arquivo >> 24) & 0xFF,
        0, 0, 0, 0,                            
        54, 0, 0, 0                      
    };

    unsigned char cabecalho_info[40] = {
        40, 0, 0, 0,                      
        largura & 0xFF,                   
        (largura >> 8) & 0xFF,
        (largura >> 16) & 0xFF,
        (largura >> 24) & 0xFF,
        altura & 0xFF,                    
        (altura >> 8) & 0xFF,
        (altura >> 16) & 0xFF,
        (altura >> 24) & 0xFF,
        1, 0,                             
        24, 0,                            
        0, 0, 0, 0,                       
        tamanho_dados & 0xFF,             
        (tamanho_dados >> 8) & 0xFF,
        (tamanho_dados >> 16) & 0xFF,
        (tamanho_dados >> 24) & 0xFF,
        19, 11, 0, 0,                     
        19, 11, 0, 0,                     
        0, 0, 0, 0,                       
        0, 0, 0, 0                       
    };

    fwrite(cabecalho_arquivo, 1, 14, arquivo);
    fwrite(cabecalho_info, 1, 40, arquivo);

    for (int y = altura - 1; y >= 0; y--) {
        for (int x = 0; x < largura; x++) {
            unsigned char azul, verde, vermelho;

            if (x >= 50 && x <= 150 && y >= 50 && y <= 150) {
                azul = 0;
                verde = 0;
                vermelho = 255; 
            } else {
                azul = 255;
                verde = 255;
                vermelho = 255; 
            }

            fputc(azul, arquivo);
            fputc(verde, arquivo);
            fputc(vermelho, arquivo);
        }
    }

    fclose(arquivo);
    printf("Arquivo 'imagem.bmp' gerado com sucesso!\n");
    return 0;
}