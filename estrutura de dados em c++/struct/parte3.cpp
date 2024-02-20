#include <iostream>
#include <new>
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

    carro *carros=new carro[5];
    carro car1,car2,car3,car4,car5;
    
    carros[0]=car1; carros[1]=car2; carros[2]=car3; carros[3]=car4; carros[4]=car5;

    carros[0].inserir("tornado","vermelho",450,350);
    carros[1].inserir("hilux","azul",450,350);
    carros[2].inserir("civic","roxo",450,350);
    carros[3].inserir("corola","branco",450,350);
    carros[4].inserir("fusca","preto",450,350);

    for(int i=0;i<5;++i){
        carros[i].mostra();
        cout<<endl;
    }

    


    

   

    
    
    
}