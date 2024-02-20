#include <iostream>
#include <new>
using namespace std;

struct pilha{
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
            cout<<("erro,a pilha esta vazia\n");
            return 1;
        }
        else{
            return v[n-1];
        }
        
    }

    void desempilhar(){
        if(estavazia()){
            cout<<("erro,a pilha esta vazia\n");
           
        }
        else{
            n--;
        }

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
        cout<<'\n';
       
    }

    ~pilha(){
        delete[]v;
    }

};

int main(){
    pilha p;
    int elemento;
    while(true){
        char acao;
        cout<<"e: empilhar\n d: desempilhar\n t:retornar o topo\n; i: imprimir\n  ";
        cout<<"digite qualquer outra coisa para sair do programa \n";
        cin>>acao;
        if(acao=='e'){
            cout<<"digite um elemento para empilhar: \n";
            cin>>elemento;
            p.empilhar(elemento);
        }
        else if(acao=='d'){
            p.desempilhar();
        }
        else if(acao=='t'){
            cout<<"o elemento do topo e "<<p.topo()<<'\n';
        }
        else if(acao=='i'){
            p.imprimir();
        }
        else{
            return false;
        }
    }
}