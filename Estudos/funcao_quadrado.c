#include <stdio.h>

double quadrado(double x) {
    return x * x;
}

int main(void) {
    double resultado = quadrado(5.0);
    printf("O quadrado e: %.2f\n", resultado);
    return 0;
}