#include <iostream>
#include <new>
using namespace std;

int main() {
    try {
        int n = 0, tam = 1;
        double *v = new double[tam];

        while (true) {
            cout << "Digite um número natural (<0 para encerrar): ";
            int i;
            cin >> i;

            if (i < 0)
                break;

            if (n == tam) {
                int novo_tam = tam + 1;
                double *w = new double[novo_tam];

                for (int j = 0; j < n; ++j)
                    w[j] = v[j];

                delete[] v;
                v = w;
                tam = novo_tam;
            }
            
            v[n] = i;
            ++n;
        }

        cout << "v:";
        for (int j = 0; j < n; ++j)
            cout << ' ' << v[j];
        cout << '\n';
        delete[] v;
    }
    catch (const bad_alloc &excecao) {
        cout << "Falha de alocação de memória\n";
        return 1;
    }

    return 0; // Adicionei um retorno 0 para indicar que o programa terminou com sucesso.
}
