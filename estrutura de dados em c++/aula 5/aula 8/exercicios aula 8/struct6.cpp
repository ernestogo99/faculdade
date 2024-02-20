#include <iostream>
#include <new>
using namespace std;
struct vetor{
    double *v;
    int tam;
    int n;

    vetor(){
        cout<<"construtor\n";
        v=new double[1];
        tam=1;
        n=0;
    }

    ~vetor(){
        cout<<"destrutor\n";
        delete[] v;
    }


     void imprimir(){
        cout<<"vetor \n";
        for(int i=0;i<n;++i){
            cout<<' '<<v[i];
        }
        cout<<'\n';
    }

    void inserir(double num){
        for(int j=0;j<n;++j){
            if(v[j]==num){
                cout<<"insercao falhou,elemento ja presente\n ";
                return;
            }
        }
        
        if(n==tam){
            cout<<"redimensionamento\n";
           int novotam=tam*2;
           double *w=new double[novotam];
           for(int i=0;i<n;++i) w[i]=v[i];
           
           delete[] v; v=w; tam=novotam;

        }
        v[n]=num; ++n;
        cout<<"elemento inserido com sucesso\n";
        
    }

    void remover(double num){
        int removeri=-1;
        for(int j=0;j<n;++j){
            if(num==v[j]){
                removeri=j;
                break;
            }
        }
       
        if(removeri!=-1){
            for(int i=removeri;i<num-1;++i){
            v[i]=v[i+1];
        }
            n--;
            cout<<"elemento removido com sucesso\n";
        }
        else{
            cout<<"elemento nao encontrado no conjunto\n";
        }

        

        
    }

};

int main(){
    try{
        vetor vet;

        while(true){
            vet.imprimir();

            cout<<"escolha uma operacao:\n";
            cout<<"1: inserir elemento \n";
            cout<<"2: remover elemento\n";
            cout<<"3: encerrar o programa\n";
            int escolha;
            cin>>escolha;

            if(escolha==1){
                int elemento;
                cout<<"digite um numero inteiro para inserir ";
                cin>>elemento;
                vet.inserir(elemento);

               
            }
            else if(escolha==2){
                int elemento;
                cout<<"digite um numero para ser removido ";
                cin>>elemento;
                vet.remover(elemento);
            }
            else if(escolha==3){
                
                break;
            }
            else{
                cout<<"operacao invalida";
            }


        }

    }
    catch(const bad_alloc &excecao){
        cout<<"erro, falta de memoria\n";
        return 1;
    }
}


