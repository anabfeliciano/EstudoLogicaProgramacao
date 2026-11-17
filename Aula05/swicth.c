#include <stdio.h>
#include <stdlib.h>

int main () {

    system("cls");

    char Letra; // Armazenará a letra digitada pelo usuário
    scanf ("%c", &Letra);

    switch(Letra) {
        case 'A':
            printf ("Você digito a letra de ARANHA.\n");
            break;
        case 'B':
            printf ("Você digito a letra de BANCO.\n");
        case 'C':
            printf ("Você digito a letra de CASA.\n");
        default:
        printf ("Digita uma letra valida!");
    }

    return 0;

}