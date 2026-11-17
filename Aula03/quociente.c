#include <stdio.h>
#include <stdlib.h>

int main () {
    system ("cls");

    int A = 18;
    int B = 4;
    float Q = A/B;

    Q = A/B; // ocorre conversao implicita, int / int é int
    Q = (float) A / (float) B; // conversão EXPLÍCITA, float / float é float
    Q = (float) A / B;

    printf("Conversao de tipos: \n");
    printf("O quociente da divisão de %d por %d é %f. \n \n",A,B,Q);



    return 0;

}