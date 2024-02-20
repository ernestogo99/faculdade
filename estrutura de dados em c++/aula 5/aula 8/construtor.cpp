#include <iostream>
#include <new>
using namespace std;
struct vetor{
    double *v;
    int tam;
    int n;
    
    vetor(){
        cout<<"construtor \n";
        v=new double[1];
        tam=1;
        n=0;

    }
    ~vetor(){
        cout<<"destrutor \n";
        delete[] v;
    }

    void inserir(double num){
        if(n==tam){
            cout<<"redimensionamento \n";
            int novo_tam=tam*2;
            double *w=new double[novo_tam];
            for(int i=0;i<n;++i){
                w[i]=v[i];
            }
            delete[]v; v=w; tam=novo_tam;

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

}; //struct vetor

int main(){
    try{
        cout<<"antes de criar vet\n";
        vetor vet;
        cout<<"depois de criar vet\n";

        while(true){
            cout<<"digite o proximo numero(negativo para parar) ";
            double num;
            cin>>num;
            if(num<0) break;

            vet.inserir(num);
        }
        vet.imprimir();
    }
    catch(const bad_alloc &excecao){
        cout<<"erro,falta de memoria";
        return 1;
    }
}
