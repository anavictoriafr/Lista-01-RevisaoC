// 1- linha 4: int n = sizeof(v) / sizeof(int); 
//como v[] é passado como ponteiro o sizeof(v) vai retornar o tamanho do ponteiro (8 bytes) e não do array completo.
// 2 - linha 7: for (int i = 1; i <= n; i++) 
// como o laço não começa no 0 o ele tentará entrar em um endreço a mais de memória do que o reservado para o ponteiro.
// 3- linha 12: return &maior;
// maior é uma varável local, logo quando a função acaba essa variável é destruída e seu endereço deixa de estar reservado.
// Assim, ele pode retornar lixo de memória ao invés do resultado esperado.
// 4 - linha 20:  printf("%d\n", *p); 
// esse ponteiro ainda não possui nenhum endereço de memória atribuido a ele, logo será printado lixo de memória.


#include <stdio.h>

int *maiorValor(int v[], int n) {
    int *p = &v[0];

    for (int i = 0; i < n; i++) { 
        if (v[i] > *p) {
            p = &v[i];
        }
    }
    return p;                
}

int main() {
    int v[5] = {12, 7, 30, 4, 18};
    int n = sizeof(v) / sizeof(int);
 
    printf("%d\n", *maiorValor(v, n));

    return 0;
}