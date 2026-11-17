#include <stdio.h>
#include <stdlib.h>

int main(){
    system ("cls");

    printf("Digite um número:" );

    int N;
    scanf("%d", &N);

    int diagonais;
    diagonais = N*(N-3)/2;

    printf ("O número de diagonais de um polígono de %d lados é %d diagonais.", N,diagonais);



    return 0;
}