// Ele funciona nos testes pois normalmente há espaço suficiente para executar o realloc, no entanto é errado fazer v = realloc(v, ...) pois
// em caso de erro no realloc ele vai retornar NULL sobreescrevendo o endereço que estava em v e tornando impossível liberá-lo por meio do free(v)
// causando vazamento de memória.
// Meu programa chama o realloc 9 vezes para ler 100 numeros, se sua capacidade crescesse de 1 em 1 seriam 998 chamadas de realloc
// No meu programa são copiados 1022 elementos, no caso de copiar de um em 1 seriam 499.999 elementos copiados.

#include <stdlib.h>
#include <stdio.h>

int main(){
    int tam = 0; int cap = 2, reallocs = 0, soma = 0;
    int *num ;

    num = malloc(2*sizeof(int));
    if(num == NULL){
        printf("Ponteiro nao alocado\n");
        return 1;
    }
    
    while(1){
        if(tam == cap){
            cap *= 2;
            int *novo = realloc(num, cap * sizeof(int));
            if(novo == NULL){
                printf("novo ponteiro nao pode ser alocado\n");
                free(num);
                return 1;
            }
            num = novo;
            reallocs++;
        }
        printf("Digite um numero: \n");
        scanf("%d", num + tam);

        if(num[tam] == -1){
            break;
        } 

        soma += num[tam];
        tam++;
    }

    printf("tam %d cap %d reallocs %d soma %d\n", tam, cap, reallocs, soma);
    
    free(num);
    num = NULL;

}