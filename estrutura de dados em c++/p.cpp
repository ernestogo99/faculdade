#include <iostream>
using namespace std;
int main(){
    int i =3;
    int *p; //não sabemos para onde p aponta

    p=&i;
    cout<<"*p: "<<*p<<'\n'; //p=3
    *p=4;
    cout<<"i: "<<i<<'\n'; //i=4
    cout<<"o endereço de i e: "<<p<<'\n';
    int j=5; p=&j;
    cout<<"*p: "<<*p<<'\n';
    *p=6;
    cout<<"j: "<<j<<" i: "<<i<<'\n';
    cout<<"o endereço de j e: "<<p<<'\n';
    double d=3.14; double *q=&d;
    cout<<"*q: "<<*q<<'\n';
    cout<<"o endereço de d e: "<<q<<'\n';


}