#include <iostream>
#include <new>
using namespace std;

struct matriz{
    double *v;
    int l;
    int c;

    matriz(int num_linhas,int num_colunas){
        cout<<"construtor";
        v=new double[num_linhas*num_colunas];
        l=num_linhas;
        c=num_colunas;
    }

    ~matriz(){
        cout<<"destrutor";
        delete[]v;
    }

    int num_linhas(){
        return l;
    }

    int num_colunas(){
        return c;
    }

    double &operator()(int linha,int coluna){
        return v[linha*c+coluna];
    }


};

void imprimir(matriz &m){
    for(int l=0;l<m.num_linhas();++l){
        cout<<"[";
        for(int c=0;c<m.num_colunas();++c){
            cout<<" "<<m(l,c);
        }
        cout<<endl;
    }

}

matriz* somar(matriz &a, matriz &b) {
    // Verifica se as dimensões das matrizes são iguais
    if (a.num_linhas() != b.num_linhas() || a.num_colunas() != b.num_colunas()) {
        throw std::invalid_argument("As matrizes devem ter as mesmas dimensões para somar.");
    }

    // Cria uma nova matriz para armazenar a soma
    matriz* resultado = new matriz(a.num_linhas(), a.num_colunas());

    // Soma os elementos das matrizes
    for (int i = 0; i < a.num_linhas(); ++i) {
        for (int j = 0; j < a.num_colunas(); ++j) {
            (*resultado)(i, j) = a(i, j) + b(i, j);
        }
    }

    return resultado;
}

int main() {
    try {
        matriz a(2, 2);
        matriz b(2, 2);

        // Inicialize a e b com valores

        imprimir(a);
        imprimir(b);

        matriz* resultado = somar(a, b);
        imprimir(*resultado);

        // Não se esqueça de liberar a memória alocada para o resultado
        delete resultado;
    } catch (const std::invalid_argument &ex) {
        std::cout << "Erro: " << ex.what() << std::endl;
    }

    return 0;
}
