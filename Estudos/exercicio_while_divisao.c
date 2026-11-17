#include <stdio.h>
#include <stdlib.h>

int main() {
    system("cls");

    int numero = 100;
    int contador = 0;

    while (numero > 0) {
        numero /= 2;
        contador++;
    }

    printf("Numero de divisoes ate chegar a 0: %d vezes.\n", contador);

    return 0;
}