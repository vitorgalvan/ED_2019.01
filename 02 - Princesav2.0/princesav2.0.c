#include <stdio.h>
#include <stdbool.h>


int proximo_vivo(int v[], int tam, int escolhido, int dir){
    
	int pos = 0;
	
    if(dir == 1){
        pos = (escolhido + dir) % tam;
    }else{
        pos = (escolhido + tam - 1) % tam;
    }
    while(v[pos] == 0){
        if(dir == 1){
            pos = (pos + dir) % tam;
        }else{
            pos = (pos + tam - 1) % tam;
        }
    }
    return pos;
}

void printVetor(int v[], int tam, int escolhido){
   
    bool primeiro = true;
    printf("[");
    int i;
    
void mostrar(int vector[], int tam){
    
	bool primeiro = true;
	
    printf("[");
    int i;
    for(i = 0; i < tam; i++){
        if(vector[i] != 0){
            if(primeiro){
                primeiro = false;
            }else{
                printf(" ");
            }
            printf("%d", vector[i]);
        }
    }
    printf("]\n");
}

int main(){
	
    int tam = 0;
    printf("Digite o Numero de Knights : ");
    scanf("%d", &tam);
    
    int qtd = tam - 1;
    int escolhido = 0;
    
    printf("Digite o Knight Escolhido : ");
    scanf("%d", &escolhido);
    escolhido = escolhido - 1;
    
    int fase = 0;
    printf("Digite a Fase Positiva ou Negativa : ");
    scanf("%d", &fase);
    
    int v[tam];
    int i;
    for(i = 0; i < tam; i++){
        v[i] = (i + 1) * fase;
        fase = fase * (-1);
    }
    printVetor(v, tam, escolhido);
    while(qtd--){
    	int i;
        int dir = (v[escolhido] > 0) ? 1 : -1; 
        
        int saltos = (v[escolhido] > 0) ? v[escolhido] : -v[escolhido];
        int bater_botas = proximo_vivo(v, tam, escolhido, dir);
        v[bater_botas] = 0;
        escolhido = bater_botas;
        for(i = 0; i < saltos; i++){
            escolhido = proximo_vivo(v, tam, escolhido, dir);
        }
        mostrar(v, tam, escolhido);
    }
    return 0;
}
