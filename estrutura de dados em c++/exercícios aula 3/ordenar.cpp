#include <iostream>
using namespace std;

void ordenar(double *v, int n) {
    for (int passo = 0; passo < n-1 ; passo++) {
        for (int i = 0; i < n -1 - passo; i++) {
            if (v[i] > v[i + 1]) {
                // Troca os elementos v[i] e v[i + 1]
                double temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
            }
        }
    }
}
int main(){
    int tamanhov=5;
   double v[tamanhov];
   for(int i =0;i<tamanhov;++i){
    cout<<"digite  elementos para o vetor"<<'\n';
    cin>>v[i];
   }
   ordenar(v,tamanhov);
   cout<<"vetor ordenado"<<'\n';
   for(int i=0;i<tamanhov;++i){
    cout<<v[i]<<" "<<'\n';
   }

}