#include <stdio.h>

struct Pacote {
    int id;
    char status;
};

int main() {
    struct Pacote p1 = {10, 'A'}; 
    
    unsigned char *ponteiro_bruto = (unsigned char *)&p1;

    printf("Lendo os bytes da struct na memoria:\n");
    for(int i = 0; i < sizeof(struct Pacote); i++) {
        printf("Byte %d: %u\n", i, ponteiro_bruto[i]);
    }

    return 0;
}