#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    
    while(true){
        cout<<"digite um natural(ou negativo para parar)\n";
        int i;
        cin>>i;
        if(i<0) break;

        v.push_back(i);
    }
    cout<<"v: ";
    for(int i:v){
        cout<<' '<< i <<'\n';
    }
}