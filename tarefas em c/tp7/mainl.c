#include "listaencad.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Registro *lista;
  inicializarLista(&lista);

  
  if (carregarDados(&lista, "dados.txt")) {
    printf("Dados carregados com sucesso!\n");
  } else {
    printf("Erro ao carregar os dados do arquivo.\n");
  }


  inserir_inicio(&lista, "Jonas", 1234, 11, 99998887, "jonas@email.com", 'P');
  agd_inserir_final(&lista, "Mariana", 5678, 21, 98765432, "mariana@email.com", 'C');
  agd_inserir_inicio(&lista, "Alice", 7890, 11, 99887766, "alice@email.com", 'C');

 
  agd_remover(&lista, "Jonas");
  agd_remover(&lista, "Ana");
  agd_ordenar(&lista);


  if (salvarDados(lista, "dados.txt")) {
    printf("Dados salvos com sucesso!\n");
  } else {
    printf("Erro ao salvar os dados no arquivo.\n");
  }


  printf("Registros na lista:\n");
  percorrerLista(lista);


  free(lista);

  return 0;
}
