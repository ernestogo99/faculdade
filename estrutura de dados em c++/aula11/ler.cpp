#include <iostream>
#include <string>
using namespace std;

double ler_expressao(){
    string palavra;
    cin>>palavra;
    if(palavra[0]=='('){
        double esq=ler_expressao();
        string op;
        cin>>op;

        double dir=ler_expressao();
        string parf;
        cin>>parf;

        if(op[0] =='+') return esq+dir;
        else if(op[0]=='-')return esq-dir;
        else if(op[0]=='*')return esq*dir;
        else return esq/dir;

    }
    else return stod(palavra);
}
int main(){
    cout<<"digite a expressao ";
    double resultado=ler_expressao();
    cout<<"resultado "<<resultado<<'\n';
}