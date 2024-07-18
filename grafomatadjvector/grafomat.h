#ifndef GRAFOMATADJ_H
#define GRAFOMATADJ_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct grafo{
    int arestanula;
    int maxvertices;
    vector<string> vertices; // vetor de vértices
    vector<vector<int>> matrizadjacencias; // matriz de adjacências

    grafo(int max, int valoresarestanula);
    ~grafo() = default; 
    int obterindice(string item);
    bool estacheio();
    void inserirvertice(string item);
    void inseriraresta(string nosaida, string noentrada, int peso);
    int obterpeso(string nosaida, string noentrada);
    int obtergrau(string item);
    void imprimirmatriz();
    void imprimirvertices();
};

#endif // GRAFOMATADJ_H
