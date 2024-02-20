#include <iostream>
#include <new>
using namespace std;

char *concatenar(const char *r, const char *s){
    int tamr=0;
    while(r[tamr]!= 0){
        ++tamr;
    }

    int tams=0;
    while(s[tams]!=0){
        ++tams;
    }
     char novotam=tams+tamr+1;
    char *nova=new char[novotam];

    
    for(int i=0;i<tamr;++i){
        nova[i]=r[i];
    }

    for(int j=0;j<tams;++j){
        nova[tamr+j]=s[j];
    }
     

    return nova;
}

int main(){
    const char* st1= "oi ";
    const char * st2="sumido ";

    char *resultado=concatenar(st1,st2);

    cout<<resultado<<endl;
    delete[] resultado;

}