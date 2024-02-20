#include <iostream>

struct noh {
    int valor;
    noh* esq;
    noh* dir;

    noh(int val) : valor(val), esq(nullptr), dir(nullptr) {}
};

struct Arvore {

    noh* raiz;

    // Função auxiliar para remover nós sem filhos em pós-ordem
    void removerSemFilhos(noh*& no) {
        if (no) {
            // Primeiro, remover nós nos filhos esquerdo e direito
            removerSemFilhos(no->esq);
            removerSemFilhos(no->dir);

            // Se o nó não tiver filhos, removê-lo
            if (!no->esq && !no->dir) {
                delete no;
                no = nullptr;
            }
        }
    }


    Arvore() : raiz(nullptr) {}

    // Função para remover nós sem filhos
    void removerNosSemFilhos() {
        removerSemFilhos(raiz);
    }

    // Outras funções da árvore, como inserir, imprimir, etc.
    // ...

    // Função auxiliar para imprimir a árvore em ordem
    void imprimirEmOrdem(noh* no) {
        if (no) {
            imprimirEmOrdem(no->esq);
            std::cout << no->valor << " ";
            imprimirEmOrdem(no->dir);
        }
    }

    // Função pública para imprimir a árvore em ordem
    void imprimirEmOrdem() {
        imprimirEmOrdem(raiz);
        std::cout << std::endl;
    }
};

void removerUmFilho(noh*& raiz) {
    if (raiz) {
        removerUmFilho(raiz->esq);
        removerUmFilho(raiz->dir);

        if ((raiz->esq == nullptr && raiz->dir != nullptr) || (raiz->esq != nullptr && raiz->dir == nullptr)) {
            // Nó tem exatamente um filho
            noh* temp = raiz;
            if (raiz->esq != nullptr) {
                raiz = raiz->esq;
            } else {
                raiz = raiz->dir;
            }
            delete temp;
        }
    }
}