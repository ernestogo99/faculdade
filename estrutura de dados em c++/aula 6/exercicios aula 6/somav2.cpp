#include <iostream>
#include <new>
using namespace std;

double *soma(double *v,double *w,int n){
    double *resultado=new double[n];// aloca um novo vetor para representar o resultado

    for(int i=0;i<n;++i){
        resultado[i]=v[i]+w[i];//  soma os elementos dos vetores
    }
    return resultado; // retorna o ponteiro para o novo vetor

}



int main() {
    try {
        int n = 0;
        unsigned long int tam;
        cout << "Digite o tamanho dos vetores: ";
        cin >> tam;
        double *v = new double[tam];
        double *w = new double[tam];

        // Preenche os vetores v e w
        for (int i = 0; i < tam; ++i) {
            cout << "Digite o elemento " << i  << " do vetor v: ";
            cin >> v[i];
            cout << "Digite o elemento " << i  << " do vetor w: ";
            cin >> w[i];
        }

        // Imprime os elementos dos vetores v e w
        cout << "Elementos do vetor v:" << endl;
        for (int i = 0; i < tam; ++i) {
            cout << v[i] << " ";
        }
        cout << endl;

        cout << "Elementos do vetor w:" << endl;
        for (int i = 0; i < tam; ++i) {
            cout << w[i] << " ";
        }
        cout << endl;

        double *resultado = soma(v, w, tam);

        // Imprime os elementos do vetor resultado
        cout << "Elementos do vetor resultado:" << endl;
        for (int i = 0; i < tam; ++i) {
            cout << resultado[i] << " ";
        }
        cout << endl;

        delete[] resultado;
    } catch (const bad_alloc &excecao) {
        cout << "Falha de alocação de memória\n";
        return 1;
    }

    return 0;
}
