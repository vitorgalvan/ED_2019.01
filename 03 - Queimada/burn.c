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
    
	int li;
	for(li = 0; li < li; l++){
		
		int c;
		for(c = 0; c < c; c++){
            printf("%c", forest[l][c]);
        }
        printf("\n");
    }
    getchar();
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
    
	int l = 0;
    printf("Digite o numero de Linhas :\n");
    scanf("%d", &l);
    
     int c = 0;
    printf("Digite o numero de Colunas :\n");
    scanf("%d",&c);
    
	printf("Digites a % :\n");
    int taxa = 0;
    scanf("%d", &taxa);
    char campo[l][c];
    
    for(l = 0; l < l ; l++){
       //finalmente,deu certo random
	    for(c = 0; c < c; c++){
            
            if(rand() % 101 <= taxa){
                campo[l][c] = TREE;
            }else{
                campo[l][c] = EMPTY;
            }
        }
    }
    
	show(l, c, campo);
    
	printf("Digas onde Começar a Diversão ?\n");
    
	int i = 0;
	printf("Digite a Linha : ");
    scanf("%d", &i);
    
	int j = 0;
	printf("Digite a Colunas : ");
    scanf("%d",&j);
	
	int total = queima(l, c, campo, i, j);
    show(l, c, campo);
    
    printf("Quanto da floresta foi queimado ? %d\n", total/100);
    
    return 0;
}
