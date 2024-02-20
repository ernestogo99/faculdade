#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

void inicializar(ArvoreBB **a) {
    *a = (ArvoreBB *)malloc(sizeof(ArvoreBB));
    if (*a == NULL) {
        printf("Erro de alocação de memória\n");
        exit(EXIT_FAILURE);
    }
    (*a)->raiz = NULL;
}

No *criar_no(int chave, float valor) {
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocação de memória\n");
        exit(EXIT_FAILURE);
    }
    novo->chave = chave;
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

int inserir_interativo(No **no, int chave, float val) {
    No *novo = criar_no(chave, val);

    if (*no == NULL) {
        *no = novo;
        return 1;
    }

    No *atual = *no;
    No *anterior = NULL;

    while (atual != NULL) {
        if (chave == atual->chave) {
            free(novo);
            return 0;
        }

        anterior = atual;

        if (chave < atual->chave) {
            atual = atual->esquerda;
        } else {
            atual = atual->direita;
        }
    }

    if (chave < anterior->chave) {
        anterior->esquerda = novo;
    } else {
        anterior->direita = novo;
    }

    return 1;
}
int inserir_recursivo(No **no, int chave, float val) {
    if (*no == NULL) {
        *no = criar_no(chave, val);
        return 1;
    }

    if (chave == (*no)->chave) {
        return 0;
    }

    if (chave < (*no)->chave) {
        return inserir_recursivo(&(*no)->esquerda, chave, val);
    } else {
        return inserir_recursivo(&(*no)->direita, chave, val);
    }
}

float buscar_interativo(No *no, int chave) {
    while (no != NULL) {
        if (chave == no->chave) {
            return no->valor;
        } else if (chave < no->chave) {
            no = no->esquerda;
        } else {
            no = no->direita;
        }
    }
    printf("Chave não encontrada.\n");
    return -99999.99;
}

float buscar_recursivo(No *no, int chave) {
    if (no == NULL) {
        printf("Chave não encontrada.\n");
        return -99999.99;
    }

    if (chave == no->chave) {
        return no->valor;
    } else if (chave < no->chave) {
        return buscar_recursivo(no->esquerda, chave);
    } else {
        return buscar_recursivo(no->direita, chave);
    }
}

void listar_elementos(No *no) {
    if (no != NULL) {
        listar_elementos(no->esquerda);
        printf("Chave: %d, Valor: %.2f\n", no->chave, no->valor);
        listar_elementos(no->direita);
    }
}
