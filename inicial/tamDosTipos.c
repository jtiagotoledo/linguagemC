#include <stdio.h>

int main() {
    printf("Um numero inteiro ocupa: %zu bytes\n", sizeof(int));
    printf("Uma letra ocupa: %zu byte\n", sizeof(char));
    printf("Um numero com virgula ocupa: %zu bytes\n", sizeof(float));
    return 0;
}