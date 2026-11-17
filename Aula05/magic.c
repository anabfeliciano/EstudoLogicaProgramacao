#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    system("cls");
    srand(time(NULL));

    int Magic = rand() %201;
    int Palpite;
    INICIO:

    printf ("Digite um número: \n");
    scanf("%d", &Palpite);

    if (Palpite == Magic) printf("Parabéns, você acertou o número!!!");
    else if (Palpite > Magic) printf ("Você digitou um número muito grande!!!");
    else if (Palpite < Magic) printf ("Voc}e digitou um npumero muito pequeno!!!");

    goto INICIO;

    printf("%d", Magic);
    
    return 0;
}