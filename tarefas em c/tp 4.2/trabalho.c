#include <stdlib.h>
#include <stdio.h>
#include "cadeia.h"


void numeroPorExtenso(int numero, char *extenso) {
    
    char *unidades[] = {"Zero", "Um", "Dois", "Tres", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove"};
    char *dezAVinte[] = {"Dez", "Onze", "Doze", "Treze", "Catorze", "Quinze", "Dezesseis", "Dezessete", "Dezoito", "Dezenove"};
    char *dezenas[] = {"", "", "Vinte", "Trinta", "Quarenta", "Cinquenta", "Sessenta", "Setenta", "Oitenta", "Noventa"};
    char *centenas[] = {"", "Cento", "Duzentos", "Trezentos", "Quatrocentos", "Quinhentos", "Seiscentos", "Setecentos", "Oitocentos", "Novecentos"};

    
    if (numero >= 1 && numero <= 9) {
        str_concatena(unidades[numero], extenso);
    } else if (numero >= 10 && numero <= 19) {
        str_concatena(dezAVinte[numero - 10], extenso);
    } else if (numero >= 20 && numero <= 99) {
        int dezena = numero / 10;
        int unidade = numero % 10;
        str_concatena(dezenas[dezena], extenso);
        if (unidade > 0) {
            str_concatena(" e ", extenso);
            str_concatena(unidades[unidade], extenso);
        }
    } else if (numero >= 100 && numero <= 999) {
        int centena = numero / 100;
        int resto = numero % 100;
        str_copia(centenas[centena], extenso);
        if (resto > 0) {
            str_concatena(" e ", extenso);
            numeroPorExtenso(resto, extenso);
        }
    }
}

int main(int narg, char *argv[]){
    int num;
    const int MAX_LEN = 1024;
    const int MAX_NUM = 1000;
    char numextenso[MAX_NUM][MAX_LEN];
    
    if (narg == 1) {
        
        printf("Entre um numero no intervalo fechado de 1 a 999: ");
        scanf("%d", &num);
        if (num < 1 || num > 999) {
            printf("Numero fora do intervalo valido.\n");
            return 1;
        }
        numeroPorExtenso(num, numextenso[0]);
        printf("%s\n", numextenso[0]);
    } else if (narg == 2) {
        
        FILE *arquivo = fopen(argv[1], "r");
        if (arquivo == NULL) {
            printf("Nao foi possivel abrir o arquivo.\n");
            return 1;
        }
        int linha = 0;
        
        while (fscanf(arquivo, "%d", &num) != EOF && linha < MAX_NUM) {
            numeroPorExtenso(num, numextenso[linha]);
            printf("%s\n", numextenso[linha]);
            linha++;
        }
     
        fclose(arquivo);
    } else {
        printf("Uso incorreto. Use: %s [nome_do_arquivo]\n", argv[0]);
        return 1;
    }
    




    return 0;
}