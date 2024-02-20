#include <iostream>
#include<new>
using namespace std;

struct errofila{
    const char *msg;

    errofila(const char *msg_erro){
        msg=msg_erro;
    }
    const char *mensagem ()const{
        return msg;
    }


};

struct fila{
    int tam;
    int prim,ult;
    double *v;

    fila(){
        tam=1;
        v=new double[tam];
        prim=-1;
    }
    ~fila(){
        delete[]v;
    }
    void avancar(int &indice){
        if(indice==tam-1){
            indice=0;
        }
        else{
            ++indice;
        }
    }
    bool vazia(){
        return  prim==-1;
    }

   void enfileirar(double elem) {
    if (prim == -1) {
        prim = 0;
        ult = 0;
    } else {
        if ((prim == 0 and ult == tam - 1) or (ult + 1 == prim)) {
            int novo_tam = tam * 2;
            double *w = new double[novo_tam];
            for (int i = 0,j=prim; i<tam; ++i) {
                w[i] = v[j];
                avancar(j);
            }
            delete[] v;
            v = w;
            prim = 0;
            ult = tam - 1;
            tam = novo_tam;
        }
        avancar(ult);
    }
    v[ult] = elem;
}

    void desinfileirar(){
        if(vazia()){
            throw errofila("erro,fila vazia");
        }
        if(prim==ult){
            prim=-1;
        }
        else{
            avancar(prim);
        }
    }
int topo() {
    if (vazia()) {
        throw errofila("erro, fila vazia");
    }
    return v[prim]; // Retorna o elemento atual no topo da fila
}
    
};

int main(){
    fila f;
    f.enfileirar(10);
    f.enfileirar(20);
    cout<<"o primeiro elemento e: "<<f.topo();
    f.desinfileirar();
     cout<<"o primeiro elemento e: "<<f.topo();

}
