#include <iostream>
#include <vector>
using namespace std;

int main(){
    float v[5]={0,1,2,3,4};
    int i;
    for (i=0;i<5;++i){
        cout<<"v["<< i << "]: "<< v[i] <<'\n';
    }
    for(i=4;i>=0;--i){
        cout<<"v["<< i << "]:" << v[i]<<'\n';
    }
}