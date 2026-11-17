#include <stdio.h>
#include <stdlib.h>

int main () {

    system ("cls");

    char Letra;

    printf("Digite uma letra entre A, B, C, D, E: ");
    scanf(" %c", &Letra); // O espaço antes de %c ignora o Enter/espaços da entrada

    switch (Letra) {
        case 'A':
        case 'a':
            printf("Excelente!\n");
            break;

        case 'B':
        case 'b':
            printf("Bom!\n");
            break;

        case 'C':
        case 'c':
            printf("Regular!\n");
            break;

        case 'D':
        case 'd':
            printf("Ruim!\n");
            break;

        case 'E':
        case 'e':
            printf("Péssimo!\n");
            break;

        default:
            printf("Letra inválida!\n");
    }

    return 0;
}