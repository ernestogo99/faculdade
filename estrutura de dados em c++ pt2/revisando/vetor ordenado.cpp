#include <iostream>
#include <new>
using namespace std;

struct vet
{
    double *v;
    int tam;
    int n;

    vet()
    {
        tam = 1;
        v = new double[tam];
        n = 0;
    }

    // Busca binária, o vetor deve estar ordenado para funcionar
    int buscar(double x)
    {
        int ini = 0;
        int fim = tam - 1;

        while (ini <= fim)
        {
            int meio = ini + (fim - ini) / 2;

            if (x == v[meio])
                return meio;
            if (x < v[meio])
                fim = meio - 1;
            else
                ini = meio + 1;
        }

        return -1; // Elemento não encontrado
    }
    void ordenar()
    {
        int aux = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = 0; j < n - 1 - i; ++j)
            {
                if (v[j] > v[j + 1])
                {
                    aux = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = aux;
                }
            }
        }
    }

    void inserir(int elemento)
    {
        if (n == tam)
        {
            tam = tam * 2;
            double *w = new double[tam];
            for (int i = 0; i < n; ++i)
            {
                w[i] = v[i];
            }
            delete[] v;
            v = w;
        }
        v[n] = elemento;
        n++;
    }

    ~vet()
    {
        delete[] v;
    }

    void imprimir()
    {
        for (int i = 0; i < n; ++i)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    int encontrarPosicaoParaInserir(double x)
{
    int ini = 0;
    int fim = tam-1;

    while (ini < fim)
    {
        int meio = (ini + fim) / 2;

        if (x <= v[meio])
        {
            fim = meio;
        }
        else
        {
            ini = meio + 1;
        }
    }

    return ini;
}

    void remover(){
        if(n==0){
            cout<<"impossivel remover,fila vazia ";
            return;
        }
        n--;
    }


};

int main()
{
    vet v;
    v.inserir(10);
    v.inserir(5);
    v.inserir(3);
    v.inserir(8);
    v.ordenar();
    v.remover();
    v.imprimir();
    cout << endl;
    cout << "digite um numero para buscar ";
    double num;
    cin >> num;
    int indice = v.buscar(num);
    if (indice != -1)
    {
        cout << "o numero foi encontrado na posicao " << indice << '\n';
    }
    else
    {
        cout << "numero nao encontrado\n";
        
    }
    cout<<"dite um numero para ver em que posicao ele iria entrar \n";
    double nu;
    cin>>nu;
   int pos= v.encontrarPosicaoParaInserir(nu);
   cout<<"o numero "<<nu<<" seria inserido na posicao "<<pos<<'\n';

    return 0;
}
