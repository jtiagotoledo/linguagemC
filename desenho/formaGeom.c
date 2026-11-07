#include <stdio.h>
#include <stdint.h>

int main() {
    int largura = 200;
    int altura = 200;
    int tamanho_dados = largura * altura * 3; // 3 bytes por pixel (Azul, Verde, Vermelho)
    int tamanho_arquivo = 54 + tamanho_dados;  // 54 bytes do cabeçalho + dados

    FILE *arquivo = fopen("imagem.bmp", "wb"); // "wb" = Write Binary (Escrita Binária)
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo BMP!\n");
        return 1;
    }

    // --- 1. CABEÇALHO DO ARQUIVO (14 bytes) ---
    unsigned char cabecalho_arquivo[14] = {
        'B', 'M',                         // Assinatura do arquivo BMP
        tamanho_arquivo & 0xFF,           // Tamanho do arquivo (4 bytes)
        (tamanho_arquivo >> 8) & 0xFF,
        (tamanho_arquivo >> 16) & 0xFF,
        (tamanho_arquivo >> 24) & 0xFF,
        0, 0,                             // Reservado
        0, 0,                             // Reservado
        54, 0, 0, 0                       // Offset onde começam os pixels (54º byte)
    };

    // --- 2. CABEÇALHO DE INFORMAÇÕES DA IMAGEM (40 bytes) ---
    unsigned char cabecalho_info[40] = {
        40, 0, 0, 0,                      // Tamanho deste cabeçalho (40 bytes)
        largura & 0xFF,                   // Largura (4 bytes)
        (largura >> 8) & 0xFF,
        (largura >> 16) & 0xFF,
        (largura >> 24) & 0xFF,
        altura & 0xFF,                    // Altura (4 bytes)
        (altura >> 8) & 0xFF,
        (altura >> 16) & 0xFF,
        (altura >> 24) & 0xFF,
        1, 0,                             // Planos de cores (deve ser 1)
        24, 0,                            // Bits por pixel (24 bits = RGB verdadeiro)
        0, 0, 0, 0,                       // Sem compressão
        tamanho_dados & 0xFF,             // Tamanho dos dados de imagem (4 bytes)
        (tamanho_dados >> 8) & 0xFF,
        (tamanho_dados >> 16) & 0xFF,
        (tamanho_dados >> 24) & 0xFF,
        19, 11, 0, 0,                     // Resolução horizontal (pixels por metro)
        19, 11, 0, 0,                     // Resolução vertical (pixels por metro)
        0, 0, 0, 0,                       // Cores na paleta
        0, 0, 0, 0                        // Cores importantes
    };

    // Escreve os cabeçalhos no arquivo
    fwrite(cabecalho_arquivo, 1, 14, arquivo);
    fwrite(cabecalho_info, 1, 40, arquivo);

    // --- 3. OS PIXELS (Gerados linha por linha, de baixo para cima) ---
    for (int y = altura - 1; y >= 0; y--) {
        for (int x = 0; x < largura; x++) {
            unsigned char azul, verde, vermelho;

            // Condição do quadrado central (Vermelho)
            if (x >= 50 && x <= 150 && y >= 50 && y <= 150) {
                azul = 0;
                verde = 0;
                vermelho = 255; // Cor Vermelha pura (em BGR: R=255, G=0, B=0)
            } else {
                azul = 255;
                verde = 255;
                vermelho = 255; // Fundo Branco (B=255, G=255, R=255)
            }

            // Escreve os 3 bytes do pixel no arquivo na ordem BGR
            fputc(azul, arquivo);
            fputc(verde, arquivo);
            fputc(vermelho, arquivo);
        }
    }

    fclose(arquivo);
    printf("Arquivo 'imagem.bmp' gerado com sucesso!\n");
    return 0;
}