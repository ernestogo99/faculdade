#include <iostream>
using namespace std;

class conjunto{
    struct noh{
        double elem;
        noh *esq,*dir;
    };

    noh* raiz;

    void imprimir_subarvore(noh *n){
        if(n!=nullptr){
            imprimir_subarvore(n->esq);
            cout<< n->elem<<endl;
            imprimir_subarvore(n->dir);
        }
    }
    public:
    conjunto(){
        raiz=nullptr;
    }

    void inserir(double x){
        // é a primeira insercao?
        if(raiz==nullptr){
            raiz=new noh{x,nullptr,nullptr};
            //raiz->elem=x;
            //raiz->dir=nullptr;
            //raiz->esq=nullptr;
            return;
        }
        noh *n=raiz;
        while(true){
            if(x==n->elem) return;

            if(x<n->elem){
                if(n->esq==nullptr){
                    n->esq=new noh{x,nullptr,nullptr};
                    return;
                }
                else{
                    n=n->esq;
                }
            }
            else{
                if(n->dir==nullptr){
                    n->dir=new noh{x,nullptr,nullptr};
                    return;
                }
                else{
                    n=n->dir;
                }
            }
        }
    }

    bool pertence(double x){
        noh *n=raiz;
        while(n!=nullptr){
            if(x==n->elem)return true;
            if(x<n->elem) n=n->esq;
            else          n=n->dir;
        }
        return false;
    }

    void remover(double x){
        //encontrar x na arvore
        noh *n=raiz; noh *pai=nullptr;
        while(n!=nullptr){
            if(x==n->elem)break;
            pai=n;
            if(x<n->elem)n=n->esq;
            else         n=n->dir;
        }

        if(n==nullptr)return;
        // no maximo 1 filho
        if(n->esq==nullptr or n->dir==nullptr){
            noh *filho; //filho possivelmente nao nulo
            if(n->esq==nullptr)filho=n->dir;
            else                filho=n->esq;

            // retirar n da arvore
            if(pai==nullptr){
                raiz=filho;
            }
            else if(pai->elem<n->elem){
                pai->dir=filho;
            }
            else{
                pai->esq=filho;
            }
        }
        else{// n tem 2 filhos
            // encontrar predecessor e retira-lo da arvore
            noh *pai_pred=n;
            noh *pred=n->esq;
            while(pred->dir!=nullptr){
                pai_pred=pred;
                pred=pred->dir;
            }

            //retirar o predecessor da arvore
            if(pred==pai_pred->esq){
                pai_pred->esq=pred->esq;
            }
            else{
                pai_pred->dir=pred->esq;
            }

            //substituir n pelo predecessor

            pred->esq=n->esq;
            pred->dir=n->dir;

            if(pai==nullptr){
                raiz=pred;
            }
            else if(pai->elem<n->elem){
                pai->dir=pred;
            }
            else{
                pai->esq=pred;
            }
        }
        delete n;
    }

    void imprimir_crescente(){
        imprimir_subarvore(raiz);
    }

    int tamanho(noh *raiz){
        if(raiz==nullptr){
            return 0;
        }
        else{
            return 1+tamanho(raiz->esq)+tamanho(raiz->dir);
        }   
    }
};

int main() {
    conjunto conj;

    // Inserir elementos
    conj.inserir(10);
    conj.inserir(5);
    conj.inserir(15);
    conj.inserir(2);
    conj.inserir(7);
    conj.inserir(12);
    conj.inserir(20);

    // Imprimir a árvore
    cout << "Árvore atual:\n";
    conj.imprimir_crescente();
    cout << "\n";

    // Verificar a pertinência de elementos
    cout << "Verificar pertinência:\n";
    cout << "Pertence 7? " << (conj.pertence(7) ? "Sim" : "Não") << "\n";
    cout << "Pertence 8? " << (conj.pertence(8) ? "Sim" : "Não") << "\n";
    cout << "\n";

    // Remover elementos
    cout << "Remover elementos:\n";
    cout << "Remover 5\n";
    conj.remover(5);
    conj.imprimir_crescente();
    cout << "\n";

    cout << "Remover 15\n";
    conj.remover(15);
    conj.imprimir_crescente();
    cout << "\n";

    cout << "Remover 10\n";
    conj.remover(10);
    conj.imprimir_crescente();
    cout << "\n";

    return 0;
}