#include <iostream>
#include <new>
#include <string>
using namespace std;

struct registro{
    int chave;
    string valor;

    registro(int matricula,const string nome){
        chave=matricula;
        valor=nome;
    }
    registro(){
        chave=0;
        valor="";
    }
};
struct dicionario{
    registro *dados;
    int n;
    int tam;

    
    dicionario(){
        tam=1;
        dados=new registro[tam];
        n=0;
    }

    ~dicionario(){
        delete []dados;
    }

     int buscabinaria(int chave) const {
        int inicio = 0;
        int fim = n-1;
        while (inicio <= fim) {
            int meio = inicio + (fim - inicio) / 2;
            if (dados[meio].chave == chave) {
                return meio;
            } else if (dados[meio].chave < chave) {
                inicio = meio + 1;
            } else {
                fim = meio - 1;
            }
        }
        return inicio; // Retorna a posição onde a chave deveria estar inserida
    }


void inserir(int chave, const string valor) {
    int indice = buscabinaria(chave);

    if (n == tam) {
        tam = tam * 2;
        registro *w = new registro[tam];

        for (int i = 0; i < indice; ++i) {
            w[i] = dados[i];
        }

        w[indice] = registro(chave, valor);

        for (int i = indice; i < n; ++i) {
            w[i + 1] = dados[i];
        }

        delete[] dados;
        dados = w;
    } else {
        for (int i = n; i > indice; --i) {
            dados[i] = dados[i - 1];
        }
        dados[indice] = registro(chave, valor);
    }

    n++;
}


   string consultar(int chave) const {
        int indice = buscabinaria(chave);
        if (indice >= 0 && indice < tam && dados[indice].chave == chave) {
            return dados[indice].valor;
        }
        return "Chave nao encontrada.";
    }

  bool remover(int chave){
    int indice = buscabinaria(chave);
    if (indice >= 0 && indice < n && dados[indice].chave == chave){
        for (int i = indice; i < n - 1; ++i){
            dados[i] = dados[i + 1];
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
