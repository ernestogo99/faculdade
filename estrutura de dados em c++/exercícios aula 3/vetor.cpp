#include <iostream>
using namespace std;
int main(){
    cout<<"digite o tamanho do vetor "<<'\n';
    int tamanhov;
    cin>>tamanhov;
    double v[tamanhov];
    for(int i=0;i<tamanhov;++i){
        cout<<"digite os elementos de vetor "<<'\n';
        cin>>v[i];
    }
    for(int i=0;i<tamanhov;++i){
        cout<<v[i]<<" "<<'\n';
    }

}