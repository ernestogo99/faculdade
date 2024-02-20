#include <iostream>
#include <string>
#include <new>
#include <sstream>
using namespace std;

class pilha{
    int tam; // tamanho do vetor
    string *v; // ponteiro para o vetor
    int n;  // numero de elementos de v
public:
    pilha(){
        tam=1;
        v=new string[tam];
        n=0;
    }

    void empilhar(string  s){
        if(n==tam){
            tam=2*tam;
            string *w=new string[tam];
            for(int i =0;i<n;++i){
                w[i]=v[i];
            }
            delete[]v; v=w;
        }
        v[n]=s; ++n;
    }

    bool estavazia(){
        //if(n==0) return true
        //else return false
        return(n==0);
    }

    // pre condição: a pilha não esta vazia

    void desempilhar(){    
        if(n==0){
            cout<<"erro,pilha vazia";
            return;
        }
        --n;

        if(n>0 && n<=tam/4){
            tam=tam/2;
            string *w=new string[tam];
            for(int i=0;i<n;++i){
                w[i]=v[i];
            }
           delete[]v; v=w;
        }

        
    }

    int tamanho(){
        return n;
    }

    string topo(){
        if(n==0){
            cout<<"erro,pilha vazia";
            return "";
        }
        return v[n-1];

    }

    ~pilha(){
        delete[]v;
    }
};

bool ehOperador(const string &op) {
    return op == "+" || op == "-" || op == "*" || op == "/";
}


