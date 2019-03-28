
#include <stdio.h>
#include <stdbool.h>


int proximo_vivo(int vector[], int tam, int escolhido){
    
	int morto = (escolhido + 1) % tam;
	
    while(vector[morto] == 0){
        morto = (morto + 1) % tam;
    }
    return morto;
}


void mostrar(int vector[], int tam){
   
    bool primeiro = true;
    printf("[");
   
    for(int i = 0; i < tam; i++){
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
    print("Digite o Numero de Knights");
    scanf("%d", &tam);
    
	int vect[tam];
    for(int i = 0; i < tam; i++){
        vect[i] = i + 1;
    }
    
	int escolhido = 0; 
    scanf("%d", &escolhido);
    escolhido - - 1;
    int qtd = tam - 1;
    printVector(vect, tam);
    
	while(qtd--){
        
		int bater_botas = proximo_vivo(vect, tam, escolhido);
        vect[bater_botas] = 0;
        escolhido = proximo_vivo(vect, tam, bater_botas);
        mostrar(vect, tam);
    }

}
