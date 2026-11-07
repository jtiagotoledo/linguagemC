#include <stdio.h>
#include "relatorio.h"

void gerar_cabecalho(void) {
    printf("=========================================\n");
    printf("     RELATORIO DE SISTEMA OPERACIONAL    \n");
    printf("=========================================\n");
}

void imprimir_estatisticas(struct DadosSistema sistema) {
    float percentual = ((float)sistema.memoria_usada_gb / sistema.memoria_total_gb) * 100.0;
    
    printf("Memoria Total: %d GB\n", sistema.memoria_total_gb);
    printf("Memoria Usada: %d GB\n", sistema.memoria_usada_gb);
    printf("Uso do Sistema: %.2f%%\n", percentual);
    printf("-----------------------------------------\n");
}