#include <iostream>
#include <string>

using namespace std;

class pilha {
    struct noh {
        string elem;
        noh *prox;
    };
    noh *topo;

public:
    pilha() {
        topo = nullptr;
    }

    ~pilha() {
        while (topo != nullptr) {
            noh *atual = topo;
            topo = topo->prox;
            delete atual;
        }
    }

    void empilhar(string elem) {
        noh *p = new noh;
        p->prox = topo;
        p->elem = elem;
        topo = p;
    }

    string consultar_topo() {
        return topo->elem;
    }

    string desempilhar() {
        if (topo == nullptr) {
            throw runtime_error("Pilha vazia");
        }
        string elem = topo->elem;
        noh *p = topo;
        topo = topo->prox;
        delete p;
        return elem;
    }

    bool vazia() {
        return topo == nullptr;
    }
};

int main() {
    try {
        pilha p;
        p.empilhar(string{"primeiro"});
        p.empilhar(string{"segundo"});
        p.empilhar(string{"terceiro"});

        cout << "1 desempilhar: " << p.desempilhar() << endl;
        cout << "2 desempilhar: " << p.desempilhar() << endl;

        p.empilhar(string{"quarto"});
        while (!p.vazia()) {
            cout << "topo atual: " << p.consultar_topo() << '\n';

            cout << "desempilhando: \n";
            p.desempilhar();
        }

        p.empilhar(string{"quinto"});

    } catch (const bad_alloc &e) {
        cout << "Falha de alocação de memória \n";
        return 1;
    } catch (const exception &e) {
        cout << "Exceção: " << e.what() << endl;
        return 1;
    }

    return 0;
}
