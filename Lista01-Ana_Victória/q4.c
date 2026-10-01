#include <stdio.h>

void  minMax(const int *v, int n, int *min, int *max){
    if (n > 0){ // tratamento dos casos de n <= 0

        *min = *v; 
        *max = *v;
        
        for (int i = 0; i < n; i++){
        if ( *min > *v){
            *min = *v;
        }
        if ( *max < *v){
            *max = *v;
        }
        v++;
    }
}
}

int main(){
    int teste[] = {12, 7, 30, 4, 18, 9};
    int min = -1, max = -1; // iniciando as variáveis com valores de controle

    minMax(teste, 0, &min, &max); // teste no caso n <= 0
    printf("%d %d \n", min, max);

    minMax(teste, 6, &min, &max); // teste normal
    printf("%d %d", min, max);

    return 0;
}