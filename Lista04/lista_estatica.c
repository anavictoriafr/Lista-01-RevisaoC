#include <stdio.h>
#include <stdlib.h>
#include "lista_estatica.h"

#define MAX 100

struct produto {
int codigo;
char nome[30];
float preco;
};


int lista_tem_espaco(Lista* li, int n){

}

float soma_precos(Lista* li){
    if(li == NULL) return 0;
    int soma = 0;
    
    
}