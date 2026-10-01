// O programa não vai avisar e vai colocar a informação em um espaço de memória que não está reservado para o vetor (stack overflow), 
//podendo comprometer outras informações e prejudicando a retomada do conteúdo do vetor no qual foi escrito o conteúdo

#include <stdio.h>

int meuStrlen(const char *s){
   int tamanho = 0;
   while( *s != '\0'){
        tamanho += 1;
        s++;
      }
   return tamanho;
}

void meuStrcpy(char *destino, const char *origem){
    int tamanho_origem = meuStrlen(origem);
    for(int i = 0; i < tamanho_origem; i++){
        *destino = *origem;
        destino++;
        origem++;
    }
    *destino = '\0';
}

int main(){
    char origem[] = "Estrutura de dados";
    char destino[20];

    meuStrcpy(destino, origem); 
    int tamanho_origem = meuStrlen(destino);
    printf("%s|%d \n", destino, tamanho_origem);

    return 0;
}