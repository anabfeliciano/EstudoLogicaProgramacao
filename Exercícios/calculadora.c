#include <stdio.h>
#include<stdlib.h>

int main () {

    system ("cls");

    int A,B,C,Resultado;

    printf ("Digite o número correspondente a operação matemática que deseja:\n");
    printf ("1- Adição.\n");
    printf ("2- Subtração:.\n");
    printf ("3- Multiplicação.\n");
    printf ("4- Divisão.\n");
    scanf("%d", &C);

    printf("Digite um número: ");
    scanf ("%d", &A);
    printf ("Digite outro número: ");
    scanf ("%d", &B);

    switch (C) {
        case 1:
            Resultado = A + B;
            printf ("Resultado: %d + %d = %d, Resultado", A,B,Resultado);
            break;
        case 2:
            Resultado = A - B;
            printf ("Resultado: %d - %d = %d, Resultado", A,B,Resultado);
            break;
        case 3:
            Resultado = A * B;
            printf ("Resultado: %d * %d = %d, Resultado", A,B,Resultado);
            break;
        case 4:
            if (B == 0){
                printf ("Erro: Nao e possivel dividir por zero!\n");
            }
            else {
            
            // (float) faz o cast para exibir casas decimais
            float resultadoDivisao = (float) A / B; 
            printf("Resultado: %d / %d = %.2f \n", A, B, resultadoDivisao);
            break;
            }
        default:
            printf ("Opção inválida!\n");
            break;
    }
    return 0;
}