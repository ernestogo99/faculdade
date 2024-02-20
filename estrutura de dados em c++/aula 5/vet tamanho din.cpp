#include <iostream>
using namespace std;

int main() {
    int n;

    do {
        cout << "n: ";
        cin >> n;
    } while (n <= 0);

    double *v = new double[n];

    // Lê os valores para o array v
    for (int i = 0; i < n; ++i) {
        cout << "v[" << i << "]: ";
        cin >> v[i];
    }

    // Imprime os valores do array v
    for (int i = 0; i < n; i++) {
        cout << "v[" << i << "]: " << v[i] << '\n';
    }

    delete[] v;
}
