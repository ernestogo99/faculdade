#include <new>
#include <iostream>
using namespace std;

int main(){
    try{
        int tam=1;
        double *v=new double[tam];
        int n=0;

        while(true){
            cout<<"digte o proximo elemento(negativo para sair): ";
            double num;
            cin>>num;
            if(num<0) break;

            if(n==tam){
                cout<<"nova alocacao \n";
                int ntam=2*tam;
                double *w=new double[ntam];
                for(int i=0;i<n;++i) w[i]=v[i];

                delete []v;  v=w; tam=ntam;
                }
                v[n]=num; ++n;

            }
            cout<<"elementos digitados: ";
            for(int i=0;i<n;++i){
                cout<<' '<<v[i];
            }
            cout<<'\n';
            delete[]v;
        }
        catch(const bad_alloc &e){
            cout<<"erro, falta de memoria \n"; return 1;

        }
}