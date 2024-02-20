#include <iostream>
#include <stack>
#include <string>

using namespace std;

double ler_expressao(){
    stack<string>  pilha;
    //pop : faz a retirada de elementos
    //top :retorna o elemento que esta no topo
    while(true){
        string palavra; cin>>palavra;

        if(palavra=="FIM") break;

        if(palavra !="(" and palavra !=")"){
            pilha.push(palavra); // empilhar
        }
        else{
            if(palavra==")"){
                double dir= stod(pilha.top()); pilha.pop();
                string op=pilha.top();  pilha.pop();
                double esq=stod(pilha.top()); pilha.pop();

                double res;
                if(op=="+") res=esq+dir;
                else if(op=="-")res=esq-dir;
                else if(op=="*")res=esq*dir;
                else res=esq/dir;
                pilha.push(to_string(res));
            }
        }

    }
    return stod(pilha.top());
}
int main(){
    cout<<"digite a expressao ";
    double resultado=ler_expressao();
    cout<<"\nresultado: "<<resultado<<'\n';
}