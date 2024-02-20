#include <iostream>
#include <new>
using namespace std;

struct fila{
    struct noh{
        double elem;
        noh *prox;
        noh *ant;
    };
    noh *ini;
    noh *fim;

    fila(){
        ini=nullptr;
        fim=nullptr;
    }


    bool vazia(){
        return(ini==nullptr or fim==nullptr);    
    }

    double consultar_prim(){
        return ini->elem;
    }

    double consultar_ult(){
        return fim->elem;
    }

    void inserir_final(int elem){
        noh *p=new noh;
        p->elem=elem;
        p->prox=nullptr;
        if(vazia()){
            ini=fim=p;
        }
        else{
            fim->prox=p;
            p->ant=fim;
            fim=p;
        }
    }

    void inserir_inicio(int elem){
        noh*p=new noh;
        p->elem=elem;
        p->ant=nullptr;
        p->prox=nullptr;
        
        if(vazia()){
            ini=fim=p;
            
        }
        else{
            p->prox=ini;
            ini->ant=p;
            ini=p;
        }
    }

     void inserir_ordenado(double elem) {
        noh *p = new noh{elem, nullptr, nullptr};
        if (vazia() || elem <= ini->elem) {
            // Caso especial: inserção quando a fila está vazia ou o elemento é menor que o primeiro
            inserir_inicio(elem);
            return;
        }

        noh *atual = ini;

        // Encontrar o ponto de inserção
        while (atual->prox && elem > atual->prox->elem) {
            atual = atual->prox;
        }

        // Inserir o elemento
        p->prox = atual->prox;
        p->ant = atual;
        atual->prox = p;

        // Atualizar o ponteiro anterior do próximo nó, se existir
        if (p->prox) {
            p->prox->ant = p;
        }

        // Se o elemento foi inserido no final, atualizar o ponteiro de fim
        if (!p->prox) {
            fim = p;
        }
    }

    void remover_inicio(){
        if(vazia()){
            cout<<"erro,fila vazia";
        }
        
        noh *p=ini;
        // se ha apenas um elemento
        if(ini==fim){
            ini=fim=nullptr;
        }else{
            ini->prox->ant=nullptr;
            ini=ini->prox;
        }
        
        delete p;
    }

    void remover_final(){
        if(vazia()){
            cout<<"erro,fila vazia";
        }
        noh *p=fim;
        // se ha apenas um elemento na fila
        if(ini==fim){
            ini=fim=nullptr;
        }
        else{
            fim->ant->prox=nullptr;
            fim=fim->ant;
        }
        delete p;
    }



};

int main() {
    fila minhaFila;

    cout << "Inserindo elementos no final:" << endl;
    minhaFila.inserir_final(1);
    minhaFila.inserir_final(2);
    minhaFila.inserir_final(3);
    minhaFila.inserir_final(4);

    cout << "Consultando o primeiro elemento: " << minhaFila.consultar_prim() << endl;
    cout << "Consultando o último elemento: " << minhaFila.consultar_ult() << endl;

    cout << "Removendo elementos do início:" << endl;
    minhaFila.remover_inicio();
    minhaFila.remover_inicio();

    cout << "Inserindo elementos no início:" << endl;
    minhaFila.inserir_inicio(5);
    minhaFila.inserir_inicio(6);

    cout << "Consultando o primeiro elemento: " << minhaFila.consultar_prim() << endl;
    cout << "Consultando o último elemento: " << minhaFila.consultar_ult() << endl;

    cout << "Removendo elementos do final:" << endl;
    minhaFila.remover_final();
    minhaFila.remover_final();

    cout << "Fila final:" << endl;
    if (minhaFila.vazia()) {
        cout << "A fila está vazia." << endl;
    } else {
        cout << "Elementos na fila:" << endl;
        while (!minhaFila.vazia()) {
            cout << minhaFila.consultar_prim() << " ";
            minhaFila.remover_inicio();
        }
        cout << endl;
    }

    return 0;
}
