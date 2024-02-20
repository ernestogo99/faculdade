#include <iostream>
using namespace std;

int ler_nat(){
    cout<< "ler_nat: iniciando \n";
    cout<<"ler_nat: digite um natural: ";
    int i;
    cin>>i;
    if(cin.fail()){
        cout<<"ler_nat: vai jogar false\n";
        throw false; //joga um booleano
    }

    if(i<0){
        cout<<"ler_nat vai jogar i = "<< i <<'\n';
        throw i; // joga um inteiro
    }
    if(i==314){ // so para ver uma execao não ser tratada
        cout<<"ler_nat vai jogar 3.14\n";
        throw 3.14; //joga um double
    }

    cout<<"ler_nat vai retornar "<< i <<'\n';
    return i;
    
}

int meio(){
    cout<<"meio iniciando \n";
    while(true){
        try{
            int i=ler_nat();
            cout<<"meio recebeu ler_nat e vai retornar "<< i <<'\n';
            return i;
        }
        catch(int i){
            cout<<"meio: pegou exceçao int= "<< i <<"e vai ler novamente \n";
        }
    }

}

int main(){
    cout<<"main iniciando\n";
    try{
        int i=meio();

        cout<<"main recebeu de meio int= "<< i <<'\n';
    }
    catch(int i){
        cout<<"main pegou int= "<< i <<'\n';// nunca vai ocorre,meio ja pegou int i
    }
    catch(bool b){
        cout<<"main pegou bool= ";
        if(b) cout<<"true\n";
        else cout<<"false\n";
    }
}