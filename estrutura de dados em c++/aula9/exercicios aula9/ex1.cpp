#include <iostream>
using namespace std;

int tamanho(const char *s){
    int i=0;
    while(s[i]!=0) ++i;
    return i;
}

int main(){
    const char *texto="o sol";

    cout<<"o tamanho de [ "<<texto<<"] e "<<tamanho(texto)<<endl;
}