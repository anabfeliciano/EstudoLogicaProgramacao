#include <stdio.h>
#include <stdlib.h>

int main () {
    system ("cls");

    printf("Veja lista de candidatos a governadores:\n\n");
    printf("30 - Francisco Queiroz Caputo Neto - Partido Novo (NOVO)\n");
    printf("28 - Alderico da Silva Pinheiro Filho - Partido Renovador Trabalhista Brasileiro (PRTB)\n");
    printf("40 - Ricardo Garcia Cappelli - Partido Socialista Brasileiro (PSB)\n");
    printf("36 - Elisson Ferreira Freire - Agir (AGIR)\n");
    printf("29 - Expedito Carneiro de Mendonça - Partido da Causa Operária (PCO)\n");
    printf("11 - Celina Leao Hizim Ferreira - Progressistas (PP)\n");
    printf("45 - Paula Moreno Paro Belmonte - Partido da Social Democracia Brasileira (PSDB)\n");
    printf("16 - Robson Raymundo da Silva - Partido Socialista dos Trabalhadores Unificado (PSTU)\n");
    printf("80 - Samara Mineiro Oliveira - Unidade Popular (UP)\n");
    printf("55 - José Roberto Arruda - Partido Social Democrático (PSD)\n");
    printf("13 - Leandro Antônio Grass Peixoto - Partido dos Trabalhadores (PT)\n");
    printf("0 - Voto nulo\n");
    printf("Digite -1 para encerrar a votação e ver os resultados.\n\n");

    FILE * fp = fopen("votar.csv","w");
    fprintf(fp, "Número;Candidato;Votos\n");

    int Voto; 
    int VotoFrancisco = 0;
    int VotoAlderico = 0;
    int VotoRicardo = 0;
    int VotoElisson = 0;
    int VotoExpedito = 0;
    int VotoCelina = 0;
    int VotoPaula = 0;
    int VotoRobson = 0;
    int VotoSamara = 0;
    int VotoJose = 0;
    int VotoLeandro = 0;
    int VotoNulo = 0;
    VOTAR:
    printf ("Registre o seu voto: ");
    scanf ("%d", &Voto);

    switch(Voto) {
        case 30:
            printf ("Você votou no Francisco.\n");
            VotoFrancisco++;
            break;
        case 28:
            printf ("Você votou no Alderico.\n");
            VotoAlderico++;
            break;
        case 40:
            printf ("Você votou no Ricardo.\n");
            VotoRicardo++;
            break;
        case 36:
            printf ("Você votou no Elisson.\n");
            VotoElisson++;
            break;
        case 29:
            printf ("Você votou no Expedito.\n");
            VotoExpedito++;
            break;
        case 11:
            printf ("Você votou na Celina.\n");
            VotoCelina++;
            break;
        case 45:
            printf ("Você votou na Paula.\n");
            VotoPaula++;
            break;
        case 16:
            printf ("Você votou no Robson.\n");
            VotoRobson++;
            break;
        case 80:
            printf ("Você votou na Samara.\n");
            VotoSamara++;
            break;
        case 55:
            printf ("Você votou no José.\n");
            VotoJose++;
            break;
        case 13:
            printf ("Você votou no Leandro.\n");
            VotoLeandro++;
            break;
        case 0:
            printf ("Você registrou um voto nulo.\n");
            VotoNulo++;
            break;
        case -1:
            fprintf (fp, "Encerrando a votação\nResultados finais:\n");
            fprintf (fp, "Francisco (30): %d votos\n", VotoFrancisco);
            fprintf (fp, "Alderico (28): %d votos\n", VotoAlderico);
            fprintf (fp, "Ricardo (40): %d votos\n", VotoRicardo);
            fprintf (fp, "Elisson (36): %d votos\n", VotoElisson);
            fprintf (fp, "Expedito (29): %d votos\n", VotoExpedito);
            fprintf (fp, "Celina (11): %d votos\n", VotoCelina);
            fprintf (fp, "Paula (45): %d votos\n", VotoPaula);
            fprintf (fp, "Robson (16): %d votos\n", VotoRobson);
            fprintf (fp, "Samara (80): %d votos\n", VotoSamara);
            fprintf (fp, "José (55): %d votos\n", VotoJose);
            fprintf (fp, "Leandro (13): %d votos\n", VotoLeandro);
            fprintf (fp, "Votos Nulos (0): %d votos\n", VotoNulo);
            break;
        default:
            printf ("Digite um número válido!\n");
    }
    goto VOTAR;

    return 0;
}