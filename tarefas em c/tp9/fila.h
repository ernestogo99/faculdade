#include<stdio.h>
#include<stdlib.h>
typedef struct fila{
    char nome[250];
    int conta;
    float valor;
   struct fila *prox;
}fila;

int enfileirar(fila **f,char nome[250],int conta ,float valor);
int vazia(fila *f);
float consulta_valor_proximo(fila*f);
int consulta_conta_proximo(fila *f);
char *desinfileirar(fila **f);
void imprimir(fila *f);
