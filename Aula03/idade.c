#include <stdio.h>
#include <stdlib.h>

int main (){
    system("cls");

    printf("Digite sua idade: ");

    int idade;
    scanf("%d", &idade);

    if (idade >=18) {
        printf("Maior de idade.");
    }

    else {
        printf("Menor de idade.");
    }

    return 0;
}