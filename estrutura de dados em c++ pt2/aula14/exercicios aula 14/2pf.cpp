#include <iostream>
#include <string>
#include <new>
using namespace std;

class pilha {
    int tam; // tamanho do vetor
    string *v; // ponteiro para o vetor
    int n;  // numero de elementos de v
public:
    pilha() {
        tam = 1;
        v = new string[tam];
        n = 0;
    }

    void empilhar(string s) {
        if (n == tam) {
            tam = 2 * tam;
            string *w = new string[tam];
            for (int i = 0; i < n; ++i) {
                w[i] = v[i];
            }
            delete[] v;
            v = w;
        }
        v[n] = s;
        ++n;
    }

    bool estavazia() {
        return (n == 0);
    }

    void desempilhar() {
        if (n == 0) {
            cout << "Erro: pilha vazia" << endl;
            return;
        }
        --n;

        if (n > 0 && n <= tam / 4) {
            tam = tam / 2;
            string *w = new string[tam];
            for (int i = 0; i < n; ++i) {
                w[i] = v[i];
            }
            delete[] v;
            v = w;
        }
    }

    int tamanho() {
        return n;
    }

    string topo() {
        if (n == 0) {
            cout << "Erro: pilha vazia" << endl;
            return "";
        }
        return v[n - 1];
    }

    ~pilha() {
        delete[] v;
    }
};

class fila {
    pilha entrada; // Pilha para a entrada (enqueue)
    pilha saida;   // Pilha para a saída (dequeue)

public:
    void enfileirar(string s) {
        entrada.empilhar(s);
    }

  void desenfileirar() {
    if (saida.estavazia()) {
        while (!entrada.estavazia()) {
            string elemento = entrada.topo();
            entrada.desempilhar();
            saida.empilhar(elemento);
        }
    }
    saida.desempilhar();
}

    bool vazia() {
        return entrada.estavazia() && saida.estavazia();
    }

   string top() {
    if (saida.estavazia()) {
        while (!entrada.estavazia()) {
            string elemento = entrada.topo();
            entrada.desempilhar();
            saida.empilhar(elemento);
        }
    }
    return saida.topo();
}
};

int main() {
    fila minhaFila;

    minhaFila.enfileirar("A");
    minhaFila.enfileirar("B");
    minhaFila.enfileirar("C");

    cout << "Elementos da fila: ";
    while (!minhaFila.vazia()) {
        cout << minhaFila.top();
        minhaFila.desenfileirar();
        if (!minhaFila.vazia()) cout << " ";
    }

    cout << endl;

    return 0;
}

