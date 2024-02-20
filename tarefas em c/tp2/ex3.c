

#include <stdlib.h>
#include <stdio.h>

int main(int narg, char *argv[]){
    int n=1000;
    int cont=0;
    int num=1;
    while(cont<n){
        if(num%2!=0 && num%7!=0 && num%3!=0){
            printf(" %d ",num);
            cont+=1;
        }
        num++;

    }

    printf('\n');
    return EXIT_SUCCESS;
}
