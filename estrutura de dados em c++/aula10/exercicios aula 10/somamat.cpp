using namespace std;
#include <iostream>
#include <new>

struct matriz
{
    double *v;
    int l;
    int c;

    matriz(int num_linhas, int num_colunas)
    {
        cout << "construtor";
        cout << endl;
        v = new double[num_linhas * num_colunas]();
        l = num_linhas;
        c = num_colunas;
    }

    ~matriz()
    {
        cout << "destrutor\n";

        delete[] v;
    }

    int num_linhas()
    {
        return l;
    }

    int num_colunas()
    {
        return c;
    }

    double &operator()(int linha, int coluna)
    {
        return v[linha * c + coluna];
    }
};

void imprimir(matriz &m)
{
    for (int l = 0; l < m.num_linhas(); ++l)
    {
        cout << "[";
        for (int c = 0; c < m.num_colunas(); ++c)
        {
            cout << " " << m(l, c);
        }
        cout << endl;
    }
}

matriz *somar(matriz &a, matriz &b)
{
    if (a.num_linhas() != b.num_linhas() || a.num_colunas() != b.num_colunas())
    {
        throw invalid_argument("as matrizes devem ter o mesmo tamanho");
    }

    matriz *resultado = new matriz(a.num_linhas(), a.num_colunas());

    for (int i = 0; i < a.num_linhas(); ++i)
    {
        for (int j = 0; j < a.num_colunas(); ++j)
        {
            (*resultado)(i, j) = a(i, j) + b(i, j);
        }
    }

    return resultado;
}

int main()
{
    try
    {
        matriz a(3, 3);
        matriz b(3, 3);
        cout << "matriz a\n";
        imprimir(a);
        cout << endl;
        cout << "matriz b\n";
        imprimir(b);

        matriz *resultado = somar(a, b);
        cout << "matriz resultado\n";

        imprimir(*resultado);

        cout<<"apos atribuicoes \n";
        cout<<endl;

        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                a(i,j)=1+i*3+j;
            }
        }

        cout<<"matriz a\n";
        imprimir(a);

        for(int x=0;x<3;++x){
            for(int z=0;z<3;++z){
                b(x,z)= x*3+z;
            }
        }
        cout<<endl;
        cout<<"matriz b\n";
        imprimir(b);
        cout<<endl;
        matriz* soma=somar(a,b);
        cout<<"matriz soma\n";
        imprimir(*soma);




        delete resultado;
    }
    catch (const bad_alloc &e)
    {
        cout << "erro,falta de memoria";
        return 1;
    }
}