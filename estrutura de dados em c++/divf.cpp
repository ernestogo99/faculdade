#include <iostream>
using namespace std;

int ler_int_positivo(){
    int numero;
    cin>>numero;

    while(numero<=0){
        cout<<"o numero deve ser positivo";
        cin>>numero;
    }
    return numero;
}
int main(){
    cout<<"digite um numero: ";
    int dividendo= ler_int_positivo();
    cout<<"digite o divisor: ";
    int divisor= ler_int_positivo();

    cout<<"o resto da divisao de "<<dividendo<<" por "<<divisor<<" e "<<dividendo%divisor<<'\n';

}