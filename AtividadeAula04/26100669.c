#include <stdio.h>
#include <stdlib.h>

int main() {

system ("cls");

int N;
printf("Digite um numero inteiro de 3 digitos (100 a 999): ");
scanf ("%d",&N);

if (N >=100 && N<=999) {
   int U,D,C,T;
   U = N%10;
   D = (N/10)%10;
   C = N/10/10;
   T = (100*U)+(10*D)+C;
   printf ("O valor de T é: %d", T);
}

else {
    printf ("Erro: o numero deve estar entre 100 e 999.\n");
}

return 0;
}

// Teste 1: entrada de um número válido (583).
// Teste 2: entrada de outro número válido (247).
// Teste 3: teste do limite inferior do intervalo (100).
// Teste 4: teste do limite superior do intervalo (999).
// Teste 5: entrada de um número inválido (99).