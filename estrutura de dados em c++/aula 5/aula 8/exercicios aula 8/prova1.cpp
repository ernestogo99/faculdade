#include <iostream>
#include <stdlib.h>
#include <new>
using namespace std;

struct funcionario{
    int matricula;
    double salario;
};
struct vetorFunc{
    funcionario *v;
    int tam;
    int n;
    vetorFunc(){
        tam = 1;
        n = 0;
        v = new funcionario[tam];
    }
    ~vetorFunc(){
        delete[] v;
    }
    void inserir(int matricula, double salario){
        if (n == tam){
            int novo_tam = 2*tam;
            funcionario *w = new funcionario[novo_tam];
            for (int i=0; i<n; i++){
                w[i]=v[i];
            }
            delete[] v; v=w; tam = novo_tam;
        }
        v[n].matricula = matricula;
        v[n].salario = salario; 
        n++;
    }
};

int selecionar(funcionario *v, int n, funcionario *w, double min, double max){
    int  n_escolhidos = 0;
    for(int i=0; i<n; i++){
        if ((v[i].salario > min )&& (v[i].salario < max))
        {
            w[n_escolhidos].salario= v[i].salario;
            w[n_escolhidos].matricula = v[i].matricula;
           n_escolhidos++;
        }
    }
    return n_escolhidos;
}
int main(int argc, char *argv[])
{
	cout << "Digite os n func: " << endl;
	int n ; cin >> n;
	while (n<0){
	    cout << "Digite um n positivo : " << endl;
	    cin >> n;
	}
	
	vetorFunc V;
	vetorFunc W;
	int matricula;
	double salario;
	for ( int i=0; i < n; i++){
	    cout << "Funcionario ["<< i << "]"<< endl;
	    cout << "digite a matricula : " << endl;
	    cin >> matricula; 
	    cout << " digite o salario : " << endl;
	    cin >> salario;
	    V.inserir(matricula, salario);
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
	int n_escolhidos = selecionar(V.v, n, W.v, min, max);
	cout << " O numero de funcionarios no intervalo foi: " << n_escolhidos<< endl;
	for (int i=0; i<n_escolhidos; i++){
	    cout << "Funcionario ["<<i<<"]"<<endl;
	    cout << "Matricula: "<< W.v[i].matricula << endl;
	    cout << "Salario: " << W.v[i].salario << endl;
	}
}