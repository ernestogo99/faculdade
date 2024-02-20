#include <stdio.h>
#include <stdlib.h>
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


int main() {
    srand(time(NULL));

    #define N 10000  // Tamanho inicial do vetor
    #define K  100   // Número de vezes que cada algoritmo é executado
    int max_value = 100 * N;
    int i,j,k,l;

    printf("Tamanho do vetor (N): %d\n", N);
    printf("Numero de execucoes (K): %d\n", K);
    printf("Maximo valor gerado: %d\n", max_value);

    int *v = (int *)malloc(N * sizeof(int));
    clock_t start_time, end_time;

    // Bubble Sort
    printf("\nBubble Sort:\n");
    populateRandomArray(v, N, max_value);
    start_time = clock();
    for ( i = 0; i < K; i++) {
        bubblesort(v, N);
    }
    end_time = clock();
    printf("Tempo de execucao das k execucoes: %.6f segundos\n", (double)(end_time - start_time) / (CLOCKS_PER_SEC ));

    // Insertion Sort
    printf("\nInsertion Sort:\n");
    populateRandomArray(v, N, max_value);
    start_time = clock();
    for (j = 0; j< K; j++) {
        insersort(v, N);
    }
    end_time = clock();
    printf("Tempo de execucao das k execucoes: %.6f segundos\n", (double)(end_time - start_time) / (CLOCKS_PER_SEC ));

    // Selection Sort
    printf("\nSelection Sort:\n");
    populateRandomArray(v, N, max_value);
    start_time = clock();
    for (k = 0; k < K; k++) {
        selectsort(v, N);
    }
    end_time = clock();
   printf("Tempo de execucao das k execucoes: %.6f segundos\n", (double)(end_time - start_time) / (CLOCKS_PER_SEC ));

    // Comb Sort
    printf("\nComb Sort:\n");
    populateRandomArray(v, N, max_value);
    start_time = clock();
    for (l = 0; l < K; l++) {
        combsort(v, N);
    }
    end_time = clock();
    printf("Tempo de execucao das k execucoes: %.6f segundos\n", (double)(end_time - start_time) / (CLOCKS_PER_SEC ));

    free(v);

    return 0;
}
