#include <stdio.h>

int f(int a, int b) {
    return a * b + 1;
}

int main(void) {
    int res1 = f(2, 3);
    int res2 = f(f(1, 2), 3);

    printf("f(2, 3) = %d\n", res1);
    printf("f(f(1, 2), 3) = %d\n", res2);
    
    return 0;
}