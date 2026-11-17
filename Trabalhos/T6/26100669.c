/*
 * Universidade Católica de Brasília
 * Lógica de Programação e Algoritmos - 2º Semestre de 2026
 * Trabalho prático 06 - Coletânea de funções
 *
 * Compilação: gcc 26100669.c -o saida.exe
 */

#include <stdio.h>

/* ------------------------------------------------------------------ */
/* Questão 01 - Função afim f(x) = ax + b                              */
/* ------------------------------------------------------------------ */
double funcao_afim(double a, double b, double x) {
    return a * x + b;
}
/* Testes:
 * (a=3,   b=2, x=4) -> 14.00
 * (a=2,   b=-3, x=0) -> -3.00
 * (a=-1.5, b=4, x=2) -> 1.00
 * (a=1,   b=0, x=-5) -> -5.00
 */

/* ------------------------------------------------------------------ */
/* Questão 02 - Quantidade de raízes reais distintas                   */
/* ------------------------------------------------------------------ */
int qtd_raizes_reais(int a, int b, int c) {
    int delta = b * b - 4 * a * c;   /* máx. |delta| = 10000 + 40000 */
    if (delta < 0) return 0;
    if (delta == 0) return 1;
    return 2;
}
/* Testes:
 * (1, 0, 1)        -> 0
 * (1, -4, 4)       -> 1
 * (1, -5, 6)       -> 2
 * (100, 100, 100)  -> 0  (delta = -30000, limite superior)
 * (-100, 0, 0)     -> 1  (delta = 0, raiz dupla em 0)
 * (1, 100, 100)    -> 2  (delta = 9600)
 */

/* ------------------------------------------------------------------ */
/* Questão 03 - Soma dos termos de uma PA                              */
/* ------------------------------------------------------------------ */
double soma_pa(double primeiro, double razao, int n) {
    double soma = 0.0;
    double termo = primeiro;
    int i;
    for (i = 0; i < n; i++) {
        soma += termo;
        termo += razao;
    }
    return soma;
}
/* Testes:
 * (10, -2, 4)   -> 28.00  (10+8+6+4)
 * (5, 0, 3)     -> 15.00  (razão zero)
 * (1.5, 0.5, 1) -> 1.50   (um único termo, fronteira)
 * (2, 3, 5)     -> 40.00  (2+5+8+11+14)
 */

/* ------------------------------------------------------------------ */
/* Questão 04 - Termo de uma PG por multiplicações sucessivas          */
/* ------------------------------------------------------------------ */
double termo_pg(double primeiro, double razao, int posicao) {
    double termo = primeiro;
    int i;
    for (i = 1; i < posicao; i++) {
        termo *= razao;
    }
    return termo;
}
/* Testes:
 * (3, -2, 4)   -> -24.00
 * (3, -2, 1)   -> 3.00   (posição 1, fronteira)
 * (5, 0, 3)    -> 0.00   (razão zero)
 * (2, 0.5, 3)  -> 0.50
 * (7, 1, 10)   -> 7.00   (razão 1)
 */

/* ------------------------------------------------------------------ */
/* Questão 05 - Montante a juros compostos, período a período          */
/* ------------------------------------------------------------------ */
double montante_composto(double capital, double taxa_percentual, int periodos) {
    double saldo = capital;
    int i;
    for (i = 0; i < periodos; i++) {
        saldo += saldo * taxa_percentual / 100.0;
    }
    return saldo;
}
/* Testes:
 * (1000, 10, 2) -> 1210.00
 * (500, 5, 0)   -> 500.00   (zero períodos, fronteira)
 * (0, 10, 5)    -> 0.00     (capital zero)
 * (100, 0, 10)  -> 100.00   (taxa zero)
 * (200, 50, 3)  -> 675.00
 */

/* ------------------------------------------------------------------ */
/* Questão 06 - Classificação de triângulo                             */
/* Retorno: 0 não forma; 1 equilátero; 2 isósceles; 3 escaleno         */
/* ------------------------------------------------------------------ */
int classifica_triangulo(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) return 0;
    if (a >= b + c || b >= a + c || c >= a + b) return 0;
    if (a == b && b == c) return 1;
    if (a == b || a == c || b == c) return 2;
    return 3;
}
/* Testes:
 * (1, 2, 3)        -> 0  (soma igual ao terceiro lado, degenerado)
 * (5, 5, 5)        -> 1
 * (5, 3, 5)        -> 2
 * (3, 5, 5)        -> 2  (outra ordem)
 * (3, 4, 5)        -> 3
 * (5, 4, 3)        -> 3  (outra ordem)
 * (0, 4, 4)        -> 0  (lado zero)
 * (-3, 4, 5)       -> 0  (lado negativo)
 * (1000, 1000, 1000) -> 1 (limite superior)
 */

