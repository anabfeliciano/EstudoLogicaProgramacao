#include <stdio.h>

int main() {
    int numero = 5;
    int fatorial = 1;

    for (int i = 1; i <= numero; i++) {
        fatorial *= i;
    }

    printf("O fatorial de %d e: %d\n", numero, fatorial);

    return 0;
}