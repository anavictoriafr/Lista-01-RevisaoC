// Para ambos os casos a função executa 3 trocas.
// Expressão geral em função de n: n/2 (divisão de interios em C), quando n é ímpar o elemneto central não é alterado
// já que o laço executa apenas n / 2 vezes, parando antes de chegar ao elemento central. 

#include <stdio.h>

void inverter(int *inicio, int n){
    int *fim = inicio + n - 1;
    for(int i = 0; i < n/2; i++){
        int ultimo = *fim;
        *fim = *inicio;
        *inicio = ultimo;
        fim--;
        inicio++;
    }
}

int main(){
    int teste1[] = {12, 7, 30, 4, 18, 9};
    int teste2[] = {1, 2, 3, 4, 5, 6, 7};
    int n1 = 6, n2 = 7;

    inverter(teste1, n1);
    
     for(int i = 0; i < n1; i++){
        printf("%d ", teste1[i]);
    }

    printf("\n");

    inverter(teste2, n2);
 
    for(int i = 0; i < n2; i++){
        printf("%d ", teste2[i]);
    }

    return 0;
}