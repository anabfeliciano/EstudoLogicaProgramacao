#include <stdio.h>
#include <stdlib.h>

int main (){

    system("cls");

    int A;
    float X,Resultado;

    printf("Lista de conversões disponíveis:\n");
    printf("\n1- Dólar\n");
    printf("2- Euro\n");
    printf("3- Libra Esterlina\n");
    printf("4- Iene Japonês\n");
    printf("\nDigite o número correspondente a conversão escolhida: ");
    scanf ("%d", &A);

    if (A < 1 || A > 4) {
        printf("Opção inválida");
        return 0; // Encerra o programa
    }

    printf("\nDigite o valor em reias que deseja converter: R$ ");
    scanf("%f", &X);

    switch (A){
        case 1: // Dólar
            Resultado = X * 0.20;
            printf("Convertendo o valor de R$ %.2f, ficaria em US$ %.2f.",X,Resultado);
            break;
        case 2: // Euro
            Resultado = X * 0.18;
            printf("Convertendo o valor de R$ %.2f, ficaria em EUR %.2f.",X,Resultado);
            break;
        case 3: // Libra Esterlina
            Resultado = X * 0.16;
            printf("Convertendo o valor de R$ %.2f, ficaria em GBP %.2f.",X,Resultado);
            break;
        case 4: // Iene Japonês
            Resultado = X * 27.00;
            printf("Convertendo o valor de R$ %.2f, ficaria em JPY %.2f.",X,Resultado);
            break;
        default:
            printf("Opção inválida!");
            break;
            
    }
    return 0;
}