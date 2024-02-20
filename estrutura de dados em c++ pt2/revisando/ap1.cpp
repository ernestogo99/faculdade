#include <iostream>
#include <new>
using namespace std;

struct funcionario{
    int matricula;
    double salario;
};

struct vetfun{
    int tam;
    int n;
    funcionario *v;

    vetfun(){
        tam=1;
        n=0;
        v=new funcionario[tam];
    }

    void inserir(int matricula,double salario){
        if(n==tam){
            tam=tam*2;
            funcionario *w=new funcionario[tam];
            for(int i=0;i<n;++i){
                w[i]=v[i];
            }
            delete[]v;
            v=w;
        }
        v[n].matricula=matricula;
        v[n].salario=salario;
        ++n;
    }



};





int selecionar(funcionario *v,int n,funcionario *w,double min,double max){
    int n_escolhidos=0;
    for(int i=0;i<n;++i){
        if((v[i].salario>min) and (v[i].salario<max)){
            w[n_escolhidos].salario=v[i].salario;
            w[n_escolhidos].matricula=v[i].matricula;
            ++n_escolhidos;
        } 
    }
    return n_escolhidos;
}

int main(){
    cout<<" digite os n func";
    int n;
    cin>>n;
    while(n<0){
        cout<<"digite um n positivo:  "<<endl;
        cin>>n;
    }

    vetfun v;
    vetfun w;

    int matricula;
    double salario;
    for(int i=0;i<n;++i){
        cout<<"funcionario ["<<i<<"]"<<endl;
        cout<<"digite a matricula: "<<endl;
        cin>>matricula;
        cout<<"digite o salario: "<<endl;
        cin>>salario;
        v.inserir(matricula,salario);
    }

    double min, max;
	cout << " Digite o minimo: " << endl;
	cin >> min;
	cout << "digite o max :" << endl;
	cin >> max;
	while( min > max){
	    cout << " Digite um intervalo valido"<< endl;
	    cout << "Digite o min: "<< endl;
	    cin>> min;
	    cout << "Digite o max: "<< endl;
	    cin >> max;
	}

    int n_escolhidos=selecionar(v.v,n,w.v,min,max);

    cout<<"o numero de funcionarios no intervalo foi: "<<n_escolhidos<<endl;
    for(int  i=0;i<n_escolhidos;++i){
        cout<<"funcionario ["<<i<<"]"<<endl;
        cout<<"matricula: "<<w.v[i].matricula<<endl;
        cout<<"salario: "<<w.v[i].salario<<endl;
    }

}