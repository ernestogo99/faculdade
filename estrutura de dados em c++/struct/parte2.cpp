#include <iostream>
using namespace std;
struct carro{
    string nome;
    string cor;
    int pot;
    int velmax;
    int vel;

    void inserir(string stnome,string stcor,int stpot,int stvelmax){
        nome=stnome;
        cor=stcor;
        pot=stpot;
        velmax=stvelmax;
        vel=0;
    }
    
    void mostra(){
        cout<<"nome: "<<nome<<endl;
        cout<<"cor: "<<cor<<endl;
        cout<<"pot: "<<pot<<endl;
        cout<<"vel atual: "<<vel<<endl;
        cout<<"velmax: "<<velmax<<endl;
    }

    void mudavel(int mv){
        vel=mv;
       if(vel>velmax){
        vel=velmax;
       }

       if(vel<0){
        vel=0;
       }

    }

    

};

int main(){
    carro car1;
    carro car2;

    car1.inserir("hilux","branco",450,300);
    car2.inserir("luxo","preto",300,300);

    car1.mostra();

    car1.mudavel(400);
    cout<<endl;
    car1.mostra();


    

   

    
    
    
}