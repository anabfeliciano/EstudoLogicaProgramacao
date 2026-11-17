#include <stdio.h>
#include <stdlib.h>

int main() {
    system("cls");

    int contador = 0;
    int i;
    
    for (i = 1; i <= 5; i++) {
        contador++; // Conta 5 vezes
    }

    printf("%d \n", contador); // Vai imprimir 5
    return 0;
}