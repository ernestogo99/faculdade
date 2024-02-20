#include <stdlib.h>
#include <stdio.h>

int main(int narg, char *argv[]){
    int v[100000];
    int n=0;
    int i=0,j;
    int l,c;
    int aux;
    
    while(n>=0){
        printf("digite um valor inteiro (negativo para encerrar) ");
        scanf("%d",&n);
        if(n>0){
            v[i]=n;
            ++i;
        }
    }

    printf("vetor:\n");
    for(j=0;j<i;++j){
        printf("%d ",v[j]);
    }

    printf("\n");

    for(l=0;l<i-1;++l){
        for(c=0;c<i-l-1;++c){
            if(v[c]>v[c+1]){
                aux=v[c];
                v[c]=v[c+1];
                v[c+1]=aux;
            }

        }
    }


    printf("vetor ordenado\n");
    for(j=0;j<i;++j){
        printf("%d ",v[j]);
    }

    printf("\n");

    return EXIT_SUCCESS;



}