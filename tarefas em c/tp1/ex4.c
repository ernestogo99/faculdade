#include <stdio.h>

int main(void) {
  float d,valor,icms,lucro,vreais,valorl,valoricms,total;
  printf("digite o valor da compra em dolar: ");
  scanf("%f",&d);
  printf("digite o valor  que se encontrava o dolar durante a compra: ");
  scanf("%f",&valor);
  printf("digite o percentual de lucro da empresa: ");
  scanf("%f",&lucro);
  printf("digite o percentual que incide o icms em seu estado: ");
  scanf("%f",&icms);

  vreais=d*valor;
  printf("o valor da compra em real e sem taxas é: %.2f \n",vreais);

  valorl=vreais*(lucro/100);
  printf("a empresa irá obter  de lucro: %.2f reais \n",valorl);

  valoricms=vreais*(icms/100);
  printf("o imposto será de: %.2f reais \n",valoricms);

  total=vreais+valorl+valoricms;
  
  printf("o valor total pago em reais e: %.2f \n",total);


  
  
  
  
  return 0;
}