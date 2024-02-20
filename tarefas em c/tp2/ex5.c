#include <stdio.h>
#include <stdlib.h>

int main(int narg, char *argv[]){
    int n, inv=0,resto;
    printf("digite um numero de ate 10 digitos ");
    scanf("%d",&n);

    while(n!=0){
        resto=n%10;
        inv=inv*10+resto;
        n/=10;
    }

    printf("o numero invertido e %d ",inv);

}