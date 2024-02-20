#include <iostream>
#include <new>
using namespace std;

int main(){
    try{
        unsigned long int tam;
        cout<<"tam: ";
        cin>>tam;

        double *v=new double[tam];
        cout<<"deu certo\n";

        delete[] v;

    }
    catch(bad_alloc &excecao){
        cout<<"falha na alocacao do vetor";
        return 1;
    }
}