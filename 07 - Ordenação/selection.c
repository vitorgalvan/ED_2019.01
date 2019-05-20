#include "stdio.h"

void Show(int vector[], int n){
    printf("[");
    for(int a = 0; a < n; a++){
        printf("%d", vector[a]);
        if(a < n - 1)
            printf(" ");
    }
    printf("]\n");
}

void SWAP(int vector[], int a, int b){
    int aux = vector[a];
    vector[a] = vector[b];
    vector[b] = aux;
} 

int small(int vector[], int n, int index){
    int imenor = index;
    for(int a = index + 1; a < n; a++)
        if(vector[a] < vector[imenor])
            imenor = a;
    return imenor;
}

void selection(int vector[], int n){
    for(int a = 0; a < n; a++){
        int index = small(vector, n, a);
        SWAP(vector, a, index);
    }
}

int main(){

    int n = 0;
    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &n);
    int vector[n];
    printf("Digite os valores do vetor: \n");
    for(int a = 0; a < n; a++)
        scanf("%d", &vector[a]);
    selection(vector, n);
    Show(vector, n);

    return 0;
}
