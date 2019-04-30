
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
    printf("Digite o Numero de Knights : \n");
    scanf("%d", &tam);
    
	int vect[tam];
    for(int i = 0; i < tam; i++){
        vect[i] = i + 1;
    }
    
	int escolhido = 0; 
    printf("The CHOSEN ONE : \n");
    scanf("%d", &escolhido);
    escolhido --;
    int qtd = tam - 1;
    mostrar(vect, tam);
    
	while(qtd--){
        
		int bater_botas = proximo_vivo(vect, tam, escolhido);
        vect[bater_botas] = 0;
        escolhido = proximo_vivo(vect, tam, bater_botas);
        mostrar(vect, tam);
    }

}
