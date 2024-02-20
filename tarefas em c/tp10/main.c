#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "abb.h"

int main() {
    ArvoreBB *arvore;
    inicializar(&arvore);

    srand(time(NULL));

  
    int chave, i;
    float valor;

    for (i = 0; i < 10; i++) {
        chave = rand() % 20; 
        valor = (float)rand() / RAND_MAX * 100.0; 
        inserir_interativo(&arvore, chave, valor);
    }

   
    printf("Elementos na árvore:\n");
    listar_elementos(arvore);

    
    int chaveBusca = 5; 
    float resultado = buscar_interativo(arvore, chaveBusca);

    if (resultado == -99999.99) {
        printf("Chave %d não encontrada na árvore.\n", chaveBusca);
    } else {
        printf("Valor encontrado para a chave %d: %.2f\n", chaveBusca, resultado);
    }

    return 0;
}
