#include <iostream>
using namespace std;

int main(){
    cout<<"digite o dividendo: ";//funciona como o print do python
    int dividendo;// declarando a variável 
    cin>>dividendo; //funciona como o input do python

    while(dividendo<=0){
        cout<<"o numero deve ser positivo";
        cin>>dividendo;
    }
    cout<<"digite o divisor ";

    int divisor;
    cin>>divisor;

    while(divisor<=0){
        cout<<"o numero deve ser positivo";
        cin>>divisor;

    }
    cout<<"o resto da divisao de "<<dividendo<<" por "<<divisor<<" e "<<dividendo%divisor<<'\n';

}