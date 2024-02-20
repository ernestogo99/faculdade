#include  <iostream>
using namespace std;

int main(){
    int i =3;

    int &ri=i; cout<<"i: "<<i<<" ri: "<<ri<<'\n';
    ri=4;      cout<<"i: "<<i<<" ri: "<<ri<<'\n';
    int &r2=ri; cout<<"i: "<<i<<" ri: "<<ri<<'\n';
    r2=5; cout<<"i: "<<i<<" ri: "<<ri<<'\n';
    i=0;

    cout<<"i: "<<i<<" ri: "<<ri<<" r2: "<<r2<<'\n';


}