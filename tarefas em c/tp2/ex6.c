#include <stdio.h>
#include <stdlib.h>

int main(int narg, char *argv[]){
    int n,contn=0,cont3=0;
    float median=0,media3=0;
    while(cont3!=10){
        printf("digite um numero inteiro: ");
        scanf("%d",&n);
        if(n%3==0){
            cont3++;
            media3+=n;
        }
        else{
            contn++;
            median+=n;
        }
        
    }
    printf("a media aritmetica dos numeros nao divisiveis por 3 eh: %.2f \n",median/contn);
    printf("a media dos numeros divisiveis por 3 eh: %.2f \n",media3/cont3);
}