#include <stdio.h>
#include <stdlib.h>

int main () {
    system ("cls");

    printf("Digite 4 números inteiros, separados por espaço: ");

    int A,B,C,D;
    scanf("%d %d %d %d", &A, &B, &C, &D);

    float Media;
    Media = (float) ( A + B + C + D)/ 4;
    Media = ( A + B + C + D)/ 4.0;

    printf("A média é %f.\n",Media);


    return 0;
}