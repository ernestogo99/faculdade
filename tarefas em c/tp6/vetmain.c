#include <stdio.h>
#include <stdlib.h>
#include "vetdim.h"

int main(){
  void *mat;
  void *v=criar_vetor(16);
  
  atribuir_vetor(v, 8, 456.0);
  double valor=obter_vetor(v,8);

  printf(" a pos. 8 do vetor contem %.3f.\n",valor);
  liberar_vetor(v);
  

  mat=criarmatriz(10,10);
  atribuir_matriz(mat,5,4,12.0);
  printf(" a pos. (5,4) da matriz = %.3f.\n",obtermatriz(mat,5,4));
  liberarmatriz(mat);
  
  
}