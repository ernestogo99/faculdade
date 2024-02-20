#include <iostream>
#include <new>
using namespace std;

struct funcionario{
    int matricula;
    double salario;

};

int selecionar(funcionario *v,int n,funcionario *w,double min,double max){
    int escolhidos=0;
    for(int i=0;i<n;++i){
        if(v[i].salario>=min and v[i].salario<=max){
            w[escolhidos].salario=v[i].salario;
            w[escolhidos].matricula=v[i].matricula;
            ++escolhidos;
        }
    }
    return escolhidos;
}

int main(){
    int n=0;
    while(n<1){
        cout<<"digite o numero de funcionarios \n";
        cin>>n;
        if(n<1){
            cout<<"digite um numero de funcionarios que seja maior que 0\n";
        }
    }

    try{
        funcionario *v=new funcionario[n];
        funcionario *w=new funcionario[n];
        for(int i=0;i<n;++i){
            cout<<"digite a matricula do funcionario: "<<i+1<<endl;
            cin>>v[i].matricula;
            cout<<"digite o salario do funcionario: "<<i+1<<endl;
            cin>>v[i].salario;
        }

        int min=1; int max=0;
        while(max<=min ){
            cout<<"digite o valor minimo de salario: \n";
            cin>>min;
            cout<<"digite o valor maximo de salario: \n";
            cin>>max;
            if(max<=min){
                cout<<"o valor maximo deve ser maior que o minimo";
            }
        }

       int quantidade=selecionar(&v[0],n,&w[0],min,max);
       cout<<"segue abaixo os funcionarios escolhidos\n";
       for(int i=0;i<quantidade;++i){
            cout<<"o funcionario de matricula: " <<w[i].matricula <<
            "possui salario de: "<< w[i].salario <<endl;
       }

       delete[]v; delete[]w;
    }

    catch(const bad_alloc *&e){
        cout<<"erro de alocacao de memoria ";
        return 1;
    }
}