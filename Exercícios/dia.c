#include <stdio.h>
#include <stdlib.h>

int main () {

    system ("cls");

    int X;
    printf ("Digite um número entre 1 a 7: ");
    scanf ("%d", &X);

    switch (X) {
        case 1:
            printf ("O dia corresponde é Segunda-Feira.");
            break;
        case 2:
            printf ("O dia corresponde é Terça-Feira.");
            break;
        case 3:
            printf ("O dia corresponde é Quarta-Feira.");
            break;
        case 4:
            printf ("O dia corresponde é Quinta-Feira.");
            break;
        case 5:
            printf ("O dia corresponde é Sexta-Feira.");
            break;
        case 6:
            printf ("O dia corresponde é Sábado.");
            break;
        case 7:
            printf ("O dia corresponde é Domingo.");
            break;
        default: printf ("Número inválido!");
        
    }

    return 0;

}