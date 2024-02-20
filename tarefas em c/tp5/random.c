#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

void populateRandomArray(int *v, int size, int max_value) {
    int i;
    for (i = 0; i < size; i++) {
        v[i] = rand() % (max_value + 1);
    }
}


void bubblesort(int *v,int n){
    int passo,i;
    int aux;
    for(passo=0;passo<n-1;++passo){
        for(i=0;i<n-1-passo;++i){
            if(v[i]>v[i+1]){
                aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;

            }
            

        }
    }
}


void insersort(int *v,int n){
    int i,aux,j;
    for(i=1;i<n;++i){
        aux=v[i];
        j=i-1;
        while(j>=0 && aux<v[j]){
            v[j+1]=v[j];
            j=j-1;
        }
        v[j+1]=aux;
    }
}

void selectsort(int *v,int n){
    int i,j,aux;
    for(i=0;i<n-1;++i){
        for(j=i+1;j<n;++j){
            if(v[j]<v[i]){
                aux=v[j];
                v[j]=v[i];
                v[i]=aux;
            }
        }
    }
}

void combsort(int *v,int n){
    int aux,intervalo,trocado,i,j;
    intervalo=n;
    trocado=1;
    while(intervalo!=1 || trocado==1){
        trocado=0;
        intervalo=intervalo/1.3;
        if(intervalo<1){
            intervalo=1;
        }
        for(i=0;i<n-intervalo;++i){
            if(v[i]>v[i+intervalo]){
                aux=v[i];
                v[i]=v[i+intervalo];
                v[i+intervalo]=aux;
                trocado=1;
            }
        }
    }
}

int main(){
   srand(time(NULL));
   #define N 100000 // tamanho inicial do vetor
   #define K 100 // numero de vezes que cada algoritmo é executado
   int max_value=100*N;
   int i,j,k,l;

   int *v=(int*)malloc(N*sizeof(int));

   clock_t startt,endt;

   //bubblesort

   printf("\nbubblesort:\n");
   populateRandomArray(v,N,max_value);
   startt=clock();
   for(i=0;i<K;++i){
        bubblesort(v,N);
   }
   endt=clock();
   printf("Tempo médio de execução: %.6f segundos\n", (double)(endt - startt) / (CLOCKS_PER_SEC * K));
   
   //combsort
   printf("\n combsort:\n");
   populateRandomArray(v,N,max_value);
   startt=clock();
   for(j=0;j<K;++j){
    combsort(v,N);
   }
   endt=clock();
   printf("Tempo médio de execução: %.6f segundos\n", (double)(endt - startt) / (CLOCKS_PER_SEC * K));


   printf("\n bubblesort:\n");
   populateRandomArray(v,N,max_value);
   startt=clock();
   for(k=0;k<K;++k){
    bubblesort(v,N);
   }
   endt=clock();
   printf("Tempo médio de execução: %.6f segundos\n", (double)(endt - startt) / (CLOCKS_PER_SEC * K));

   printf("\n selectsort:\n");
   populateRandomArray(v,N,max_value);
   startt=clock();
   for(l=0;l<K;++l){
    selectsort(v,N);
   }
   endt=clock();
   printf("Tempo médio de execução: %.6f segundos\n", (double)(endt - startt) / (CLOCKS_PER_SEC * K));

   free(v);

   return 0;

}