#include <iostream>
using namespace std;

int main(){
    int n;
    int soma=0;
    
    
    while(n>0){
        cout<<"digite  numeros interos e finalize ao digitar um numero negativo: ";
        cin>>n;
        if (n%2==0){
            soma+=n;
            
        }
    }
    cout<<"a soma dos numeros pares e "<<soma;
}