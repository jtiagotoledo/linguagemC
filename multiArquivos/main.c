#include <stdio.h>
#include "relatorio.h" 

int main() {
    struct DadosSistema meu_pc;
    meu_pc.memoria_total_gb = 16;
    meu_pc.memoria_usada_gb = 4;

    gerar_cabecalho();
    imprimir_estatisticas(meu_pc);

    return 0;
}