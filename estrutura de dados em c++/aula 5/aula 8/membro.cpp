#include <iostream>
#include <new>
using namespace std;

struct vetor{
    double *v;
    int tam;
    int n;

    void inicializar(){
        v=new double[1];
        tam=1;
        n=0;
    }

    void terminar(){
        delete[]v;
    }

    void inserir(double num){
        if(n==tam){
            int novo_tam=tam*2;
            double *w= new double[novo_tam];
            for(int i=0;i<n;++i) w[i]=v[i];
            delete[] v; v=w; tam=novo_tam;

        }

        v[n]=num; ++n;
    }

    void imprimir(){
        cout<<"vetor ";
        for(int i=0;i<n;++i){
            cout<<' '<<v[i];
        }
        cout<<'\n';
    }


}; // struct vetor

int main(){
    try{
        vetor vet; vet.inicializar();

        while(true){
            cout<<"digite o proximo numero(negativo para parar) ";
            double num;
            cin>>num;

            if(num<0) break;
            vet.inserir(num);
        }

        vet.imprimir();

        vet.terminar();
    }
    catch(const bad_alloc &excecao){
        cout<<"erro,falta de memoria";
        return 1;
    }
}