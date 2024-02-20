#include "listaencad.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Registro *lista;
  inicializarLista(&lista);

  // Carregar dados do arquivo "dados.txt" para a lista
  if (carregarDados(&lista, "dados.txt")) {
    printf("Dados carregados com sucesso!\n");
  } else {
    printf("Erro ao carregar os dados do arquivo.\n");
  }

  // Inserir novos registros na lista
  // inserirFinal(&lista, "Jonas", 1234, 11, 99998887, "jonas@email.com", 'P');
  // inserir_inicio(&lista, "Carlito", 1010, 85, 99922423, "carlitos@gmail.com",
  // 'P');

  agd_remover(&lista, "Ana");
  agd_ordenar(&lista);

  // Salvar a lista atualizada no arquivo "dados.txt"
  if (salvarDados(lista, "dados.txt")) {
    printf("Dados salvos com sucesso!\n");
  } else {
    printf("Erro ao salvar os dados no arquivo.\n");
  }

  // Percorrer e imprimir a lista
  printf("Registros na lista:\n");
  percorrerLista(lista);

  // Liberar a memória alocada para a lista
  free(lista);

  return 0;
}
