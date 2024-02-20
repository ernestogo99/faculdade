// Definição:
//se p é um ponteiro e i é um inteiro
// então p[i] é igual a *p(p+i)

#include <iostream>
using namespace std;
int main(){
    int v[5]={0,10,20,30,40};
    int *p;
    p=&v[0];

    *(p+1)=-10; p[2]=-20; p[3]=-30; p[4]=-40;
    for(int i=0;i<5;i++){
        cout<<"v[" <<i<<"]: "<<v[i]<<'\n';
    }
}