#include <iostream>
using namespace std;
struct carro{
    string nome;
    string cor;
    int pot;
    int velmax;

};

int main(){
    carro car1;
    carro car2;

    car2.nome="corola";
    car2.cor="preto";
    car2.pot=400;
    car2.velmax=350;

    car1.nome="hilux";
    car1.cor="branco";
    car1.pot=450;
    car1.velmax=300;

    cout<<"nome do carro: "<<car1.nome<<endl;
    cout<<"cor: "<<car1.cor<<endl;
    cout<<"potencia: "<<car1.pot<<endl;
    cout<<"velocidade maxima: "<<car1.velmax<<endl;
    
    cout<<endl;
    
    cout<<"nome do carro: "<<car2.nome<<endl;
    cout<<"cor: "<<car2.cor<<endl;
    cout<<"potencia: "<<car2.pot<<endl;
    cout<<"velocidade maxima: "<<car2.velmax<<endl;
    
}