#include <iostream>
using namespace std;
int procurar(double *v,int n,double x){
    for(int i =0;i<n;i++){
        if(v[i]==x){
            return i;
        }
    }
    return -1;
}

int main() {
    cout<<"digite o tamanho do vetor "<<'\n';
    int tamanhov;
    cin>>tamanhov;
    double v[tamanhov];
    for(int i=0;i<tamanhov;++i){
        cout<<"digite os elementos de vetor "<<'\n';
        cin>>v[i];
    }
    for(int i=0;i<tamanhov;++i){
        cout<<v[i]<<" "<<'\n';
    }

    double valorProcurado;
    cout << "Digite um valor para procurar: ";
    cin >> valorProcurado;

    int indice = procurar(v, tamanhov, valorProcurado);

    if (indice != -1) {
        cout << "Valor encontrado na posição " << indice << " do vetor." <<'\n';
    } else {
        cout << "Valor não encontrado no vetor." << '\n';
    }

    
}