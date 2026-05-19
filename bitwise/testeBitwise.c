#include <stdio.h>

void print_bits(char c) {
    for (int i = 7; i >= 0; i--) {
        int bit = (c >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

int main(void) {
    char a = 'A'; 

    printf("Valor em decimal: %d\n", a); 
    
    printf("Valor em caractere: %c\n", a); 
    
    printf("Em bits: "); 
    print_bits(a);

    return 0;
}