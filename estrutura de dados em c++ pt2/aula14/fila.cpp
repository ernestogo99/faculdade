#include <iostream>
#include <stdlib.h>
#include <new>
using namespace std;
struct Fila{
    int tam_vet, quant, inicio, fim, *v;
    Fila(){  
        quant = 0;
        tam_vet = 1;
        inicio = 0;
        fim = 0;
        v = new int[tam_vet];
    }
    void inserir(int valor){
        if (tam_vet == quant){
            int novo_tam = tam_vet * 2;
            int *w = new int[novo_tam];
            for(int i=0; i<quant; i++) w[i] = v[i];
            delete[] v; v=w;
            tam_vet=novo_tam;
        }
        else if(fim == tam_vet){
            fim = 0;
        }
        v[fim] = valor;
        fim++;
        quant++;      
    }
    void remover(){
        if (quant == 0){
            cout << "Erro: Fila sem elementos" <<endl;
           
        }
        else {inicio++; quant--;}
    }
    int printar(){
      
        if (quant == 0){
            cout << "Erro: Fila sem elementos";
            return 2;
        }
        cout << "A fila eh:" << endl;
        if (fim>inicio){
            for(int i=inicio; i<fim; i++){
                cout << v[i] << endl;
            }
        }
        else{
               
            for (int i = inicio; i < tam_vet; i++){         
                 cout << v[i] << endl;
                 i++;
            }
            for (int i=0; i<fim; i++){
                cout << v[i] <<endl;
            }
            return 3;
        }
                   
    }
};

int main(int argc, char *argv[])
{
	Fila f;
	
   
    while(true){
        char acao;
        cout << " R: remover \n S: Inserir \n P: Printar" << endl;
	    cin >> acao;
	    if (acao == 'R'){
	        
	        f.remover();
	    }
	    else if (acao == 'S'){
	        int valor;
	        cout << " \n Digite um valor a ser inserido: ";
	        cin >> valor;
	        f.inserir(valor);
	    }
	    else if (acao == 'P'){
	        f.printar();
	    }
    }
}