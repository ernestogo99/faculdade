#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n, ultimo = 0, penultimo = 1;
    int atual = 1;

    printf("digite um numero inteiro positivo: ");
    scanf("%d", &n);

    printf("%d %d", ultimo, penultimo);

    while (atual < n) {
        printf(" %d", atual);
        ultimo = penultimo;
        penultimo = atual;
        atual = ultimo + penultimo;
    }

    printf("\n");

    return EXIT_SUCCESS;
}
