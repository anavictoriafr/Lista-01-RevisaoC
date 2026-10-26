#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int matricula;
    char nome[32];
    float media;
} Aluno;

int main(void) {
    Aluno *a = malloc(sizeof(Aluno *)); // ele pede para alocar o tamanho do ponteiro aluno (8 bytes) ao invés do tamanho da struct Aluno 
    a->matricula = 20260145;
    a->media = 8.7f;

    free(a);
    printf("%.1f\n", a->media);// acesso ao ponteiro após sua liberação, aquele endereço não está mais reservado podendo conter lixo de memória

    Aluno *b = malloc(sizeof(Aluno));
    b = malloc(sizeof(Aluno)); // usar o ponteiro b de novo sem liberar o espaço anteriormente reservado no heap causa vazamento de memoria
    b->matricula = 20260200;

    free(b);
    free(b); // dupla liberação

    int *v = malloc(5 * sizeof(int));
    for (int i = 0; i <= 5; i++) { //o laço de repetição acessa o espaço v[5] que não está reservado para este ponteiro, acessando lixo de memória
        v[i] = i * i;
    }

    free(v);

    return 0;

}