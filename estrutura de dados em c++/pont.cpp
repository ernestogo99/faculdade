//definição de aritmética básica de ponteiros:
//se v é um vetor de n elementos
// e p é um ponteiro que aponta para um elemento v[i]
// e se j é um ponteiro tal que 0<= i+j<=n
// então p+j denota um ponteiro apontando para v[i+j]
// além disso, p-j é o mesmo que p+(-j).

#include <iostream>
using namespace std;

int main(){
    int v[10]={0,10,20,30,40,50,60,70,80,90};
    int *p;
    p=&v[5];
    cout<<"*(p+2): "<<*(p+2)<<'\n';
    cout<<"*(p-2): "<<*(p-2)<<'\n';
    
}

