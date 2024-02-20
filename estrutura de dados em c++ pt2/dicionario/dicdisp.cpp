#include <iostream>
#include<new>
#include <string>
#include <vector>
using namespace std;

class diciotd{// dicionario via tabela de dispersao
//chaves:matricula , valores:nome

    struct noh{
        int chave;//numero da matricula
        string valor;//nome
        noh *prox; //ponteiro para o proximo no(ou nulo)
    };

    int m;// tamanho da tabela(isto é,tamanho do vetor)
    noh* *t;//ponteiro para o vetor(de ponteiros para noh)
    int n;//quantidade de elementos armazenados na tabela

    int h(int chave){//função de dispersao (hash)
        return chave%m;
    }

    void redimensionar(int novo_m){
        noh* *u=new noh*[novo_m]; int i;
        for(i=0;i<novo_m;++i)u[i]=nullptr;

        int m_anterior=m; m=novo_m;//m é usado em h

        for(i=0;i<m_anterior;++i){
            noh *Noh=t[i];

            while(Noh !=nullptr){
                int j=h(Noh->chave);
                noh *inicio=u[j];//primeiro da lista u[j]
                u[j]=Noh;
                noh *proximo=Noh->prox;//proximo da lista t[i]
                Noh->prox=inicio;
                Noh=proximo;
            }

        }
        delete t; t=u;
    }
    public:

    const string *consultar(int chave){
        for(noh *p=t[h(chave)];p!=nullptr;p=p->prox){
            if(chave==p->chave)return &(p->valor);
        }
        return nullptr;
    }

    diciotd(){
        m=1;
        t=new noh*[m];
        n=0;
        for(int i=0;i<m;++i)t[i]=nullptr;
    }

    ~diciotd(){
        for(int i=0;i<m;++i){
            while(true){
                noh *Noh=t[i]; 
                if (Noh==nullptr)break;
                t[i]=Noh->prox;
                delete Noh;
            }
        }
        delete[]t;
    }

    void inserir(int chave,string valor){
        if(consultar(chave)!=nullptr) return; //a chave ja existe
        if(n==m) redimensionar(2*m);
        int i=h(chave);
        t[i]=new noh{chave,valor,t[i]};
        ++n;
    }

    void remover(int chave){
        int i=h(chave);        
        if(t[i]==nullptr)return; //lista vazia,chave não existe
        
        if(t[i]->chave==chave){
            noh *p=t[i];
            t[i]=p->prox;
            delete p;
        }
        else{
            noh *ant=t[i];

            while(true){
                noh *p=ant->prox;
                if(p==nullptr)return;// fim da lista,chave não existe

                if(p->chave==chave){
                    ant->prox=p->prox;
                    delete p;
                    return;
                }
                ant=p;
            }
        }
        if(m==4*n){
            redimensionar(m/2);
        }
    }

    vector<int> chaves_do_valor(string valor){
        vector<int> chavesencontradas;
        for(int i=0;i<m;++i){
            noh *p=t[i];
            while(p!=nullptr){
                if(p->valor==valor){
                    chavesencontradas.push_back(p->chave);
                }
                p->prox;
            }
        }
        return chavesencontradas;
    }

}; 

int main() {
    diciotd dicionario;

    dicionario.inserir(123, "Alice");
    dicionario.inserir(456, "Bob");
    dicionario.inserir(789, "Carol");

    // Consulta valores no dicionário
    cout << "Valor associado a chave 456: ";
    const string *valor = dicionario.consultar(456);
    if (valor != nullptr) {
        cout << *valor << endl;
    } else {
        cout << "Chave nao encontrada." << endl;
    }

    cout << "Valor associado à chave 999: ";
    valor = dicionario.consultar(999);
    if (valor != nullptr) {
        cout << *valor << endl;
    } else {
        cout << "Chave nao encontrada." << endl;
    }

    // Remoção de elementos do dicionário
    dicionario.remover(456);
    cout << "Valor associado a chave 456 apos a remocao: ";
    valor = dicionario.consultar(456);
    if (valor != nullptr) {
        cout << *valor << endl;
    } else {
        cout << "Chave nao encontrada." << endl;
    }

    return 0;
}

