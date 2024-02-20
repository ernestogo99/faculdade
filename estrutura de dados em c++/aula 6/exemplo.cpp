#include <iostream>
using namespace std;

int main(){
    cout<<"digite um inteiro ";
    int i;
    cin>>i;
    if(cin.fail()){
        cout<<"erro na leitura \n"; 
        return 1;

    }
    cout<<"lido "<< i <<'\n';
}