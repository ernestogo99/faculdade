#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main() {
    fila *f = NULL;
    int opcao, conta;
    float valor;
    char *nomeRemovido;

    do {
        printf("\t0 - sair \n\t1 - inserir \n\t2 - remover\n\t3 - imprimir \n\t4 - consultar conta \n\t5 - consultar valor \n ");
        scanf("%d", &opcao);

          

        switch (opcao) {
            case 0:
                // Sair
                break;

            case 1:
                // Inserir
                printf("Digite o nome: ");
                char nome[250];
                scanf("%s", nome);
                printf("Digite o número da conta: ");
                scanf("%d", &conta);
                printf("Digite o valor: ");
                scanf("%f", &valor);
                enfileirar(&f, nome, conta, valor);
                break;

            case 2:
                // Remover
                nomeRemovido = desinfileirar(&f);
                if (nomeRemovido != NULL) {
                    printf("Cliente removido: %s\n", nomeRemovido);
                    free(nomeRemovido);
                }
                break;

            case 3:
                // Imprimir
                imprimir(f);
                break;

            case 4:
                // Consultar conta
                conta = consulta_conta_proximo(f);
                if (conta != -1) {
                    printf("Próximo cliente na fila tem conta: %d\n", conta);
                }
                break;

            case 5:
                // Consultar valor
                valor = consulta_valor_proximo(f);
                if (valor != -1.0) {
                    printf("Próximo cliente na fila deseja sacar: %.2f\n", valor);
                }
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);

    // Liberar memória ao final do programa
    while (!vazia(f)) {
        nomeRemovido = desinfileirar(&f);
        free(nomeRemovido);
    }

    return 0;
}
