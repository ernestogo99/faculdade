#include <stdio.h>
#include <stdlib.h>


int main(int narg, char *argv[]){
    int jogadas[15]={};
    int sorteados[6]={};
    int contac=0;
    int i,j,n;

    printf("digite a quantidade de numeros da cartela(6<=n<=15) ");
    scanf("%d",&n);

    for(i=0;i<n;++i){
        printf("digite os numeros da cartela ");
        scanf("%d",&jogadas[i]);
    }

    for(j=0;j<6;++j){
        printf("digite os numeros sorteados ");
        scanf("%d",&sorteados[j]);
    }

    for(i=0;i<n;++i){
        for(j=0;j<6;++j){
            if(jogadas[i]==sorteados[j]){
                contac++;
            }
        }
    }

    if(contac==6){
        printf("mega sena");
    }
    else if(contac==5){
        printf("quina");
    }
    else if(contac==4){
        printf("quadra");
    }
    else{
        printf("voce perdeu");
    }
printf("\n");
return EXIT_SUCCESS;
    




}
