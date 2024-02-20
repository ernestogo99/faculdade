#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string terminador="FIM";
    vector<string> texto;

    while(true){
        string palavra; cin>>palavra;

        if(palavra==terminador) break;

        texto.push_back(palavra);
    }

    cout<<"as palavras digitadas foram: ";
    for(int i=0;i<(int)texto.size();++i){
        cout<<" "<<texto[i];
    }
    cout<<endl;
}