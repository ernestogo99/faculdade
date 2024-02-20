#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<float> v(7);
    
    // adicionar os valores no vetor
    for(int i=0;i<v.size();++i){
        cout<<"digite um valor para adicionar ao vetor ";
        cin>>v[i];
        cout<<"v["<< i << "]: "<< v[i] <<'\n';


    }
    // inverter o vetor
     for (int i = 0; i < v.size() / 2; ++i) {
        double temp = v[i];
        v[i] = v[v.size() - 1 - i];
        v[v.size() - 1 - i] = temp;
    
    }
    cout<<"vetor invertido ";
    cout<<'\n';
    for(int i =0;i<v.size();++i){
        cout<<v[i]<<" ";
    }
    

} 