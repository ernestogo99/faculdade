#include <stdlib.h>
#include <stdio.h>

int main(int narg, char *argv[]){
   int v[1000];
    int n;
    int r=0;
    int pg=1;
    printf("digite a quantidade de termos: ");
    scanf("%d",&n);
    int i;
    for(i=0;i<n;++i){
        printf("informe o numero %d: ",1+i);
        scanf("%d",&v[i]);

        if(i>0){
            r=v[1]/v[0];
            if(v[i]/v[i-1]!=r){
                ++pg;
            }
        }

    }

    if(pg==1){
        printf("eh uma pg de razao %d ",r);
    }

    else{
        printf("nao eh uma pg");
    }

    return EXIT_SUCCESS;
}