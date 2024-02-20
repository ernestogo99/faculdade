#include <iostream>
using namespace std;
// Função para verificar se um elemento está presente no vetor
bool estaNoConjunto(int elemento, int* conjunto, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (conjunto[i] == elemento) {
            return true; // O elemento está no conjunto
        }
    }
    return false; // O elemento não está no conjunto
}

// Função para imprimir o conjunto atual
void imprimirConjunto(int* conjunto, int tamanho) {
    cout << "Conjunto atual: ";
    for (int i = 0; i < tamanho; i++) {
        cout << conjunto[i] << " ";
    }
    cout << std::endl;
}

int main() {
    int tamanhoMaximo = 10; // Tamanho inicial do vetor (pode aumentar dinamicamente)
    int* conjunto = new int[tamanhoMaximo]; // Vetor para armazenar os elementos do conjunto
    int tamanho = 0; // Tamanho atual do conjunto

    while (true) {
        imprimirConjunto(conjunto, tamanho);

        cout << "Escolha uma operacao:" << endl;
        cout << "1. Inserir elemento" << endl;
        cout << "2. Remover elemento" << endl;
        cout << "3. Encerrar o programa" << endl;
        int escolha;
        cin >> escolha;

        if (escolha == 1) {
            cout << "Digite o elemento a ser inserido: ";
            int elemento;
            cin >> elemento;

            if (tamanho == tamanhoMaximo) {
                // O vetor está cheio, alocar um novo vetor maior
                int novoTamanho = tamanhoMaximo * 2;
                int* novoConjunto = new int[novoTamanho];

                for (int i = 0; i < tamanho; i++) {
                    novoConjunto[i] = conjunto[i];
                }

                delete[] conjunto;
                conjunto = novoConjunto;
                tamanhoMaximo = novoTamanho;
            }

            if (!estaNoConjunto(elemento, conjunto, tamanho)) {
                // Inserir elemento no conjunto
                conjunto[tamanho] = elemento;
                tamanho++;
                cout << "Elemento inserido com sucesso!" << endl;
            } else {
                cout << "Elemento ja presente no conjunto. Insercao falhou." << endl;
            }
        } else if (escolha == 2) {
            cout << "Digite o elemento a ser removido: ";
            int elemento;
            cin >> elemento;

            int indiceParaRemover = -1;

            for (int i = 0; i < tamanho; i++) {
                if (conjunto[i] == elemento) {
                    indiceParaRemover = i;
                    break;
                }
            }

            if (indiceParaRemover != -1) {
                // Remover elemento do conjunto
                for (int i = indiceParaRemover; i < tamanho - 1; i++) {
                    conjunto[i] = conjunto[i + 1];
                }
                tamanho--;
                cout << "Elemento removido com sucesso!" << endl;
            } else {
                cout << "Elemento nao encontrado no conjunto. Remocao falhou." << endl;
            }
        } else if (escolha == 3) {
            // Encerrar o programa
            break;
        } else {
            cout << "Escolha invalida. Tente novamente." << endl;
        }
    }

    // Liberar a memória alocada para o vetor
    delete[] conjunto;

    return 0;
}
