#include <iostream>
using namespace std;

int main(){
    int n;
    double numero;
    double soma=0.0;
    cout<<"digite um numero inteiro positivo ";
    cin>>n;
    int i=0;
    while(i<n){
        i++;
        cout<<"digite um numero racional ";
        cin>>numero;
        soma+=numero;

    }
    cout<<"a media  dos numeros racionais e: "<<soma/n;
}