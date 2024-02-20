#include <stdlib.h>
#include <stdio.h>

void str_copia(char *s, char *d) {
    while (*s != '\0') {
        *d = *s;
        s++;
        d++;
    }
    *d = '\0';
}

void str_concatena (char *s, char *d){
    int i = 0, j = 0;
    //Vai até a posição final do vetor s
    while(s[i] != '\0'){
        i++;
    }
    //Adiciona o conteudo de d no fim do vetor s
    while(d[j] != '\0'){
        s[i + j] = d[j];
        j++;
    }
}

int str_tamanho (char *s){
    int i = 0;
    while(s[i] != '\0')
        i++;
    
    return i;
}

int converte_centenas(int *valor, int i, char nome[][15], char numextenso[][1024]){
    int tam, continua = 1, aux;
    
    if(*valor == 100){
        str_copia(&nome[30][0], &numextenso[i][0]);
        continua = 0;
    }
    else{
        aux = (int) (*valor / 100);
        *valor = *valor - (aux * 100);
        
        str_copia(&nome[30 + aux][0], &numextenso[i][0]);
        
        if(*valor == 0)
            continua = 0;
        else{
            tam = str_tamanho(&numextenso[i][0]);
            str_copia(&nome[40][0], &numextenso[i][tam]); //Conectivo E
            }
        }
        
	return continua;
}

int converte_dezenas(int *valor, int i, char nome[][15], char numextenso[][1024]){
    int aux, continua = 1, tam;
    
    aux = (int) (*valor / 10);
    *valor = *valor - (aux * 10);
    
    tam = str_tamanho(&numextenso[i][0]);
    if(*valor + (aux * 10) <= 19){
        str_copia(&nome[10 + *valor][0], &numextenso[i][tam]);
        continua = 0;
    }
    else
        str_copia(&nome[20 + aux][0], &numextenso[i][tam]);
    
    if(*valor == 0){
        continua = 0;
    }
    else if(continua != 0){
        tam = str_tamanho(&numextenso[i][0]);
        str_copia(&nome[40][0], &numextenso[i][tam]); //Conectivo E
    }
    return continua;
}

void converte_unidades(int *valor, int i, char nome[][15], char numextenso[][1024]){
    int tam;

    tam = str_tamanho(&numextenso[i][0]);
    str_copia(&nome[*valor][0], &numextenso[i][tam]);
}


int main(int narg, char *argv[]){
	char num[3], numextenso[1000][1024];
	FILE *arq;
	int valor, i = 0, continua = 1, j;

	char ext[42][15] = {"ZERO", "UM", "DOIS", "TRES", "QUATRO", "CINCO", "SEIS", "SETE", "OITO", "NOVE", \
            "DEZ", "ONZE", "DOZE", "TREZE", "CATORZE", "QUINZE", "DEZESSEIS", "DEZESSETE", "DEZOITO", "DEZENOVE", \
            "---", "---", "VINTE", "TRINTA", "QUARENTA", "CINQUENTA", "SESSENTA", "SETENTA","OITENTA", "NOVENTA", \
            "CEM", "CENTO", "DUZENTOS", "TREZENTOS", "QUATROCENTOS", "QUINHENTOS", "SEISSENTOS", "SETECENTOS", "OITOCENTOS", "NOVECENTOS", \
            " E " }; 

	if(narg == 1){
		arq = NULL;
		printf("Informe um valor inteiro (1 ≤ N ≤ 999): ");
		fgets(num, 4, stdin);

		valor = atoi(num);
		if(valor >= 100)
			continua = converte_centenas(&valor, i, ext, numextenso);
        	if(valor < 100 && valor >= 10)
        		continua = converte_dezenas(&valor, i, ext, numextenso);
        	if(valor <= 9 && valor != 0 && continua != 0)
            		converte_unidades(&valor, i, ext, numextenso);
	}
	else
		arq = fopen(argv[1], "r");

	while(arq != NULL && fgets(num, 4, arq) != NULL){
		valor = atoi(num);
		if(valor >= 100)
		    	continua = converte_centenas(&valor, i, ext, numextenso);
        	if(valor < 100 && valor >= 10 && continua != 0)
        		continua = converte_dezenas(&valor, i, ext, numextenso);
        	if(valor <= 9 && valor != 0 && continua != 0)
            		converte_unidades(&valor, i, ext, numextenso);

		i++;
	}
	
	for(j = 0; j <= i; j++){
		printf("\n\t%s", &numextenso[j][0]);
	}
	printf("\n");

    return EXIT_SUCCESS;
}

