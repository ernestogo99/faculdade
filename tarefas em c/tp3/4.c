#include <stdlib.h>
#include <stdio.h>

void multiplicamat(int matrizA[20][20], int matrizB[20][20], 
int resultado[20][20], int linhasA, int colunasA, int colunasB) {
    int i,j,k;
    for ( i = 0; i < linhasA; i++) {
        for ( j = 0; j < colunasB; j++) {
            resultado[i][j] = 0; /* Inicializa o elemento da matriz resultado */

            /* Calcula o produto dos elementos de A e B e acumula no resultado */
            for ( k = 0; k < colunasA; k++) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}

void imprimir(int m[20][20], int linhas, int colunas) {
    int i, j;
    for (i = 0; i < linhas; ++i) {
        for (j = 0; j < colunas; ++j) {
            printf("%d ", m[i][j]);  
        }
        printf("\n");
    }
}

int main() {
    
    int resultado[20][20];
    int a[20][20];
    int b[20][20];
    int i, j;
    int x, y, z;
    printf("Digite a quantidade de linhas da matriz A (<=20): \n");
    scanf("%d", &x);
    printf("Digite a quantidade de colunas da matriz A e de linhas da matriz B (<=20): \n");
    scanf("%d", &y);
    printf("Digite a quantidade de colunas da matriz B(<=20): \n");
    scanf("%d", &z);

    /* Preenchendo A */
    
    for (i = 0; i < x; ++i) {
        printf("digite os elementos da linha %d da matriz a\n ",i);
        for (j = 0; j < y; ++j) {
            printf("digite os elementos da coluna %d da matriz a\n ",j);
            scanf("%d", &a[i][j]);
        }
        
    }
    printf("matriz a\n");
    imprimir(a, x, y);
    printf("\n");
     /* Preenchendo B */  
    for (i = 0; i < y; ++i) {
    printf("digite os elementos da linha %d da matriz b\n ",i);
    for (j = 0; j < z; ++j) {
        printf("digite os elementos da coluna %d da matriz b\n ",j);
        scanf("%d", &b[i][j]);
    }
}
    printf("matriz b\n");
    imprimir(b,y,z);
    printf("\n");

    multiplicamat(a,b,resultado,x,y,z);
    printf("matriz resultado\n");
    imprimir(resultado,x,z);
    



    return EXIT_SUCCESS;
}
