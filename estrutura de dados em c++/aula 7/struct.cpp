#include <iostream>
using namespace std;

struct registro{int id; char prim_letra_nome; };

int main(){
    registro r{10,'p'};

    cout<<"r.id:              "<<r.id<<'\n';
    cout<<"r.prim_letra_nome: "<<r.prim_letra_nome<<'\n';         
}
