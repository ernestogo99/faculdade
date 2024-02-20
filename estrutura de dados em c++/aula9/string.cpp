#include <iostream>
#include <string>
using namespace std;

int main(){
    cout<<"digite o texto, terminando com uma linha vazia: \n";

    string texto;

    while(true){
        string linha; getline(cin,linha);
        if(linha.length()==0) break;

        texto= texto + linha + '\n';
    }

    cout<<"o texto digitado foi:\n";
    cout<<"------------------\n";
    cout<<texto;
    cout<<"------------------\n";
}