#include <stdio.h>
#include <stdlib.h>

int main(void) {
    system("cls");

    FILE *entrada, *saida;
    long long id;
    int vd, fem, amb, ind, inf, rac, dias;

    long total = 0;
    long c_vd = 0, c_fem = 0, c_amb = 0, c_ind = 0, c_inf = 0, c_rac = 0;
    long sem_marcacao = 0, vd_e_fem = 0;
    long qtd_positivos = 0, mais_365 = 0;
    long long soma_dias = 0;
    long maior;
    int n_max;
    double media = 0.0;

    entrada = fopen("Filtro.txt", "r");
    if (entrada == NULL) {
        printf("Erro: nao foi possivel abrir Filtro.txt\n");
        return 1;
    }

    while (fscanf(entrada, "%lld %d %d %d %d %d %d %d",
                  &id, &vd, &fem, &amb, &ind, &inf, &rac, &dias) == 8) {
        total++;

        if (vd == 1)  c_vd++;
        if (fem == 1) c_fem++;
        if (amb == 1) c_amb++;
        if (ind == 1) c_ind++;
        if (inf == 1) c_inf++;
        if (rac == 1) c_rac++;

        if (vd != 1 && fem != 1 && amb != 1 && ind != 1 && inf != 1 && rac != 1)
            sem_marcacao++;

        if (vd == 1 && fem == 1)
            vd_e_fem++;

        if (dias > 0) {
            soma_dias += dias;
            qtd_positivos++;
        }
        if (dias > 365)
            mais_365++;
    }
    fclose(entrada);

    if (qtd_positivos > 0)
        media = (double) soma_dias / qtd_positivos;

    /* Tema(s) com mais processos */
    maior = c_vd;
    if (c_fem > maior) maior = c_fem;
    if (c_amb > maior) maior = c_amb;
    if (c_ind > maior) maior = c_ind;
    if (c_inf > maior) maior = c_inf;
    if (c_rac > maior) maior = c_rac;

    n_max = 0;
    if (c_vd == maior)  n_max++;
    if (c_fem == maior) n_max++;
    if (c_amb == maior) n_max++;
    if (c_ind == maior) n_max++;
    if (c_inf == maior) n_max++;
    if (c_rac == maior) n_max++;

    saida = fopen("resultado.txt", "w");
    if (saida == NULL) {
        printf("Erro: nao foi possivel criar resultado.txt\n");
        return 1;
    }

    /* Questao 1 */
    fprintf(saida, "Questao 1: Total de processos no arquivo: %ld\n\n", total);

    /* Questao 2 */
    fprintf(saida, "Questao 2: Processos por tema\n");
    fprintf(saida, "  Violencia domestica: %ld\n", c_vd);
    fprintf(saida, "  Feminicidio: %ld\n", c_fem);
    fprintf(saida, "  Meio ambiente: %ld\n", c_amb);
    fprintf(saida, "  Direitos dos povos indigenas: %ld\n", c_ind);
    fprintf(saida, "  Infancia e juventude: %ld\n", c_inf);
    fprintf(saida, "  Racismo ou injuria racial: %ld\n\n", c_rac);

    /* Questao 3 */
    fprintf(saida, "Questao 3: Percentual de cada tema em relacao ao total\n");
    if (total > 0) {
        fprintf(saida, "  Violencia domestica: %.2f%%\n", 100.0 * c_vd / total);
        fprintf(saida, "  Feminicidio: %.2f%%\n", 100.0 * c_fem / total);
        fprintf(saida, "  Meio ambiente: %.2f%%\n", 100.0 * c_amb / total);
        fprintf(saida, "  Direitos dos povos indigenas: %.2f%%\n", 100.0 * c_ind / total);
        fprintf(saida, "  Infancia e juventude: %.2f%%\n", 100.0 * c_inf / total);
        fprintf(saida, "  Racismo ou injuria racial: %.2f%%\n\n", 100.0 * c_rac / total);
    } else {
        fprintf(saida, "  Nao ha processos no arquivo.\n\n");
    }

    /* Questao 4 */
    fprintf(saida, "Questao 4: Tema(s) com mais processos (%ld processos)\n", maior);
    if (c_vd == maior)  fprintf(saida, "  - Violencia domestica\n");
    if (c_fem == maior) fprintf(saida, "  - Feminicidio\n");
    if (c_amb == maior) fprintf(saida, "  - Meio ambiente\n");
    if (c_ind == maior) fprintf(saida, "  - Direitos dos povos indigenas\n");
    if (c_inf == maior) fprintf(saida, "  - Infancia e juventude\n");
    if (c_rac == maior) fprintf(saida, "  - Racismo ou injuria racial\n");
    if (n_max > 1)
        fprintf(saida, "  Ha empate entre %d temas.\n\n", n_max);
    else
        fprintf(saida, "  Nao ha empate.\n\n");

    /* Questao 5 */
    fprintf(saida, "Questao 5: Processos sem marcacao em nenhum tema: %ld\n\n", sem_marcacao);

    /* Questao 6 */
    fprintf(saida, "Questao 6: Processos com violencia domestica e feminicidio simultaneamente: %ld\n\n", vd_e_fem);

    /* Questao 7 */
    fprintf(saida, "Questao 7: Media de dias desde o recebimento (valores > 0): ");
    if (qtd_positivos > 0)
        fprintf(saida, "%.2f dias\n\n", media);
    else
        fprintf(saida, "nao ha valores maiores que zero\n\n");

    /* Questao 8 */
    fprintf(saida, "Questao 8: Processos com mais de 365 dias: %ld\n", mais_365);

    fclose(saida);
    printf("Resultados gravados em resultado.txt\n");
    return 0;
}