#include <iostream>
#include <new>
using namespace std;

int main(){
    unsigned long int tam;
    cout<<"tam: ";
    cin>>tam;

    try{
        double *v= new double[tam];
        cout<<"deu certo.\n";
        delete [] v;
    }
    catch(bad_alloc &e){
        cout<<"nao deu certo!\n";

    }
} 
