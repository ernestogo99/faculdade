#include <iostream>
#include <new>
#include <cstring>
#include <string>
using namespace std;

struct errofila{
    const char *msg;

    errofila(const char *msg_erro){
        msg=msg_erro;
    }

    const char *mensagem()const{
        return msg;
    }
};

struct cliente{
    char nome[250];
    float valor;
    int conta;

    cliente(){
        valor=0.0;
        conta=-1;
        nome[0]='\0';
    }

};

 void strcpy_custom(char *dest, const char *src) {
    // Copiar caractere por caractere até encontrar o caractere nulo que indica o final da string
    while (*src != '\0') {
        *dest = *src;
        ++dest;
        ++src;
    }
    // Adicionar o caractere nulo ao final da string de destino
    *dest = '\0';
}

struct fila{
    int tam;
    cliente *v;
    int prim,ult;


    fila(){
        tam=1;
        v=new cliente[tam];
        prim=-1;
    }
    ~fila(){
        delete[]v;
    }

    void avancar(int &indice){
        if(indice==tam-1){
            indice=0;
        }
        else{
            ++indice;
        }
    }

    bool vazia(){
        return prim==-1;
    }

 

  int enfileirar(char nome[250], int conta, float valor) {
        if ((prim == 0 and ult == tam - 1) or (ult + 1 == prim)) {
            // Fila cheia, redimensione a fila
            int novo_tam = tam * 2;
            cliente *w = new cliente[novo_tam];
            for (int i = 0, j = prim; i<tam; ++i) {
                w[i] = v[j];
                avancar(j);
            }
            delete[] v;
            v = w;
            prim = 0;
            ult = tam-1;
            tam = novo_tam;
        }

        if (vazia()) {
            prim = 0;
            ult = 0;
        } else {
            avancar(ult);
        }

        strcpy_custom(v[ult].nome, nome);
        v[ult].conta = conta;
        v[ult].valor = valor;
        return 1; // Inserção bem-sucedida
    }

    string consulta_nome(){
        if(vazia()){
            throw errofila("erro,fila vazia");
        }
        return v[prim].nome;
    }

    float consulta_valor(){
        if(vazia()){
            throw errofila("erro,fila vazia");
        }
        return v[prim].valor;
    }

    int consulta_conta(){
        if(vazia()){
            throw errofila("erro,fila vazia");
        }
        return v[prim].conta;
    }

    void desenfilar(){
        if(vazia()){
            throw errofila("erro,fila vazia");
        }
        if(prim==ult){
            prim=-1;
        }
        else{
            avancar(prim);
        }

    }


};

int main(){
    try{
        fila f;
        cout<<"clientes chegando no banco e se cadastrando para o atendimento\n";

        char cliente1[]="cliente 1";
        f.enfileirar(cliente1,100.0,541803);

        char cliente2[]="cliente 2";
        f.enfileirar(cliente2,150.0,531090);

        char cliente3[]="cliente 3";
        f.enfileirar(cliente3,180.0,591829);

        while(not f.vazia()){
            cout<<"proximo cliente da fila\n";
            cout<<"nome: "<<f.consulta_nome()<<endl;
            cout<<"valor: "<<f.consulta_valor()<<endl;
            cout<<"conta: "<<f.consulta_conta()<<endl;
            cout<<"atendendo\n";
            f.desenfilar();

            if(f.vazia()){
                cout<<"fila do banco vazia\n";
            }


        }

    }
    catch(const bad_alloc &e){
        cout<<"erro,falha na alocacao de memoria";
        return 1;
    }
    catch(const errofila &e){
        cout<<e.mensagem()<<'\n';
        return 2;
    }
   
}