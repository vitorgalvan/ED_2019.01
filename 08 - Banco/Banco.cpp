#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;

struct Client{
    string id;
    int docs;
    int pac;

    Client(string id, int docs, int pac){
        this->id = id;
        this->docs = docs;
        this->pac = pac;
    }
};

struct Banco{
    vector <Client*> caixas;
    list <Client*> fila_entrada;
    queue <Client*> fila_saida;
};

void show_vector(Banco banco, bool ini_caixas){
    for(int a = 0;a < banco.caixas.size(); a++)
        if(ini_caixas == true && banco.caixas[a] != nullptr)
            cout << "[" << banco.caixas[a]->id << ":" << banco.caixas[a]->docs << ":" << banco.caixas[a]->pac << "] ";
        else
            cout << "[]";
}

void show_list(Banco banco){
    cout << "\nin: " << "{";
    for(Client* client: banco.fila_entrada){
        cout << client->id << ":" << client->docs << ":" << client->pac;
        if(client != banco.fila_entrada.back())
            cout << " ";
    }
    cout << "}" << endl;
}

void show_queue(Banco banco){
    cout << "out: {";
    while(!banco.fila_saida.empty()){
        cout << banco.fila_saida.front()->id << ":" << banco.fila_saida.front()->docs << ":" << banco.fila_saida.front()->pac;
        banco.fila_saida.pop();
        if(!banco.fila_saida.empty())
            cout << " ";
    }
    cout << "}" << endl;
}

void show_all(Banco banco, bool ini_caixas){
    show_vector(banco, ini_caixas);
    show_list(banco);
    show_queue(banco);
}

void tic_tac(Banco *banco, int qtd_caixas, int *docs_lost, int *docs_recive){
    while(!banco->fila_saida.empty())
        banco->fila_saida.pop();
    for(int a = 0; a < banco->caixas.size(); a++){
        if(banco->caixas[a] != nullptr){
            if(banco->caixas[a]->docs > 0){
                banco->caixas[a]->docs -= 1;
                *docs_recive += 1;
            }else{
                banco->fila_saida.push(banco->caixas[a]);
                banco->caixas[a] = nullptr;
            }
        }else{
            if(banco->fila_entrada.begin() != banco->fila_entrada.end()){
                banco->caixas[a] = banco->fila_entrada.front();
                banco->fila_entrada.pop_front();
            }
        }
    }    
    for(list<Client*>::iterator cliente = banco->fila_entrada.begin(); cliente != banco->fila_entrada.end();){
        if((*cliente)->pac > 0){
            (*cliente)->pac--;
            cliente++;
        }else{
            banco->fila_saida.push(*cliente);
            *docs_lost += (*cliente)->docs;
            cliente = banco->fila_entrada.erase(cliente);
        }
    }   
}

void qt_caixas(int docs_recive, int qtd_caixas){
    int qt_caixas = docs_recive - (qtd_caixas * 100);
}

int main(){

    Banco banco;
    int pac = 0, docs = 0, qtd_caixas = 0, docs_recive = 0, docs_lost = 0, turnos = 0;
    string cmd, id;
    bool ini_caixas = false;

    while(true){
        getline(cin, cmd);
        stringstream in(cmd);

        in >> cmd;

        if(cmd == "init"){
            if(ini_caixas == false){
                in >> qtd_caixas;
                for(auto a = 0; a < qtd_caixas; a++){
                    banco.caixas.push_back(nullptr);
                }
                ini_caixas = true;
            }
        }else if(cmd == "tic"){
            tic_tac(&banco, qtd_caixas, &docs_lost, &docs_recive);
            turnos++;
        }else if(cmd == "show"){
            show_all(banco, ini_caixas);
        }else if(cmd == "in"){
                in >> id >> docs >> pac;
                Client *client = new Client(id, docs, pac);
                banco.fila_entrada.push_back(client);
        }else if(cmd == "finalizar"){
            cout << "Docs recebidos: " << docs_recive << endl;
            cout << "Docs perdidos: " << docs_lost << endl;
            cout << "Turnos: " << turnos << endl;
        }else if(cmd == "end"){
            return 0;
        }else{
            cout << "Comando inválido" << endl;
        }
    }

   qt_caixas(docs_recive, qtd_caixas);

    return 0;
}