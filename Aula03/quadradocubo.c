#include <stdio.h>
#include <stdlib.h>

int main(){
    system ("cls");

    printf("Digite um número: ");
    int A;
    scanf("%d", &A);

    int quadrado;
    int cubo;
    quadrado = (A*A);
    cubo = (A*A*A);

    printf("O quadrado e o cubo de %d são: %d e %d", A,quadrado, cubo);

    return 0;


}