#include <stdio.h>
#include <stdlib.h>

int main () {

    system ("cls");

    int X;
    printf("Digite um número: ");
    scanf ("%d", &X); //%d serve para ler o número, & serve para guardar o número x

    //switch: Use quando você já tem opções exatas e fixas para comparar, como em menus, dias da semana,meses do ano ou escolha de personagens em um jogo.

    // If/Else: Use quando você precisar comparar coisas mais complexas como: "se a nota for maior que 7..." ou "Se a idade estiver entre 18 e 30..."

    switch(X % 2) {  // % significa o resto da divisão
        case 0:
            printf(" O número é PAR");
            break;
        case 1:
            printf ("O númro é IMPAR");
            break;
    }
    return 0;
}