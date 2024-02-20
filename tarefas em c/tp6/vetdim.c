#include<stdio.h>
#include <stdlib.h>
// funções do vetor
void liberar_vetor(void *mem){
  free(mem);
}

void *criar_vetor(int tam){
  void *v=malloc(tam * sizeof(int));
}

double obter_vetor(void *mem,int x){
  double *w=mem;
  double valor=w[x];
  return valor;
}

int atribuir_vetor(void *mem,int x,double valor){
  double *w=mem;
  w[x]=valor;
  return valor;
}
// funções da matriz
void *criarmatriz(int tamanho_x, int tamanho_y) {
    int i;
    double **matriz = malloc(tamanho_x * sizeof(double));
    
    for (i = 0; i < tamanho_x; ++i) {
        matriz[i] = malloc(tamanho_y * sizeof(double));
    }

    return (void **)matriz;
}

void liberarmatriz(void *mem){
    free(mem);
}
double obtermatriz(void *mem,int x,int y){
    double **matriz=mem;
    return matriz[x][y];
    

}

int atribuir_matriz(void *mem,int x,int y,double valor){
    double **matriz=mem;
    matriz[x][y]=valor;
}


