#include <iostream>
#include <string>
#include <new>
using namespace std;

struct dic{
    struct noh{
        int chave;
        string nome;
        noh *prox;

        noh(){
            chave=-1;
            nome="";
            prox=nullptr;
        }
    };
    noh *topo;
    dic(){
        topo=nullptr;
    }

    string consultar(int chave){
        noh *p=topo;
        while(p!=nullptr){
            if(p->chave==chave){
                return p->nome;
           } 
             p=p->prox;
        }
        return "chave não encontrada";
    }

    bool contem(int chave){
        noh *p=topo;
        while(p!=nullptr){
            if(p->chave==chave){
                return true;
            }
            p=p->prox;
        }
        return false;
    }

    void inserir(int chave,string nome){
        if(contem(chave)){
            cout<<"chave ja existe no dicionario ";
            return;
        }
        noh *p=new noh;
        p->prox=topo;
        p->chave=chave;
        p->nome=nome;
        topo=p;

    }
    
  bool remover(int chave) {
    if (not contem(chave)) {
        return false; // Chave não encontrada
    }

    noh* atual = topo;
    noh* ant = nullptr;

    // Se o elemento a ser removido está no início da lista
    if (atual->chave == chave) {
        topo = atual->prox;
        delete atual;
        return true;
    }

    // Procurando a chave
    while (atual != nullptr and atual->chave != chave) {
        ant = atual;
        atual = atual->prox;
    }

    // Remover o nó da lista
    ant->prox = atual->prox;
    delete atual;
    return true;
}

};

int main() {
    dic dicionario;

    dicionario.inserir(1001, "Alice");
    dicionario.inserir(1002, "Bob");
    dicionario.inserir(1003, "Charlie");
    dicionario.inserir(1004, "David");

    cout << "Consultando chave 1002: " << dicionario.consultar(1002) << endl;
    cout << "Consultando chave 1005: " << dicionario.consultar(1005) << endl;

    cout << "Removendo chave 1003" << endl;
    bool removido = dicionario.remover(1004);
    if (removido) {
        cout << "Chave 1004 removida com sucesso" << endl;
    } else {
        cout << "Chave 1004 não encontrada no dicionário" << endl;
    }

    cout << "Consultando chave 1003: " << dicionario.consultar(1004) << endl;

    return 0;
}
