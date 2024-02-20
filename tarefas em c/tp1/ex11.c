#include <stdio.h>

int main(void) {

  int dn, mn, an, da, ma, aa, diasTotais, diasHoje, diasNascimento;
  
  printf("Digite o dia de nascimento:\n");
  scanf("%d", &dn);
  printf("Digite o mes de nascimento:\n");
  scanf("%d", &mn);
  printf("Digite o ano de nascimento:\n");
  scanf("%d", &an);
  printf("Digite o dia de hoje:\n");
  scanf("%d", &da);
  printf("Digite o mes de hoje:\n");
  scanf("%d", &ma);
  printf("Digite o ano de hoje:\n");
  scanf("%d", &aa);

  int aux = aa-an;
  int contAux = 0;

  if((an%4 == 0) && !(an%100 == 0)){
    contAux+=1;
  }
  
  int aux2 = aux/4;
  contAux += aux2;
  
  diasHoje = da + 30*ma + 365*aa;
  diasNascimento = dn + 30*mn + 365*an;

  diasTotais = diasHoje - diasNascimento + contAux;

  printf("Total de dias vividos: %d", diasTotais);
  
  return 0;
}