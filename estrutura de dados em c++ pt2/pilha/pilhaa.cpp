#include <iostream>
#include <new>
using namespace std;

struct pilha{
    int n;
    int tam;
    double *v;

    pilha(){
        tam=1;
        v=new double[tam];
        n=0;
    }
    ~pilha(){
        delete[]v;
    }
    bool vazia(){
        return n==0;
    }

    void empilhar(int elemento){
        if(n==tam){
            tam=tam*2;
            double *w=new double[tam];
            for(int i=0;i<n;++i){
                w[i]=v[i];
            }
            delete[]v;
            v=w;
        }
        v[n]=elemento;
        ++n;
    }
    int topo(){
        if(vazia()){
            cout<<"erro,pilha vazia";
            return 1;
        }
        return v[n-1];
    }

    void desempilhar(){
        if(vazia()){
            cout<<"erro,pilha vazia";
        }
        n--;
        if(n>0 and n<=tam/4){
            tam=tam/2;
            double *w=new double[tam];
            for(int i=0;i<n;++i){
                w[i]=v[i];
            }
            delete[]v;
            v=w;
        }
    }

    void imprimir(){
        cout<<"[";
        for(int i=0;i<n;++i){
            cout<<" "<<v[i];
        }
        cout<<"]";
        cout<<'\n';
    }
};

int main(){
    pilha p;
    int elemento;
    while(true){
        int acao;
        cout<<"\n 1-empilhar\n  \n2-desempilhar\n  \n3-retornar o topo da pilha\n \n4-imprimir\n ";
        cin>>acao;
        if(acao==1){
            cout<<"digite um elemento para empilhar \n";
            cin>>elemento;
            p.empilhar(elemento);
        }
        else if(acao==2){
            cout<<"o elemento: "<<p.topo()<<" foi removido\n";
            p.desempilhar();
        }
        else if(acao==3){
            if(p.vazia()){
                cout<<" ";
            }
            else{
                cout<<"o elemento do topo da pilha e: "<<p.topo()<<'\n';
            }
        }
        else if(acao==4){
            p.imprimir();
        }
        else{
            return false;
        }
    }
}