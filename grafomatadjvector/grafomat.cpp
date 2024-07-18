#include <iostream>
#include "grafomat.h"

using namespace std;

// construtor
grafo::grafo(int max, int valoresarestanula) 
    : maxvertices(max), arestanula(valoresarestanula),
      vertices(), matrizadjacencias(max, vector<int>(max, valoresarestanula)) {}



int grafo::obterindice(string item) {
    for (int i = 0; i < vertices.size(); ++i) {
        if (vertices[i] == item) {
            return i;
        }
    }
    cout << "vertice nao encontrado" << endl;
    return -1;
}

bool grafo::estacheio() {
    return (vertices.size() == maxvertices);
}

void grafo::inserirvertice(string item) {
    if (estacheio()) {
        cout << "o numero maximo de vertices foi alcancado";
    } else {
        vertices.push_back(item);
    }
}

void grafo::inseriraresta(string nosaida, string noentrada, int peso) {
    int linha = obterindice(nosaida);
    int coluna = obterindice(noentrada);
    if (linha == -1 || coluna == -1) {
        cout << "pelo menos um dos vertices nao foi encontrado" << endl;
        return;
    }

    matrizadjacencias[linha][coluna] = peso;
    matrizadjacencias[coluna][linha] = peso;
}

int grafo::obterpeso(string nosaida, string noentrada) {
    int linha = obterindice(nosaida);
    int coluna = obterindice(noentrada);
    if (linha == -1 || coluna == -1) {
        cout << "pelo menos um dos vertices nao foi encontrado" << endl;
        return -1;
    }
    return matrizadjacencias[linha][coluna];
}

int grafo::obtergrau(string item) {
    int linha = obterindice(item);
    if (linha == -1) {
        cout << "o vertice nao existe";
        return -1;
    }
    int grau = 0;
    for (int i = 0; i < maxvertices; ++i) {
        if (matrizadjacencias[linha][i] != arestanula) {
            grau++;
        }
    }
    return grau;
}

void grafo::imprimirmatriz() {
    cout << "matriz de adjacencias:\n";
    for (const auto& linha : matrizadjacencias) {
        for (int valor : linha) {
            cout << valor << " ";
        }
        cout << endl;
    }
}

void grafo::imprimirvertices() {
    cout << "lista de vertices:\n";
    for (int i = 0; i < vertices.size(); ++i) {
        cout << i << ": " << vertices[i] << endl;
    }
}
