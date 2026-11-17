#include <stdio.h>

int maior(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int main(void) {
    int resultado = maior(10, 7);
    printf("O maior numero e: %d\n", resultado);
    return 0;
}