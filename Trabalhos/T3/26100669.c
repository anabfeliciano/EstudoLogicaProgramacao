#include <stdio.h>
#include <stdlib.h>

int main() {

    system("cls");

    int i;
    double e = 0.0;
    double termo = 1.0; // Representa 1 / 0!

    for (i = 0; i < 5; i++) {
        if (i == 0) {
            termo = 1.0; // 0! = 1, logo 1/1 = 1
        } else {
            termo = termo / i; // Cada termo é o anterior dividido por n
        }
        e += termo;
    }

    printf("O valor aproximado de e (5 primeiros termos) e: %.15f\n", e);

    return 0;
}