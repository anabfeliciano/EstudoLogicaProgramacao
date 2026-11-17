#include <stdio.h>

int main() {
    int A, B;

    printf("Digite o dividendo: \n");
    scanf("%d", &A);

    printf("Digite o Divisor: \n");
    scanf("%d", &B);

    // Boa prática: verificar se B é zero para evitar divisão por zero
    if (B == 0) {
        printf("Erro: Divisão por zero não é permitida!\n");
        return 1;
    }

    int D = A / B;
    int R = A % B;

    printf("Resultado da Divisão: %d\n", D);
    printf("Resultado do Resto: %d\n", R); // Corrigido de D para R

    return 0;
}