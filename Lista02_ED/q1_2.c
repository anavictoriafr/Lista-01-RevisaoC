// Em funções da linguagem c os valores sempre são passados por valor, logo quando eu cooco *a no meu destruidor
// eu estou passando uma cópia desse endereço, então se alterar alguma coia eu estarei alterando essa cópia2

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int matricula;
    char nome[32];
    float media;
} Aluno;

Aluno *criarAluno(int matricula, const char *nome, float media){
    Aluno *a = malloc(sizeof(Aluno));
    if (a == NULL) return NULL;
    a->matricula = matricula;
    strncpy(a->nome, nome, sizeof(a->nome) - 1);
    a->media = media;
    return a;
}

void destruirAluno(Aluno **pa){
    if(pa != NULL && *pa != NULL){ 
    free(*pa);
    *pa = NULL;
    }
}

void imprimirAluno(const Aluno *a){
    if (a == NULL) {
        printf("Ponteiro nulo");
    }
    printf("matricula: %d \n nome: %s \n media: %.2f\n", a->matricula, a->nome, a->media);
}

int main(){

    int matricula = 1234;
    float media = 9.2;
    char nome[4] = "Ana";

    
    Aluno *al = criarAluno(matricula, nome, media);
    imprimirAluno(al);

    destruirAluno(&al);
    destruirAluno(&al);// mostrar que chamar o deestruidor duas vezes não quebra o código
    imprimirAluno(al);

    return 0;

}