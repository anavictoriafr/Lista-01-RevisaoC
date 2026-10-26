// Não podemos retornar o endereço de um vetor criado dentro de uma função pois essa variável é destruída no fim desa função.
// Assim, se eu retornar esse endereço quando ele for lindo o espaço de memória não estará mais reservado para esse vetor, podendo conter lixo de memória

#include <stdlib.h>
#include <stdio.h>


void lerNotas(int num,float *notas){
    for(int i = 0; i < num; i++){
        printf("Digite a proxima nota: \n");
        scanf("%f", notas + i);
    }
}

float mediaNotas(int num, float *notas){
    if(notas == NULL || num <= 0) return -1;
    float soma = 0;
    for(int i = 0; i < num; i++){
        soma += *(notas + i);
    }
    return (soma/num);
}

float maiorNota(int num, float *notas){
    if(notas == NULL || num <= 0) return -1;
    float maior = *(notas);
    for(int i = 0; i < num; i++){
        if(*(notas + i) > maior){
           maior = *(notas + i);
        }
    }
    return maior;
}

int main() {
    int num;

    printf("Quantidade de notas que serao inseridas: \n");
    scanf("%d", &num);

    float *notas = malloc(num * sizeof(float));
    if(notas == NULL){
        printf("ponteiro nao alocado\n");
        return 1;
    }

    lerNotas(num, notas);

    float media = mediaNotas(num, notas);
    float maiorN = maiorNota(num, notas);

    printf("Media das notas: %.2f, \n Maior nota: %.2f", media, maiorN);

    free(notas);

    return 0;
}