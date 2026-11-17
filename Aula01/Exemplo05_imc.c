#include <stdio.h>

int main () {

    float Altura = 1.90;
    float Peso = 110.0;
    float IMC = Peso/(Altura*Altura);

    printf ("O IMC da pessoa é %.2f\n", IMC);

    return 0;
}