// A assinatura void dobrar(int n) estaria passando o parâmetro como valor,ou seja, 
// eu estaria apenas usando o valor daquela variável sem realmente altera-lo.
// Assim, quando a função terminasse de ser executada o valor dobrado sumiria e a variável continuaria com o valor original.

#include <stdio.h>

void dobrar (int *n){
    *n = *n * 2; // modificando o número no endereço apontado por *n
}

int main(){
    int n = 21;
    dobrar(&n);
    printf("%d\n", n);
    return 0;
}


