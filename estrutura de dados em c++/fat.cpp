#include <iostream>
using namespace std;

int fat(int n){
    if(n==0){
        return 1;
    }else{
       return n*fat(n-1);
    }
}
int main(){
    int n;
    do{
        cout<<"digite um número: ";
        cin>>n;
    }while(n<0);
    cout<<"o fatorial de "<<n<< " e "<<fat(n)<<'\n';
}