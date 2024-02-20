

#include <stdlib.h>
#include <stdio.h>

int main(int narg, char *argv[]) {
    int k,n,cont=0;
    printf("digite um numero inteiro: ");
    scanf("%d",&n);

    k=n;
    while(cont!=2){
         cont=0;
         k-=1;
         for(int i=1;i<k+1;++i){
            if(k%i==0){
                cont++;
            }
         }
        
    }
    printf("o maior numero primo antes de %d eh %d ",n,k);
    return EXIT_SUCCESS;

}
