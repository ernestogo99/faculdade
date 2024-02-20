#include <iostream>
#include <new>
using namespace std;
struct errofila{
    private:
    const char *msg;

    public:
    errofila(const char *msg_erro){
        msg=(msg_erro);
    }

  const char* mensagem() const {
    return msg;
}
};

class fila{
    int tam;
    double *v;
    int prim,ult;

    void avancar(int &indice){
        if(indice==tam-1){
            indice=0;
        }
        else{
            ++indice;
        }
    }
    public:
    fila(){
        tam=1;
        v=new double[tam];
        prim=-1;

    }

    bool vazia(){
        return (prim==-1);
    }

    double desenfilar(){
        if(vazia()){
            throw errofila("tentou manipular fiza vazia");
        }

        double prim_ele=v[prim];
        if(prim==ult){
            prim=-1;
        }
        else{
            avancar(prim);
        }
        //todo:no caso em que a fila não ficou vazia,
        //verificar se é caso trocar o vetor por outro menor

        return prim_ele;
    }

void enfilar(double elem) {
    if (prim == -1) {
        prim = 0;
        ult = 0;
    } else {
        if ((prim == 0 and ult == tam - 1) or (ult + 1 == prim)) {
            int novo_tam = tam * 2;
            double *w = new double[novo_tam];
            for (int i = 0; not vazia(); ++i) {
                w[i] = desenfilar();
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
    double primeiro(){
        if(vazia()){
            throw errofila("consulta de primeiro em fila vazia");
        }
        return v[prim];
    }

    ~fila(){
        delete[]v;
    }

    
};

int main(){
    try{
        fila f;
        cout<<"enfileirando 1,2,3 \n";
        f.enfilar(1);
        f.enfilar(2);
        f.enfilar(3);
        cout<<"desinfileirando "<<f.desenfilar()<<'\n';
        cout<<"desinfileirando "<<f.desenfilar()<<'\n';
        cout<<"enfileirando 4 e 5\n";
        f.enfilar(4);
        f.enfilar(5);
        cout<<"desinfileirando "<<f.desenfilar()<<'\n';
        cout<<"enfileirando 6 e 7\n";
        f.enfilar(6);
        f.enfilar(7);
        while(not f.vazia()){
            cout<<"desenfilando: "<<f.desenfilar()<<'\n';
            
        }
        cout<<" vazia ao final? ";
        if(f.vazia()){
            cout<<"sim";
        }
        else{
            cout<<"nao";
        }


    }catch(const bad_alloc &e){
        cout<<"falha de alocação \n";
        return 1;
    }catch(const errofila &e){
        cout<<e.mensagem()<<'\n';
        return 2;
    }
        
    
}

