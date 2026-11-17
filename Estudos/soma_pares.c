#include <stdio.h>
#include <stdlib.h>

int main() {
    system("cls"); // Limpa a tela do terminal

    int soma = 0; // 1. Nosso "cofrinho" que começa vazio
    int i;        // 2. Nossa variável de contagem

    // O "for" é uma repetição: 
    // Começa no 2 (i=2), vai até o 10 (i<=10), pulando de 2 em 2 (i+=2)
    for (i = 2; i <= 10; i += 2) {
        
        soma += i; // Guarda o valor anterior da soma e adiciona o 'i' atual

        // Isso vai mostrar o que acontece em cada rodada (passo a passo)
        printf("Passo atual (i): %d | O cofrinho (soma) agora vale: %d\n", i, soma);
    }
    
    printf("\n----------------------------------------\n");
    printf("Resultado final da soma de 2 até 10 e: %d\n", soma);

    return 0;
}