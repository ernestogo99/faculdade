#include <iostream>
using namespace std;
  // int n; cout<< "n: "; cin>>n; double v[n];
    // "variable length array" não é c++ válido

    // contexpr int tam=7; doublev[tam];
    // int *pi =new int;
    // correto, apenas não inicializa
    // testar alocação
        // *pi=3
    // double *v= new double[5]
    // correto, apenas não inicializa

int main() {
    int *pi = new int{5}; // Inicializa com o valor 5

    cout << "*pi: " << *pi << '\n';
    delete pi;

    double *v = new double[5]{1,2,3}; // Inicializa todos os elementos com zero

    for (int i = 0; i < 5; ++i) {
        cout << "v[" << i << "]: " << v[i] << '\n';
    }
    delete[] v;
}
