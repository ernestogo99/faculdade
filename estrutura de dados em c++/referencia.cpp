#include <iostream>
using namespace std;
void nao_troca(int i,int j){
    int copia_de_i=i; i=j; j=copia_de_i;
}
void troca(int &i,int &j){
    int copia_de_i=i; i=j; j=copia_de_i;
}
int main(){
    int a =3,b=4;
    cout<<"a: "<<a<<" b: "<<b<<'\n';
    nao_troca(a,b);
    cout<<"a: "<<a<<" b: "<<b<<'\n';
    troca(a,b);
    cout<<"a: "<<a<<" b: "<<b<<'\n';

}