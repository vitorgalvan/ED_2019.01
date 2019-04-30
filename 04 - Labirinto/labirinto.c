#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

const char parede = '#';
const char caminho = ' ';

typedef struct _coordenadas{
    int l;
    int c;

} pos;

#define vizinhos(l, c) {{l, c - 1}, {l - 1, c}, {l, c + 1}, {l + 1, c}}

void embaralhar(pos vet[],int tam){

    for(int i=0;i<tam;i++){
        
        int local = rand() % tam;
        pos auxiliar  = vet[i];
        vet[i] = vet[local];
        vet[local] = auxiliar;

    }

}

void mostrar(int nl,int nc,char lab[nl][nc]){
   for(int i = 0; i < nl; i++){
        
        for(int j = 0; j < nc; j++){
            
            if(lab[i][j] == parede){
                printf("█");
            }
            else{
                printf(" ");
            }
        }
        puts("");
    }
}

bool compara(int nl, int nc, char lab[nl][nc], int l, int c,char valor){
    
    if((l < 0) || (l >= nl) || (c < 0) || (c >= nc)){
        return false;
    }
    return lab[l][c] == valor; 
}

bool achar_saida(int nl, int nc, char lab[nl][nc], int lout, int cout){
    if(!compara(nl, nc, lab, lout, cout, caminho)){
        return false;
            }
      if(lab[lout][cout] == caminho){
        return false;
            }
        if((nl == lout) && (nc == cout)){
        return true;
    }
}

int main(){
 srand(time(NULL));

 int nl=0;
 int nc=0;
 printf("Digite o numero de Linhas : ");
 scanf("%d",&nl);
 printf("Digite o numero de Colunas : ");
 scanf("%d",&nc);

 char lab[nl][nc];

 for(int i = 0;i < nl;i++){
     for(int j = 0;j < nc;j++){
         lab[i][j] = parede;
     }

 }
    mostrar(nl,nc,lab[nl][nc]);

    return 0;
}
