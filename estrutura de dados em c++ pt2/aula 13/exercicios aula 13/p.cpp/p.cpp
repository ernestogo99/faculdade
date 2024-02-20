#include <iostream>
#include <string>
#include <new>
#include <sstream>
#include <cctype>
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
            cerr << "Erro: pilha vazia" << endl;
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
            cerr << "Erro: pilha vazia" << endl;
            return "";
        }
        return v[n - 1];
    }

    ~pilha() {
        delete[] v;
    }
};

double avaliarExpressao(string expressao) {
    pilha p;
    istringstream entrada{expressao};
    string palavra;
    while (entrada >> palavra) {
        if (isdigit(palavra[0]) || (palavra[0] == '-' && isdigit(palavra[1]))) {
            p.empilhar(palavra);
        }
        else {
            double dir = stod(p.topo());
            p.desempilhar();
            double esq = stod(p.topo());
            p.desempilhar();

            double res;
            if (palavra == "+") res = esq + dir;
            else if (palavra == "-") res = esq - dir;
            else if (palavra == "*") res = esq * dir;
            else if (palavra == "/") res = esq / dir;
            else {
                cerr << "Operador inválido: " << palavra << endl;
                return 0;
            }
            p.empilhar(to_string(res));
        }
    }
    return stod(p.topo());
}

int main() {
    try {
        cout << "Digite a expressão: ";
        string expressao;
        getline(cin, expressao);
        double resultado = avaliarExpressao(expressao);
        cout << "Resultado: " << resultado << '\n';

    }
    catch (const bad_alloc &e) {
        cerr << "Falta de memória\n";
        return 1;
    }

    return 0;
}
