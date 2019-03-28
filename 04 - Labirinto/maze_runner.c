#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

const char PAREDE = '#';
const char CAMINHO = ' ';

int linhas[] = {0, -1, 0, 1};
int colunas[] = {-1, 0, 1, 0};

int ladus = sizeof(linhas)/sizeof(int);

void shuffle(int vet[], int tam){
    
	int i;
	for(i = 0; i < tam; i++){
        int esc = rand() % tam;
        int aux = vet[i];
        vet[i] = vet[esc];
        vet[esc] = aux;
    }
    
}

void mostrar(int linha, int colunas, char maze[linha][colunas]){
   
   int l;
    for(l = 0; l < linha; l++){
    	int c;
        for(c = 0; c < colunas; c++){
            printf("%c ", maze[l][c]);
        }
        printf("\n");
    }
 
}

bool find_out(int nlinha, int ncolunas, char maze[nlinha][ncolunas], bool ja_passei[nlinha][ncolunas], int linha, int coluna, int lsaida, int csaida){
    
	if(maze[linha][coluna] != CAMINHO){
        return false;
    }
    
	if(ja_passei[linha][coluna] == true){
        return false;
    }
    
	ja_passei[linha][coluna] = true;
    maze[linha][coluna] = '.';
   
    if((linha == lsaida)&&(coluna == csaida)){
        return true;
    }
   int i;
	for(i = 0; i < ladus; i++){
        bool caminho = find_out(nlinha, ncolunas, maze, ja_passei, linha + linhas[i],coluna + colunas[i], lsaida, csaida);
        if(caminho){
            return true;
        }
    }
   
    maze[linha][coluna] = CAMINHO;
   
    return false;
    
}

void faz_lab(int nlinha, int ncoluna, char lab[nlinha][ncoluna], int linha, int coluna){
    
	if((linha < 1) ||(linha >= nlinha - 1) ||(coluna <  1) ||(coluna >= ncoluna - 1)){
        return;
    }
   
    if(lab[linha][coluna] != PAREDE){
        return;
    }
  
    int cont = 0;
    int i;
    for(i = 0; i < ladus; i++){
        int l_auxili = 0;
		l_auxili = linha + linhas[i];
        
        int linha_col = 0;
		linha_col = coluna + colunas[i];
        if(lab[l_auxili][linha_col] == CAMINHO) cont++;
    }
   
    if(cont > 1){
        return;
    }
   
    lab[linha][coluna] = CAMINHO;
 
    int neib[] = {0, 1, 2, 3};
    shuffle(neib, ladus);
    int v;
	for(v = 0; v < ladus; v++){
        int i = neib[v];
        faz_lab(nlinha, ncoluna, lab, linha + linhas[i], coluna + colunas[i]);
    }
  
}

int main() {
    
	srand(time(NULL));
   
   
    int c = 0;
    printf("Digite o numero de colunass :\n");
    scanf("%d",&c);
    
    int l = 0;
    printf("Digite o numero de linhas :\n");
    scanf("%d",&l);
   
    getchar();
    char lab[l][c];
    bool ja_passei[l][c];
    
	for(l = 0; l < l; l++){
        for(c = 0; c < c; c++){
            lab[l][c] = PAREDE;
            ja_passei[l][c] = false;
        }
    }
  
    faz_lab(l, c, lab, 1, 1);
    mostrar(l, c, lab);
    
	int linicio = 0;
    int cinicio = 0;
    int lfim = 0;
    int cfim = 0;
    
	do{
        printf("Digite a posição inicial:\n");
        scanf("%d%d", &linicio, &cinicio);
    }

	while((lab[linicio][cinicio] == PAREDE)||(linicio < 0 )||(linicio >= l)||(cinicio < 0)||(cinicio >= c));
    
	do{
        printf("Digite a posição final:\n");
        scanf("%d%d", &lfim, &cfim);
    }while((lab[lfim][cfim] == PAREDE)||(lfim < 0)||(lfim >= l)||(cfim < 0)||(cfim >= c));
   
    bool out = find_out(l, c, lab, ja_passei, linicio, cinicio, lfim, cfim);
    mostrar(l, c, lab);
}
