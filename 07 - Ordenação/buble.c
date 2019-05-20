#include "stdio.h"

void SWAP(int vector[], int a, int b){
    int aux = vector[a];
    vector[a] = vector[b];
    vector[b] = aux;
} 

void Show(int vector[], int n){
    printf("[");
    for(int a = 0; a < n; a++){
        printf("%d", vector[a]);
        if(a < n - 1)
            printf(" ");
    }
    printf("]\n");
}

void bubble(int vector[], int n){
    for(int i = 0;i < n;i++){
        for(int j = 0;j<n-1;j++){
            if(vector[j] > vector[j+1]){
                SWAP(vector,j,j+1);
                Show(vector,n);
            }
        }
    }
}

int main(){

    int n = 0;
    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &n);
    int vector[n];
    
    printf("Digite os valores do vetor: \n");
    for(int a = 0; a < n; a++){
        scanf("%d", &vector[a]);
    }
    Show(vector, n);
    bubble(vector, n);
    Show(vector, n);
    return 0;
}
