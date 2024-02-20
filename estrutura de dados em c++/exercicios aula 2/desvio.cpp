#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    vector<float>v(5);
    int soma=0;
    
    for(int i=0;i<v.size();++i){
        cout<<"digite um valor para adicionar ao vetor ";
        cin>>v[i];
        cout<<"v["<< i << "]: "<< v[i] <<'\n';
        soma+=v[i];

    }
    float media=soma/v.size();
    cout<<"a soma dos valores dos vetores e: "<<soma<<'\n';
    cout<<"a media dos valores dos vetores e: "<<media<<'\n';
    
    for(int i=0;i<v.size();i++){
        v[i]-=media;
    }
    //vetor apos subtração
    double s2=0;
    for(int i=0;i<v.size();i++){
        s2+=abs(v[i]);
    }
    cout<<s2<<'\n';
    double dm=s2/v.size();
    cout<<"o desvio medio absoluto e: "<<dm<<'\n';

}