#ifndef RELATORIO_H  
#define RELATORIO_H  

struct DadosSistema {
    int memoria_usada_gb;
    int memoria_total_gb;
};

void gerar_cabecalho(void);
void imprimir_estatisticas(struct DadosSistema sistema);

#endif