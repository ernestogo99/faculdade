#include <iostream>
using namespace std;

struct conjunto{
    struct noh{
        int elemento;
        noh *dir;
        noh *esq;
    };
    noh *raiz;

    conjunto(){
        raiz=nullptr;
    }

    void imprimir(noh *raiz){
        if(raiz!=nullptr){
            imprimir(raiz->esq);
            cout<<raiz->elemento<<endl;
            imprimir(raiz->dir);
        }
    }

    void imp(){
        imprimir(raiz);
    }

    void inserir_recursivo(noh *&n,int valor){
        if(n==nullptr){
            n=new noh{valor,nullptr,nullptr};
        }
        if(n->elemento==valor) return;

        else if(valor<n->elemento){
            inserir_recursivo(n->esq,valor);
        }
        else{
            inserir_recursivo(n->dir,valor);
        }
    }

    void inserir(int valor){
        inserir_recursivo(raiz,valor);
    }

    int buscar(int valor){
        noh *p=raiz;
        while(p!=nullptr){
            if(valor==p->elemento){
                return p->elemento;
            }
            else if(valor<p->elemento){
                p=p->esq;
            }
            else{
                p=p->dir;
            }
        }
        return -1;
    }

     int tamanho(noh *raiz){
        if(raiz==nullptr){
            return 0;
        }
        else{
            return 1+tamanho(raiz->esq)+tamanho(raiz->dir);
        }   
    }

    int tam(){
        return tamanho(raiz);
    }

        int profundidade(noh *raiz, int valor, int nivel = 1) {
        if (raiz == nullptr) {
            // Se o nó não for encontrado, retorna -1 indicando que o valor não está na árvore
            return -1;
        }

        if (valor == raiz->elemento) {
            // Se encontrarmos o valor, retornamos o nível atual
            return nivel;
        } else if (valor < raiz->elemento) {
            // Se o valor é menor, procuramos na subárvore esquerda
            return profundidade(raiz->esq, valor, nivel + 1);
        } else {
            // Se o valor é maior, procuramos na subárvore direita
            return profundidade(raiz->dir, valor, nivel + 1);
        }
    }

    int profundidadee(int valor) {
        return profundidade(raiz, valor);
    }

    void imprimirIntervaloProfundidade(noh *raiz, int min, int max, int profundidadeAtual) {
    if (raiz != nullptr) {
        if (profundidadeAtual >= min && profundidadeAtual <= max) {
            cout << raiz->elemento << " ";
        }

        imprimirIntervaloProfundidade(raiz->esq, min, max, profundidadeAtual + 1);
        imprimirIntervaloProfundidade(raiz->dir, min, max, profundidadeAtual + 1);
    }
}

void imprimirIntervaloProfundidadeWrapper(noh *raiz, int min, int max) {
    imprimirIntervaloProfundidade(raiz, min, max, 1);
}

};

