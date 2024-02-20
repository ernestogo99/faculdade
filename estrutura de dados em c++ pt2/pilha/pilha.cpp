#include <iostream>
#include <sstream>
#include <string>
using namespace std;
struct Pilha {
    int top;
    string elementos[100];

    Pilha() : top(-1) {}

    void empilhar(const string& elemento) {
        elementos[++top] = elemento;
    }

    string desempilhar() {
        if (top >= 0) {
            return elementos[top--];
        }
        return "";
    }
};

double paraNumero(const string& str) {
    return stod(str);
}

double lerExpressao() {
    Pilha p;

    while (true) {
        string palavra;
        cin >> palavra;

        if (palavra.empty()) {
            break;
        }

        if (palavra == "+" || palavra == "-" || palavra == "*" || palavra == "/") {
            double dir = paraNumero(p.desempilhar());
            double esq = paraNumero(p.desempilhar());

            double res;
            if (palavra == "+")
                res = esq + dir;
            else if (palavra == "-")
                res = esq - dir;
            else if (palavra == "/")
                res = esq / dir;
            else
                res = esq * dir;

            p.empilhar(to_string(res));
        } else {
            p.empilhar(palavra);
        }
    }

    return paraNumero(p.desempilhar());
}

int main() {
    string linha;
    getline(std::cin, linha);

    istringstream entrada(linha);

    double resultado = lerExpressao();
    cout << "Resultado da expressao: " << resultado << std::endl;

    return 0;
}
