#include <stdio.h>
#include <stdlib.h>

int main (){
   
    printf("Digite o primeiro cateto: ");
    int c1;
    scanf("%d", &c1);

    printf("Digite o segundo cateto: ");
    int c2;
    scanf("%d", &c2);


    int hipotenusa;
    hipotenusa = (c1*c1)+(c2*c2);

    printf ("Hipotenusa do seu triângulo é %d", hipotenusa);

    return 0;
};

// Depois fazer a verificar se indentificar se é um triângulo retangulo ou não !!!!!!!