#include <iostream>
#include <new>
using namespace std;

struct vetor{
    double *v; // ponteiro p/ vetor alocado dinamicamente
    int tam; // tamanho(num de posições ) do vetor
    int n; // numero de elementos armazenados
};

void inicializar(vetor &vet){ // referencia para modificar a 
// struct passada como argumento
    
    vet.v=new double[1];
    vet.tam=1;
    vet.n=0;
}
void terminar(vetor &vet){
    delete[] vet.v;
}
void inserir(vetor &vet,double num){
    if(vet.n==vet.tam){
        int novo_tam=vet.tam*2;
        double *w=new double[novo_tam];
        for(int i=0;i<vet.n;++i) w[i]=vet.v[i];
        
        delete[] vet.v; vet.v=w; vet.tam=novo_tam;
    }
    vet.v[vet.n]=num; ++vet.n;
}

void imprimir(vetor &vet){
    cout<<"vetor: ";
    for(int i=0;i<vet.n;++i){
        cout<<' '<<vet.v[i];
    }
    cout<<'\n';

}

int main(){
    try{
        vetor vet; inicializar(vet);
        
        while(true){
            cout<<"digite o proximo numero(menor que 0 para parar): ";
            double num;
            cin>>num;
            if(num<0) break;
            inserir(vet,num);
        }
        imprimir(vet);

        terminar(vet);
    }
    catch(const bad_alloc &excecao){
        cout<<"erro,falta de memoria  \n";
        return 1;

    }
}

