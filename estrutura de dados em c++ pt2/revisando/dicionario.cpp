#include <iostream>
#include <string>

struct Registro {
    int chave;
    std::string valor;

    Registro(int matricula, const std::string& nome) : chave(matricula), valor(nome) {}
    // Adicionando um construtor padrão
    Registro() : chave(0), valor("") {}
};

class Dicionario {
private:
    Registro* dados;
    int capacidade;
    int tamanho;

public:
    Dicionario(){
        tamanho=0;
        dados=new Registro[tamanho];
        capacidade=0;
    }

    ~Dicionario() {
        delete[] dados;
    }

    void inserir(int chave, const std::string& valor) {
        int indice = buscaBinaria(chave);

        if (tamanho == capacidade) {
            capacidade = capacidade == 0 ? 1 : capacidade * 2;
            Registro* novo = new Registro[capacidade];
            
            int posicao = 0;
            for (int i = 0; i < tamanho; ++i) {
                if (posicao == indice) {
                    novo[posicao++] = Registro(); // Chamando o construtor padrão
                    novo[posicao-1].chave = chave;
                    novo[posicao-1].valor = valor;
                }
                novo[posicao++] = dados[i];
            }

            if (posicao == indice) {
                novo[posicao++] = Registro(); // Chamando o construtor padrão
                novo[posicao-1].chave = chave;
                novo[posicao-1].valor = valor;
            }

            delete[] dados;
            dados = novo;
            tamanho++;
        } else {
            for (int i = tamanho; i > indice; --i) {
                dados[i] = dados[i - 1];
            }
            dados[indice] = Registro(chave, valor);
            tamanho++;
        }
    }

    std::string consultar(int chave) const {
        int indice = buscaBinaria(chave);
        if (indice >= 0 && indice < tamanho && dados[indice].chave == chave) {
            return dados[indice].valor;
        }
        return "Chave nao encontrada.";
    }

    bool remover(int chave) {
        int indice = buscaBinaria(chave);
        if (indice >= 0 && indice < tamanho && dados[indice].chave == chave) {
            for (int i = indice; i < tamanho - 1; ++i) {
                dados[i] = dados[i + 1];
            }
            tamanho--;
            return true;
        }
        return false;
    }

private:
    int buscaBinaria(int chave) const {
        int inicio = 0;
        int fim = tamanho - 1;
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
};

int main() {
    Dicionario dicionario;

    dicionario.inserir(123, "Joao");
    dicionario.inserir(456, "Maria");
    dicionario.inserir(789, "Pedro");

    std::cout << "Consultando matricula 456: " << dicionario.consultar(456) << std::endl;

    dicionario.remover(456);

    std::cout << "Consultando matricula 456 apos remocao: " << dicionario.consultar(456) << std::endl;

    return 0;
}
