#include <iostream>
using namespace std;
double soma(double *p,int n){
    double s=0;
    for(int i=0;i<n;i++){
         s+=p[i];
    }
    return s;
}
int main(){
    double v[4]={1.1,2.2,3.3,4.4};
    cout<<"a soma de v e "<<soma(&v[0],4)<<'\n';
}