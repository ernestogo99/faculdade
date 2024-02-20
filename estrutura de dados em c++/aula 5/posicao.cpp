#include <iostream>
using namespace std;

int procurar(double *v, int n, double x) {
    for (int i = 0; i < n; ++i) {
        if (v[i]==x) {  
            return i;
        }
    }
    return -1;
}
// quando ,numa expressão , o nome de um vetor é usado num  contexto
// onde é esperado um ponteiro, então esse nome nessa expressão é 
// convertido para um ponteiro apontando para o 1 elemento do vetor


int main() {
    double v[5] = {0, 10, 20, 30, 40};
    cout << "A posiçao de 20 é " << procurar(v, 5, 20) << '\n';
}
