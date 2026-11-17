#include <stdio.h>

int eh_par(int n) {
    if (n % 2 == 0) {
        return 1; // É par
    }
    return 0;     // É ímpar
}

int main(void) {
    int resultado = eh_par(4);
    printf("Resultado (1 para par, 0 para impar): %d\n", resultado);
    return 0;
}