#include <stdio.h>

int main (){

    float Preco = 150.0;
    Preco = Preco + 30.0;
    
    printf ("Original, sem formatação: %f\n", Preco);
    printf ("%.4f\n", Preco);
    printf ("%.3f\n", Preco);
    printf ("%.2f\n", Preco);

    return 0;
}