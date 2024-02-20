#include <iostream>
#include <new>
using namespace std;

double *soma(double *v, double *w, int n)
{
    double *resultado = new double[n]; // aloca um novo vetor para representar o resultado

    for (int i = 0; i < n; ++i)
    {
        resultado[i] = v[i] + w[i]; //  soma os elementos dos vetores
    }
    return resultado; // retorna o ponteiro para o novo vetor
}

int main()
{
    try
    {
        int n = 0;
        unsigned long int tam;
        cout << "digite o tamanho dos vetores: ";
        cin >> tam;
        double *v = new double[tam];
        double *w = new double[tam];
        for (int i = 0; i < tam; ++i)
        {
            cout << "digite os elementos do vetor v: ";
            cin >> v[i];
            cout << "digite os elementos do vetor w: ";
            cin >> w[i];
        }
        cout << "elementos de v \n";
        for (int i = 0; i < tam; ++i)
        {

            cout << v[i] << " ";
        }
        cout << '\n';

        cout << "elementos de w \n";
        for (int i = 0; i < tam; ++i)
        {

            cout << w[i] << " ";
        }

        cout << "\n";

        double *resultado = soma(v, w, tam);

        cout << "elementos do vetor resultado \n";

        for (int i = 0; i < tam; ++i)
        {

            cout << resultado[i] << " ";
        }
        cout << "\n";

        delete[] resultado;
    }
    catch (const bad_alloc &excecao)
    {
        cout << "Falha de alocação de memória\n";
        return 1;
    }
}