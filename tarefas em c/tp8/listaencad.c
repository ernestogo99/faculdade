#include "listaencad.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializarLista(Registro **lista) { *lista = NULL; }

Registro *buscar(Registro **lista, int matricula) {
  Registro *aux, *no = NULL;
  aux = *lista;
  while (aux && aux->matricula != matricula) {
    aux = aux->prox;
  }
  if (aux)
    no = aux;
  return no;
}

int inserirFinal(Registro **lista, char nome[], int matricula, int ddd,
                 int telefone, char email[], char tipo) {
  Registro *novo = (Registro *)malloc(sizeof(Registro));
  Registro *aux;

  if (novo == NULL) {
    return 0; // Falha na alocação de memória
  };
  strcpy(novo->nome, nome);
  novo->matricula = matricula;
  novo->ddd = ddd;
  novo->telefone = telefone;
  strcpy(novo->email, email);
  novo->tipo = tipo;

  novo->prox = NULL;
  // eh o primeiro?
  if (*lista == NULL) {
    *lista = novo;
    novo->ant = NULL;
  } else {
    Registro *atual = *lista;
    while (atual->prox != NULL) {
      atual = atual->prox;
    }
    atual->prox = novo;
    novo->ant = atual;
    novo->prox = NULL;
  }

  return 1; // Sucesso
}
void inserir_inicio(Registro **lista, char nome[], int matricula, int ddd,
                    int telefone, char email[], char tipo) {
  Registro *novo = (Registro *)malloc(sizeof(Registro));

  if (novo == NULL) {
    return; // Falha na alocação de memória
  };

  strcpy(novo->nome, nome);
  novo->matricula = matricula;
  novo->ddd = ddd;
  novo->telefone = telefone;
  strcpy(novo->email, email);
  novo->tipo = tipo;

  if (*lista == NULL) {
    *lista = novo;
    novo->prox = NULL;
    novo->ant = NULL;
  } else {
    (*lista)->ant = novo;
    novo->prox = *lista;
    novo->ant = NULL;
    *lista = novo;
  }
}
void agd_ordenar(Registro **lista) {
  Registro *aux, *prox;
  char temp[MAXNOME];

  for (aux = *lista; aux != NULL; aux = aux->prox) {
    for (prox = aux->prox; prox != NULL; prox = prox->prox) {
      if (strcmp(aux->nome, prox->nome) > 0) {
        strcpy(temp, aux->nome);
        strcpy(aux->nome, prox->nome);
        strcpy(prox->nome, temp);
      }
    }
  }
}

void agd_remover(Registro **lista, char nome[]) {
  Registro *ant, *aux;
  ant = NULL;
  aux = *lista;
  while (aux != NULL && strcmp(aux->nome, nome) != 0) {
    ant = aux;
    aux = aux->prox;
  }
  if (aux == NULL) {
    // Elemento não encontrado para remover
    return;
  } else if (ant == NULL) {
    // O elemento é o primeiro da lista
    ant = aux;
    aux->prox->ant = NULL;
    *lista = aux->prox;
    free(ant);
    agd_remover(lista, nome);     // Remover se houver mais ocorrências
  } else if (aux->prox == NULL) {
    // O elemento está no final da lista
    ant->prox = NULL;
    free(aux);
  } else {
    // O elemento está no meio da lista
    ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
    free(aux);
    agd_remover(lista, nome); // Remover se houver mais ocorrências
  }
}

void percorrerLista(Registro *lista) {
  Registro *atual = lista;
  while (atual != NULL) {
    printf("Nome: %s, Matricula: %d, DDD: %d, Telefone: %d, E-mail: %s, Tipo: "
           "%c\n \n",
           atual->nome, atual->matricula, atual->ddd, atual->telefone,
           atual->email, atual->tipo);
    atual = atual->prox;
  }
}

// Função para carregar dados de um arquivo de texto para a lista
int carregarDados(Registro **lista, const char *nomeArquivo) {
  FILE *arquivo = fopen(nomeArquivo, "r"); // Abre o arquivo para leitura

  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo %s.\n", nomeArquivo);
    return 0; // Retorna 0 em caso de erro
  }

  char nome[MAXNOME];
  int matricula, ddd, telefone;
  char email[MAXEMAIL];
  char tipo;

  while (fscanf(arquivo, "%d %s %d %d %s %c", &matricula, nome, &ddd, &telefone,
                email, &tipo) != EOF) {
    if (!inserirFinal(lista, nome, matricula, ddd, telefone, email, tipo)) {
      printf("Erro ao inserir registro no arquivo.\n");
      fclose(arquivo);
      return 0;
    }
  }

  fclose(arquivo); // Fecha o arquivo
  return 1;        // Retorna 1 em caso de sucesso
}
// Função para salvar os dados da lista em um arquivo de texto
int salvarDados(Registro *lista, const char *nomeArquivo) {
  FILE *arquivo = fopen(nomeArquivo, "w"); // Abre o arquivo para escrita

  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo %s.\n", nomeArquivo);
    return 0; // Retorna 0 em caso de erro
  }

  Registro *atual = lista;

  while (atual != NULL) {
    fprintf(arquivo, "%d %s %d %d %s %c\n", atual->matricula, atual->nome,
            atual->ddd, atual->telefone, atual->email, atual->tipo);
    atual = atual->prox; // Avança para o próximo registro
  }

  fclose(arquivo); // Fecha o arquivo
  return 1;        // Retorna 1 em caso de sucesso
}