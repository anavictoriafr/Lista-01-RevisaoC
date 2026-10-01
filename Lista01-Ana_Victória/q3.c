// a cada p++ o ponteiro percorre 4 bytes (tamanho de um int), 
//mas se o vetor fosse um double ele percorria 8 bytes (tamanho de um double), exatamente o dobro do int.

#include <stdio.h>

int somaVetor(const int *v, int n){
    int soma = 0;          // iniciando a variável com 0
    for(int i= 0; i < n; i++){
        soma += *v;       // adiciona o valor contido naquela posição do vetor
        v++;             // incrementa a posição
    }
    return soma;
}

int main(){
    int teste[] = {12, 7, 30, 4, 18};
    int soma = somaVetor(teste, 5);

    printf("%d\n", soma);
    return 0;
}