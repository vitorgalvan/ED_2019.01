#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char TREE = '#';
const char FIRE = 'o';
const char EMPTY = '.';
const char ASH = 'x';


int linhas[] = {0, -1, 0, 1};
int coluna[] = {-1, 0, 1, 0};

int lados = sizeof(linhas)/sizeof(int);


void shuffle(int vet[], int size){
	
	int i;
	for(i = 0; i < size; i++){
        int esc = rand() % size;
        int temp = vet[i];
        vet[i] = vet[esc];
        vet[esc] = temp;
    }
}

void show(int l, int c, char forest[l][c]){

	for(int li = 0; li < l; li++){
		for(int ci = 0; ci < c; ci++){
            printf("%c", forest[li][ci]);
        }
            printf("\n");
    }
  puts("");
}

int queima(int nl, int nc,char campo[nl][nc + 2], int l, int c){
    
	if((l < 0) ||(l >= nl) ||(c <  0) ||(c >= nc)){
        return 0;
    }
    
	if(campo[l][c] != TREE){
        return 0;
    }
    
	campo[l][c] = FIRE;
    show(nl, nc, campo);
    int quantidade = 1;
    int viz[] = {0, 1, 2, 3};
    shuffle(viz, lados);
   int v;
    for(v = 0; v < lados; v++){
        int i = viz[v];
       
        quantidade += queima(nl, nc, campo, l + linhas[i], c + coluna[i]);
    }
   
    campo[l][c] = ASH;
    show(nl, nc, campo);
    
	return quantidade;
}

int main(){
    
	srand(time(NULL));
    
	int nl = 0;
    printf("Digite o numero de Linhas :\n");
    scanf("%d", &nl);
    
     int nc = 0;
    printf("Digite o numero de Colunas :\n");
    scanf("%d",&nc);
    
	printf("Digites a %%:\n");
    int taxa = 0;
    scanf("%d", &taxa);
    char campo[nl][nc];
    
    for(int l = 0; l < nl ; l++){
	    for(int c = 0; c < nc; c++){
            if(rand() % 101 <= taxa){
                campo[l][c] = TREE;
            }else{
                campo[l][c] = EMPTY;
            }
        }
    }
    
	show(nl, nc, campo);
    
	printf("Digas onde Começar a Diversão ?\n");
    
	int i = 0;
	printf("Digite a Linha : ");
    scanf("%d", &i);
    
	int j = 0;
	printf("Digite a Colunas : ");
    scanf("%d",&j);
	
	float total = queima(nl, nc, campo, i, j);
  total = total/100;
    show(nl, nc, campo);
    printf("Quanto da floresta foi queimado ? %0.2f", total);
    
    return 0;
}