/* ------------------------------------------------------------------ */
/* Questão 07 - Média ponderada                                        */
/* ------------------------------------------------------------------ */
double media_ponderada(double notas[], double pesos[], int n) {
    double soma_produtos = 0.0;
    double soma_pesos = 0.0;
    int i;
    for (i = 0; i < n; i++) {
        soma_produtos += notas[i] * pesos[i];
        soma_pesos += pesos[i];
    }
    return soma_produtos / soma_pesos;
}
/* Testes:
 * notas {7,8,10}, pesos {2,3,5}  -> 8.80
 * notas {6.5},    pesos {3}      -> 6.50  (um elemento, fronteira)
 * notas {10,0},   pesos {0,1}    -> 0.00  (peso zero em um elemento)
 * notas {5,7},    pesos {1,1}    -> 6.00
 */

/* ------------------------------------------------------------------ */
/* Questão 08 - Arranjo simples A(n,p) = n! / (n-p)!                   */
/* Produto de (n-p+1) até n; 20! cabe em long long                     */
/* ------------------------------------------------------------------ */
long long arranjo(int n, int p) {
    long long resultado = 1;
    int i;
    for (i = n - p + 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}
/* Testes:
 * (5, 3)   -> 60
 * (5, 0)   -> 1
 * (1, 1)   -> 1
 * (0, 0)   -> 1
 * (20, 1)  -> 20
 * (20, 20) -> 2432902008176640000  (limite superior)
 */

/* ------------------------------------------------------------------ */
/* Questão 09 - Combinação simples C(n,p) = n! / ((n-p)! p!)           */
/* Cada passo da divisão é exata, evitando overflow                    */
/* ------------------------------------------------------------------ */
long long combinacao(int n, int p) {
    long long resultado = 1;
    int i;
    if (p > n - p) p = n - p;   /* C(n,p) = C(n,n-p) */
    for (i = 1; i <= p; i++) {
        resultado = resultado * (n - p + i) / i;
    }
    return resultado;
}
/* Testes:
 * (5, 3)   -> 10
 * (5, 0)   -> 1
 * (5, 5)   -> 1
 * (0, 0)   -> 1
 * (20, 10) -> 184756  (maior valor para n = 20)
 */

/* ------------------------------------------------------------------ */
/* Questão 10 - Determinante 3x3 (regra de Sarrus)                     */
/* ------------------------------------------------------------------ */
double determinante_sarrus(double m[3][3]) {
    double principais = m[0][0] * m[1][1] * m[2][2]
                      + m[0][1] * m[1][2] * m[2][0]
                      + m[0][2] * m[1][0] * m[2][1];
    double secundarias = m[0][2] * m[1][1] * m[2][0]
                       + m[0][0] * m[1][2] * m[2][1]
                       + m[0][1] * m[1][0] * m[2][2];
    return principais - secundarias;
}
/* Testes:
 * {{1,2,3},{0,4,5},{1,0,6}} -> 22.00
 * {{1,0,0},{0,1,0},{0,0,1}} -> 1.00   (identidade)
 * {{1,2,3},{4,5,6},{7,8,9}} -> 0.00   (singular)
 * {{2,0,0},{0,3,0},{0,0,4}} -> 24.00  (diagonal)
 */

/* ------------------------------------------------------------------ */
/* Questão 11 - Binário (string) para decimal; -1 se inválida          */
/* ------------------------------------------------------------------ */
int binario_para_decimal(const char *s) {
    int resultado = 0;
    int i = 0;
    if (s[0] == '\0') return -1;
    while (s[i] != '\0') {
        if (s[i] != '0' && s[i] != '1') return -1;
        resultado = resultado * 2 + (s[i] - '0');
        i++;
    }
    return resultado;
}
/* Testes:
 * "10110"  -> 22
 * "00101"  -> 5   (zeros à esquerda)
 * "0"      -> 0
 * "10201"  -> -1  (caractere inválido)
 * ""       -> -1  (string vazia)
 * "1"      -> 1
 * "1111111111111111111111111111111" (31 uns) -> 2147483647
 */

/* ------------------------------------------------------------------ */
/* Questão 12 - Divisibilidade por 3 e 9 sobre string                  */
/* Retorno: -1 inválida; 0 nenhum; 1 só por 3; 2 por 3 e por 9         */
/* ------------------------------------------------------------------ */
int divisibilidade_3_9(const char *s) {
    int soma = 0;
    int i = 0;
    if (s[0] == '\0') return -1;
    while (s[i] != '\0') {
        if (s[i] < '0' || s[i] > '9') return -1;
        soma += s[i] - '0';
        i++;
    }
    if (soma % 9 == 0) return 2;
    if (soma % 3 == 0) return 1;
    return 0;
}
/* Testes:
 * "124"   -> 0
 * "123"   -> 1
 * "00108" -> 2
 * "12a3"  -> -1
 * ""      -> -1
 * "0"     -> 2   (soma 0)
 * "3"     -> 1
 * "9"     -> 2
 */

/* ------------------------------------------------------------------ */
int main(void) {
    int i;

    printf("=== Questao 01 ===\n");
    printf("f(4) com a=3,b=2: %.2f (esperado 14.00)\n", funcao_afim(3, 2, 4));
    printf("a=2,b=-3,x=0: %.2f (esperado -3.00)\n", funcao_afim(2, -3, 0));
    printf("a=-1.5,b=4,x=2: %.2f (esperado 1.00)\n", funcao_afim(-1.5, 4, 2));
    printf("a=1,b=0,x=-5: %.2f (esperado -5.00)\n", funcao_afim(1, 0, -5));

    printf("\n=== Questao 02 ===\n");
    printf("(1,0,1): %d (esperado 0)\n", qtd_raizes_reais(1, 0, 1));
    printf("(1,-4,4): %d (esperado 1)\n", qtd_raizes_reais(1, -4, 4));
    printf("(1,-5,6): %d (esperado 2)\n", qtd_raizes_reais(1, -5, 6));
    printf("(100,100,100): %d (esperado 0)\n", qtd_raizes_reais(100, 100, 100));
    printf("(-100,0,0): %d (esperado 1)\n", qtd_raizes_reais(-100, 0, 0));
    printf("(1,100,100): %d (esperado 2)\n", qtd_raizes_reais(1, 100, 100));

    printf("\n=== Questao 03 ===\n");
    printf("(10,-2,4): %.2f (esperado 28.00)\n", soma_pa(10, -2, 4));
    printf("(5,0,3): %.2f (esperado 15.00)\n", soma_pa(5, 0, 3));
    printf("(1.5,0.5,1): %.2f (esperado 1.50)\n", soma_pa(1.5, 0.5, 1));
    printf("(2,3,5): %.2f (esperado 40.00)\n", soma_pa(2, 3, 5));

    printf("\n=== Questao 04 ===\n");
    printf("(3,-2,4): %.2f (esperado -24.00)\n", termo_pg(3, -2, 4));
    printf("(3,-2,1): %.2f (esperado 3.00)\n", termo_pg(3, -2, 1));
    printf("(5,0,3): %.2f (esperado 0.00)\n", termo_pg(5, 0, 3));
    printf("(2,0.5,3): %.2f (esperado 0.50)\n", termo_pg(2, 0.5, 3));
    printf("(7,1,10): %.2f (esperado 7.00)\n", termo_pg(7, 1, 10));

    printf("\n=== Questao 05 ===\n");
    printf("(1000,10,2): %.2f (esperado 1210.00)\n", montante_composto(1000, 10, 2));
    printf("(500,5,0): %.2f (esperado 500.00)\n", montante_composto(500, 5, 0));
    printf("(0,10,5): %.2f (esperado 0.00)\n", montante_composto(0, 10, 5));
    printf("(100,0,10): %.2f (esperado 100.00)\n", montante_composto(100, 0, 10));
    printf("(200,50,3): %.2f (esperado 675.00)\n", montante_composto(200, 50, 3));

    printf("\n=== Questao 06 ===\n");
    printf("(1,2,3): %d (esperado 0)\n", classifica_triangulo(1, 2, 3));
    printf("(5,5,5): %d (esperado 1)\n", classifica_triangulo(5, 5, 5));
    printf("(5,3,5): %d (esperado 2)\n", classifica_triangulo(5, 3, 5));
    printf("(3,5,5): %d (esperado 2)\n", classifica_triangulo(3, 5, 5));
    printf("(3,4,5): %d (esperado 3)\n", classifica_triangulo(3, 4, 5));
    printf("(5,4,3): %d (esperado 3)\n", classifica_triangulo(5, 4, 3));
    printf("(0,4,4): %d (esperado 0)\n", classifica_triangulo(0, 4, 4));
    printf("(-3,4,5): %d (esperado 0)\n", classifica_triangulo(-3, 4, 5));
    printf("(1000,1000,1000): %d (esperado 1)\n", classifica_triangulo(1000, 1000, 1000));

    printf("\n=== Questao 07 ===\n");
    {
        double n1[] = {7, 8, 10}, p1[] = {2, 3, 5};
        double n2[] = {6.5},      p2[] = {3};
        double n3[] = {10, 0},    p3[] = {0, 1};
        double n4[] = {5, 7},     p4[] = {1, 1};
        printf("{7,8,10}/{2,3,5}: %.2f (esperado 8.80)\n", media_ponderada(n1, p1, 3));
        printf("{6.5}/{3}: %.2f (esperado 6.50)\n", media_ponderada(n2, p2, 1));
        printf("{10,0}/{0,1}: %.2f (esperado 0.00)\n", media_ponderada(n3, p3, 2));
        printf("{5,7}/{1,1}: %.2f (esperado 6.00)\n", media_ponderada(n4, p4, 2));
    }

    printf("\n=== Questao 08 ===\n");
    printf("(5,3): %lld (esperado 60)\n", arranjo(5, 3));
    printf("(5,0): %lld (esperado 1)\n", arranjo(5, 0));
    printf("(1,1): %lld (esperado 1)\n", arranjo(1, 1));
    printf("(0,0): %lld (esperado 1)\n", arranjo(0, 0));
    printf("(20,1): %lld (esperado 20)\n", arranjo(20, 1));
    printf("(20,20): %lld (esperado 2432902008176640000)\n", arranjo(20, 20));

    printf("\n=== Questao 09 ===\n");
    printf("(5,3): %lld (esperado 10)\n", combinacao(5, 3));
    printf("(5,0): %lld (esperado 1)\n", combinacao(5, 0));
    printf("(5,5): %lld (esperado 1)\n", combinacao(5, 5));
    printf("(0,0): %lld (esperado 1)\n", combinacao(0, 0));
    printf("(20,10): %lld (esperado 184756)\n", combinacao(20, 10));

    printf("\n=== Questao 10 ===\n");
    {
        double m1[3][3] = {{1, 2, 3}, {0, 4, 5}, {1, 0, 6}};
        double m2[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        double m3[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        double m4[3][3] = {{2, 0, 0}, {0, 3, 0}, {0, 0, 4}};
        printf("Exemplo: %.2f (esperado 22.00)\n", determinante_sarrus(m1));
        printf("Identidade: %.2f (esperado 1.00)\n", determinante_sarrus(m2));
        printf("Singular: %.2f (esperado 0.00)\n", determinante_sarrus(m3));
        printf("Diagonal: %.2f (esperado 24.00)\n", determinante_sarrus(m4));
    }

    printf("\n=== Questao 11 ===\n");
    {
        char uns[32];
        for (i = 0; i < 31; i++) uns[i] = '1';
        uns[31] = '\0';
        printf("\"10110\": %d (esperado 22)\n", binario_para_decimal("10110"));
        printf("\"00101\": %d (esperado 5)\n", binario_para_decimal("00101"));
        printf("\"0\": %d (esperado 0)\n", binario_para_decimal("0"));
        printf("\"10201\": %d (esperado -1)\n", binario_para_decimal("10201"));
        printf("\"\": %d (esperado -1)\n", binario_para_decimal(""));
        printf("\"1\": %d (esperado 1)\n", binario_para_decimal("1"));
        printf("31 uns: %d (esperado 2147483647)\n", binario_para_decimal(uns));
    }

    printf("\n=== Questao 12 ===\n");
    printf("\"124\": %d (esperado 0)\n", divisibilidade_3_9("124"));
    printf("\"123\": %d (esperado 1)\n", divisibilidade_3_9("123"));
    printf("\"00108\": %d (esperado 2)\n", divisibilidade_3_9("00108"));
    printf("\"12a3\": %d (esperado -1)\n", divisibilidade_3_9("12a3"));
    printf("\"\": %d (esperado -1)\n", divisibilidade_3_9(""));
    printf("\"0\": %d (esperado 2)\n", divisibilidade_3_9("0"));
    printf("\"3\": %d (esperado 1)\n", divisibilidade_3_9("3"));
    printf("\"9\": %d (esperado 2)\n", divisibilidade_3_9("9"));

    return 0;
}
