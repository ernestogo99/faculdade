#include <stdio.h>

int main(int narg,char *argv[]){
    float ini,j,valor;
    int meses;
    printf("digite o valor inicial da prestação em reais: ");
    scanf("%f",&ini);
    printf("digite o tempo de atraso em meses: ");
    scanf("%d",&meses);
    printf("digite a taxa de juros: ");
    scanf("%f",&j);

    valor=ini+(ini*(j/100)*meses);

    printf("o valor da prestação em atraso e R$ %.2f  \n",valor);


    return 0;



}