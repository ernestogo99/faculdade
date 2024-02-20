#include <iostream>
#include <new>
using namespace std;

class fila{
    struct noh{
        double elem;
        noh *prox;
    };
    noh *inicio;
    noh *fim;

    public:
    double consultar_primeiro(){
        return inicio->elem;
    }
    bool vazia(){
        return (inicio==nullptr or fim==nullptr);
    }

    double desenfilar(){
        noh *p=inicio;
        double elem=p->elem;
        inicio=inicio->prox;
        if(inicio==nullptr) fim=nullptr;
        delete p;
        return elem;
    }

    void enfilar(double elem){
        noh *p=new noh;
        p->elem=elem;
        p->prox=nullptr;

        if(vazia()){
            inicio=fim=p;
        }
        else{
            fim->prox=p;
            fim=p;
        }
    }

    fila(){
        inicio=fim=nullptr;
    }

    ~fila(){
        while(not vazia()){
            desenfilar();
        }
    }
};



int main(){
    try{
        fila f;

        f.enfilar(1);
        f.enfilar(2);
        f.enfilar(3);
        cout<<"desenfilando: "<<f.desenfilar()<<endl;
        cout<<"desenfilando: "<<f.desenfilar()<<endl;
        f.enfilar(4);
        f.enfilar(5);
        f.enfilar(6);
        while(not f.vazia()){
            cout<<"1: "<<f.consultar_primeiro()<<endl;
            f.desenfilar();
        }
        f.enfilar(7);
        f.enfilar(8);



    }
    catch(const bad_alloc &e){
        cout<<"falha de alocaçao \n";
        return 1;
    }
}