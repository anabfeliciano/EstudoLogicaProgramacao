#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main () {
    SetConsoleOutputCP(65001);
    system ("cls");
    

    printf("⡞⠳⣄⣀⣠⠞⢷ ֹ۪ CINEMA ⡞⠳⣄⣀⣠⠞⢷ ֹ۪\n\n");
    
    printf("Escolha o filme:\n");

    printf ("1. Aventura\n");
    printf ("2. Comédia\n");
    printf ("3. Ficção científica\n");
    printf ("4. Terror\n");
    printf("Opção: ");
    int opcaoFilme;
    scanf("%d", &opcaoFilme);

    char categoriaFilme;
    switch (opcaoFilme) {
        case 1:
            categoriaFilme = 'A';
            break;
        case 2:
            categoriaFilme = 'C';
            break;
        case 3:
            categoriaFilme = 'F';
            break;
        case 4:
            categoriaFilme = 'T';
            break;
        default:
            printf("Erro: Opção de filme inválida! Encerrando o programa.\n");
            return 1;
    }

    printf("\nEscolha o horário:\n");
    printf("1 - 14h\n");
    printf("2 - 17h\n");
    printf("3 - 20h\n");
    printf("4 - 22h\n");
    printf("Opção: ");
    int opcaoHorario;
    scanf("%d", &opcaoHorario);

    float precoBasico = 0.0, precoUnitario = 0.0, subtotal = 0.0;
    float descontoQuantidade = 0.0, valorTotal = 0.0;

    switch (opcaoHorario) {
        case 1:
            precoBasico = 20.00;
            break;
        case 2:
            precoBasico = 24.00;
            break;
        case 3:
            precoBasico = 30.00;
            break;
        case 4:
            precoBasico = 32.00;
            break;
        default:
            printf("Erro: Opção de horário inválida! Encerrando o programa.\n");
            return 1;
    }

    printf("\nEscolha o tipo de ingresso:\n");
    printf("1 - Inteira\n");
    printf("2 - Meia-entrada\n");
    printf("3 - Ingresso promocional\n");
    printf("Opção: ");
    int opcaoTipo;
    scanf("%d", &opcaoTipo);


    switch (opcaoTipo) {
        case 1:
            precoUnitario = precoBasico;
            break;
        case 2:
            precoUnitario = precoBasico * 0.50; // Desconto de 50%
            break;
        case 3:
            // Valida se a sessão permite promocional (apenas 14h e 17h)
            if (opcaoHorario == 3 || opcaoHorario == 4) {
                printf("Erro: O ingresso promocional não é válido para as sessões das 20h e 22h.\n");
                return 1;
            } else {
                precoUnitario = precoBasico * 0.70; // Desconto de 30%
            }
            break;
        default:
            printf("Erro: Tipo de ingresso inválido! Encerrando o programa.\n");
            return 1;
    }

    printf("\nInforme a quantidade de ingressos: ");
    int quantidade;
    scanf("%d", &quantidade);

    if (quantidade <= 0) {
        printf("Erro: A quantidade deve ser maior que zero. Encerrando o programa.\n");
        return 1;
    }

    // Desconto extra de 10% para Terror (opção 4) na sessão das 14h (opção 1)
    if (opcaoFilme == 4 && opcaoHorario == 1) {
        precoUnitario = precoUnitario * 0.90;
    }

    subtotal = precoUnitario * quantidade;

    // Desconto de 5% para compras acima de 5 ingressos
    if (quantidade > 5) {
        descontoQuantidade = subtotal * 0.05;
    }

    // Valor Total
    valorTotal = subtotal - descontoQuantidade;

    printf("\n========== RESUMO DA COMPRA ==========\n");

    // Exibe o filme
    printf("Filme escolhido: ");
    switch (opcaoFilme) {
        case 1: printf("Aventura\n"); break;
        case 2: printf("Comédia\n"); break;
        case 3: printf("Ficção científica\n"); break;
        case 4: printf("Terror\n"); break;
    }

    // Exibe o horário
    printf("Horário: ");
    switch (opcaoHorario) {
        case 1: printf("14h\n"); break;
        case 2: printf("17h\n"); break;
        case 3: printf("20h\n"); break;
        case 4: printf("22h\n"); break;
    }

    // Exibe o tipo de ingresso
    printf("Tipo de ingresso: ");
    switch (opcaoTipo) {
        case 1: printf("Inteira\n"); break;
        case 2: printf("Meia-entrada\n"); break;
        case 3: printf("Promocional\n"); break;
    }

    printf("Quantidade: %d\n", quantidade);
    printf("Preço básico do ingresso: R$ %.2f\n", precoBasico);

    // Detalha desconto promocional/meia
    if (opcaoTipo == 2) {
        printf("Desconto meia-entrada: 50%%\n");
    } else if (opcaoTipo == 3) {
        printf("Desconto promocional: 30%%\n");
    }

    // Detalha valor unitário
    if (precoUnitario < precoBasico) {
        printf("Valor unitário com desconto: R$ %.2f\n", precoUnitario);
    } else {
        printf("Valor unitário: R$ %.2f\n", precoUnitario);
    }

    printf("Subtotal: R$ %.2f\n", subtotal);

    // Detalha desconto de quantidade
    if (quantidade > 5) {
        printf("Desconto por quantidade: 5%%\n");
        printf("Valor do desconto por quantidade: R$ %.2f\n", descontoQuantidade);
    }

    printf("Valor total: R$ %.2f\n", valorTotal);
    printf("======================================\n");

    return 0;
}
