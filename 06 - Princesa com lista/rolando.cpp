#include <iostream>

using namespace std;

struct Node{
    int value;
    Node *next;
    Node *prev;
    Node(int value = 0){
        this->value = value;
        this->next = this;
        this->prev = this;
    }   
};

void kill(Node * vitima){
    vitima->prev->next = vitima->next;
    vitima->next->prev = vitima->prev; 
}

void Show(Node * lista, Node * assassino){
    Node *aux = lista;
    if(lista != nullptr){
        cout << "[";
        do{
            if(aux == assassino && aux->value < 0)
                cout << "<";
            cout << aux->value;
            if(aux == assassino && aux->value > 0)
                cout << ">";
            aux = aux->next;       
            if(lista != aux)
                cout << " ";
        }while(lista != aux);
        
        cout << "]\n";
    }
}

void Insert(Node * ref, int value){
    Node * no = new Node(value);
    no->prev = ref;
    no->next = ref->next;
    ref->next = no;
    no->next->prev = no;
}

int lista_size(Node * lista){
    Node * aux = lista;
    int size = 0;
    do{
        size++;
        aux = aux->next;
    }while(aux != lista);
    return size;
}

Node* find_killer_right(Node * assassino, int saltos){
    Node * aux = assassino;
    for(int cont = 0; cont < saltos; cont++){
        aux = aux->next;
    }
    return aux;
}

Node* find_killer_left(Node * assassino, int saltos){
    Node * aux = assassino;
    for(int cont = 0; cont < saltos; cont++){
        aux = aux->prev;
    }
    return aux;
}

Node* Value_menor(Node * ref){
    Node * no = ref;
    Node * menor = no;
    do{
        no = no->next;
        if((no->value < 0 ? -no->value : no->value) < (menor->value < 0 ? -menor->value : menor->value))
            menor = no;
    }while(no != ref);
    return menor;
}

Node * find_first_killer(Node * assassino, int pos){
    Node * aux = assassino;
    for(int cont = 0; cont < pos - 1; cont++){
        aux = aux->next;
    }
    return aux;
}

int main(){
    int Qtd_people = 0;
    int killer = 0; 
    int dir = 0;
    int saltos = 0;
    int fase = 0;
    
    cin >> Qtd_people >> killer >> fase;
    Node * lista = new Node();
    if(fase == 1)
        lista->value = 1;
    else 
        lista->value = -1;
    Node * index = lista;
    for(int i = 2; i <= Qtd_people; i++){
        fase *= (-1);
        Insert(index, (i*fase) );
        index = index->next;
    }
    Node * assassino = find_first_killer(lista, killer);
    Show(lista, assassino);
    while(lista_size(assassino) != 1){
        dir = assassino->value < 0 ? -1 : 1;
        saltos = assassino->value < 0 ? -assassino->value : assassino->value;
        if(dir < 0)
            kill(assassino->prev);
        else
            kill(assassino->next);
        if(assassino->value < 0)
            assassino = find_killer_left(assassino, saltos);
        else
            assassino = find_killer_right(assassino, saltos);
        Show(Value_menor(assassino), assassino);
    }
    return 0;
}
