#include <iostream>
#include <string>
#include <new>
using namespace std;

struct registro{
    int chave;
    string valor;

    registro(int mat,string nome){
        chave=mat;
        valor=nome;
    }

    registro(){
        chave=0;
        valor="";
    }
};

struct dicionario{
    int tam;
    int n;
    registro *v;

    dicionario(){
        tam=1;
        v=new registro[tam];
        n=0;
    }
    ~dicionario(){
        delete[]v;
    }

    int buscabinaria(int chave){
        int ini=0;
        int fim=n-1;
        while(ini<=fim){
            int meio=ini+(fim-ini)/2;
            if(chave==v[meio].chave){
                return meio;
            }
            else if(chave<v[meio].chave){
                fim=meio-1;
            }
            else{
                ini=meio+1;
            }
        }
        return ini;
    }

    void inserir(int chave,string valor){
        int indice=buscabinaria(chave);
        if(n==tam){
            tam=tam*2;
            registro *w=new registro[tam];
            for(int i=0;i<indice;++i){
                w[i]=v[i];
            }
            w[indice]=registro(chave,valor);

            for(int i=indice;i<n;++i){
                w[i+1]=w[i];
            }
            delete[]v;
            v=w;
        }
        else{
            for(int i=indice;i<n;++i){
                v[i+1]=v[i];
            }
            v[indice]=registro(chave,valor);
        }
        ++n;
    }

    string consultar(int chave){
        int indice=buscabinaria(chave);
        if(indice>=0 and indice<tam and v[indice].chave==chave){
            return v[indice].valor;
        }
        return "chave nao encontrada";
    }

    bool remover(int chave){
        int indice=buscabinaria(chave);
        if(indice>=0 and indice<n and v[indice].chave==chave){
            for(int i=0;i<n-1;++i){
                v[i]=v[i+1];
            }
            n--;
            return true;
        }
        return false;
    }

};

int main() {
    dicionario dicionario;

    dicionario.inserir(123, "Joao");
    dicionario.inserir(456, "Maria");
    dicionario.inserir(789, "Pedro");

    cout << "Consultando matricula 456: " << dicionario.consultar(456) << std::endl;

    dicionario.remover(456);

    cout << "Consultando matricula 456 apos remocao: " << dicionario.consultar(456) << std::endl;

    return 0;
}
