#include <stdio.h>

int main(int argc, char *argv[]) {
    int dia, mes, dia_atual, mes_atual, ano, ano_atual,cont;

    printf("Digite o dia de nascimento: \n");
    scanf("%d", &dia);
    printf("Digite o mês de nascimento: \n");
    scanf("%d", &mes);
    printf("Digite o ano de nascimento: \n");
    scanf("%d", &ano);

    printf("Digite o dia atual: \n");
    scanf("%d", &dia_atual);
    printf("Digite o mês atual: \n");
    scanf("%d", &mes_atual);
    printf("Digite o ano atual: \n");
    scanf("%d", &ano_atual);
    cont=0;
    if(ano%4==0 && ano%100!=0){
        cont+=1;
    }
    int anos_vividos = ano_atual - ano;
    int ano2=anos_vividos/4;
    cont+=ano2;
   
    int dias_vividos = ((ano_atual * 365 + mes_atual * 30 + dia_atual) - (ano * 365 + mes * 30 + dia))+ cont;


    printf("A pessoa tem %d dias de vida \n", dias_vividos);

    return 0;
}
