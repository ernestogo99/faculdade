#include <iostream>
using namespace std;

void inverter(char *s){
    int tam=0;
    while(s[tam]!=0)tam++;

    for(int i=tam-1;i>=0;--i){
        cout<<s[i];
    }
}

int main(){
    char a[]="oi";
    
    inverter("hilux");
    cout<<endl;
    inverter("oi");
    cout<<endl;
    inverter(" ");
}