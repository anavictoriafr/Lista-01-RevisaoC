// Devolver o endereço do ponteiro é seguro pois ele aponta para um vetor criado na main, 
//logo esse endereço permanecerá reservado durante toda a execução do código.
// Por outro lado, uma variável local é destruída assim que a função termina, 
//deste modo seu endereço não estará mais reservado, podendo retornar lixo ou outro dados aletório.

#include <stdio.h>

int *primeiraOcorrencia(int *v, int n, int alvo) {
    for (int i = 0; i < n; i++) {
        if (v[i] == alvo) {
            return &v[i];
        }
    }
    return NULL;
}

int main(void) {
    int teste[] = {12, 7, 30, 4, 18, 30};
    int n = 6;

    int *p1 = primeiraOcorrencia(teste, n, 30);
    if (p1 != NULL) {
        *p1 = 0;
        for (int i = 0; i < n; i++) {
            printf("%d ", teste[i]);
        }
    } else {
        printf("nao encontrado");
    }

    printf("\n");

    int *p2 = primeiraOcorrencia(teste, n, 99);
    if (p2 != NULL) {
        *p2 = 0;
        for (int i = 0; i < n; i++) {
            printf("%d ", teste[i]);
        }
    } else {
        printf("nao encontrado");
    }

    return 0;
}