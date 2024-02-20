#include <iostream>
#include <new>
using namespace std;

struct FilaDeDoisPontos {
    int tam_vet, *v, esquerda, direita;

    FilaDeDoisPontos(int tamanho) {
        tam_vet = tamanho;
        v = new int[tam_vet];
        esquerda = -1;
        direita = -1;
    }

    bool estaVazia() {
        return (esquerda == -1 && direita == -1);
    }

    void inserirEsquerda(int valor) {
        if (esquerda == -1) {
            esquerda = direita = 0;
            v[esquerda] = valor;
        } else if (esquerda > 0) {
            v[--esquerda] = valor;
        } else {
            esquerda = tam_vet - 1;
            v[esquerda] = valor;
        }
    }

    void inserirDireita(int valor) {
        if (direita == -1) {
            esquerda = direita = 0;
            v[direita] = valor;
        } else if (direita < tam_vet - 1) {
            v[++direita] = valor;
        } else {
            direita = 0;
            v[direita] = valor;
        }
    }

    int removerEsquerda() {
        if (estaVazia()) {
            cout << "Erro: Fila de dois pontos vazia" << endl;
            return -1; // Retornando um valor de erro
        }

        int valor = v[esquerda];

        if (esquerda == direita) {
            esquerda = direita = -1;
        } else if (esquerda == tam_vet - 1) {
            esquerda = 0;
        } else {
            esquerda++;
        }

        return valor;
    }

    int removerDireita() {
        if (estaVazia()) {
            cout << "Erro: Fila de dois pontos vazia" << endl;
            return -1; // Retornando um valor de erro
        }

        int valor = v[direita];

        if (esquerda == direita) {
            esquerda = direita = -1;
        } else if (direita == 0) {
            direita = tam_vet - 1;
        } else {
            direita--;
        }

        return valor;
    }
};

int main() {
    FilaDeDoisPontos fila(10); // Tamanho máximo da fila é 10

    // Inserções
    fila.inserirDireita(4);
    fila.inserirEsquerda(7);

    // Remoções
    int valorRemovido = fila.removerDireita();
    cout << "Removido da direita: " << valorRemovido << endl;
    valorRemovido = fila.removerEsquerda();
    cout << "Removido da esquerda: " << valorRemovido << endl;

    // Mais inserções
    fila.inserirEsquerda(2);
    fila.inserirDireita(10);

    // Mais remoções
    valorRemovido = fila.removerDireita();
    cout << "Removido da direita: " << valorRemovido << endl;
    valorRemovido = fila.removerEsquerda();
    cout << "Removido da esquerda: " << valorRemovido << endl;

    return 0;
}
