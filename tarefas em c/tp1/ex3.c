#include <stdio.h>

int main(int narg,char *argv[]) {
  float valorht,ht,salario;
  int filhos;
  printf("digite a quantidade de filhos: ");
  scanf("%d",&filhos);
  printf("digite a quantidade de horas trabalhadas: ");
  scanf("%f",&ht);
  printf("digite o valor recebido por cada hora trabalhada: ");
  scanf("%f",&valorht);
  salario=(ht*valorht);

  printf("o salário sem gratificação é: %.2f \n",salario);

  if(filhos>3){
    salario=(ht*valorht) +(ht*valorht*0.03*filhos);
    printf("o salario com bonificação e: %.2f \n",salario);
    
    
  }

  
  return 0;
}