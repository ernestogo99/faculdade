#include <iostream>
#include <new>
using namespace std;

struct  pilha{
    int tam;
    int n;
    double *v;

    pilha(){
        tam=1;
        n=0;
        v=new double[tam];
    }

    void empilhar(int elemento){
        if(n==tam){
            tam=tam*2;
            double *w=new double[tam];
            for(int i=0;i<n;++i){
                w[i]=v[i];
            }
            delete[]v; v=w;
        }
        v[n]=elemento;
        ++n;
    }

    bool estavazia(){
        if(n==0) return true;
        else return false;
    }

    int topo(){
        if(estavazia()){
            cout<<"erro, a pilha esta vazia";
        }
        return v[n-1];
    }

    void desempilhar(){
        if(estavazia()){
            cout<<"erro, a pilha esta vazia ";
        }
        n--;
        if(n>0 and n<=tam/4){
            tam=tam/2;
            double *w=new double[tam];
            for(int i=0;i<n;++i){
                w[i]=v[i];
            }
            delete[]v; v=w;
        }
    }

    ~pilha(){
        delete[]v;
    }

};

struct fila{
    pilha entrada;
    pilha saida;

    void enfileira(int s){
        entrada.empilhar(s);
    }
    bool vazia(){
        return entrada.estavazia() and saida.estavazia();
    }

    void desinfileirar(){
        if(vazia()){
            cout<<"erro,fila vazia";
        }

        if(saida.estavazia()){
            while(!entrada.estavazia()){
                int elemento=entrada.topo();
                entrada.desempilhar();
                saida.empilhar(elemento);
            }
        }
        saida.desempilhar();

    }

  int top() {
    if (vazia()) {
        cout << "Erro: fila vazia" << endl;
        
    }

    if (saida.estavazia()) {
        while (!entrada.estavazia()) {
            int elemento = entrada.topo();
            entrada.desempilhar();
            saida.empilhar(elemento);
        }
    }
    
    return saida.topo();
}

 
};

int main(){
    fila f;

    f.enfileira(1);
    f.enfileira(2);
    f.enfileira(3);
    f.desinfileirar();
    cout<<"elementos da fila: ";
    while(!f.vazia()){
        cout<<f.top();
        f.desinfileirar();
        if(!f.vazia())cout<<" ";

        
    }


}

