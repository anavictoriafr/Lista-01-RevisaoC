#include <stdio.h>

void ordenarPar(int *a, int *b){
    int maior;
    if (*a > *b){
        maior = *a;
        *a = *b;
        *b = maior;
    }
}

int main(){
    int a = 9, b = 5;
    int c = 2, d = 7;

    ordenarPar(&a,&b);
    ordenarPar(&c,&d);
    printf("%d %d \n", a, b);
    printf("%d %d \n", c, d);

    return 0;
}
