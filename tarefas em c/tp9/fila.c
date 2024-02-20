#include <stdlib.h>
#include <stdio.h>
#include "fila.h"
#include <string.h>

int vazia(fila *f){
    if(f==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int enfileirar(fila **f,char nome[250],int conta ,float valor){
    fila *aux,*novo=malloc(sizeof(fila));
    if(novo){
        strcpy(novo->nome,nome);
        novo->conta=conta;
        novo->valor=valor;
        novo->prox=NULL;
        if(vazia(*f)){// é o primeiro?
            *f=novo;
        }
        else{
            aux=*f;
            while(aux->prox){
                aux=aux->prox;
            }
            aux->prox=novo;
        }
        return 1;
    }
    else{
        printf("erro ao alocar memoria ");
        return 0;
    }
}

float consulta_valor_proximo(fila*f){
    if(vazia(f)){
        printf("erro, fila vazia ");
        return -1;
    }
    else{
        return f->valor;
    } 
}

int consulta_conta_proximo(fila *f){
    if(vazia(f)){
        printf("erro,fila vazia");
        return -1;
    }
    else{
        return f->conta;
    }
}

char *desinfileirar(fila **f) {
    if (vazia(*f)) {
        printf("Erro: fila vazia\n");
        return NULL;
    }

    // Aloca dinamicamente memória para o nome do cliente removido
    char *nome = malloc(sizeof(char) * (strlen((*f)->nome) + 1));

    if (nome == NULL) {
        printf("Erro ao alocar memória\n");
        return NULL;
    }

    // Armazena temporariamente o número da conta e o valor do cliente removido
    int conta = (*f)->conta;
    float valor = (*f)->valor;

    // Copia o nome do cliente para a área de memória recém-alocada
    strcpy(nome, (*f)->nome);

    // Usa um ponteiro temporário para manter uma referência ao nó que será removido
    fila *temp = *f;

    // Atualiza o ponteiro da fila para apontar para o próximo nó
    *f = (*f)->prox;

    // Libera a memória do nó removido
    free(temp);

    // Retorna o ponteiro para a string do nome do cliente
    return nome;
}

void imprimir(fila* f) {
    printf("Clientes na fila:\n");
    while (f) {
        printf("Nome: %s, Conta: %d, Valor: %.2f\n", f->nome, f->conta, f->valor);
        f = f->prox;
    }
}