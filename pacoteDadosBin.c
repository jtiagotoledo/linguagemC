#include <stdio.h>

void print_binario(unsigned char n) {
    for (int i = 7; i >= 0; i--) {
        int bit = (n >> i) & 1;
        printf("%d", bit);
    }
}

struct Pacote {
    int id;
    char status;
};

int main() {
    struct Pacote p1 = {256, 'b'};
    unsigned char *ptr = (unsigned char *)&p1;

    printf("Visualizacao Binaria da Struct na RAM:\n\n");

    for (int i = 0; i < sizeof(struct Pacote); i++) {
        printf("Byte %d [%3u]: ", i, ptr[i]);
        print_binario(ptr[i]);
        printf("\n");
    }

    return 0;
}