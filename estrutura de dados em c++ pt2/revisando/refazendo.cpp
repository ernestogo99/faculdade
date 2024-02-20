#include <iostream>
#include <new>
#include <cstring>
using namespace std;

struct errofila{
    const char* msg;
    errofila(const char *msg_erro){
        msg=msg_erro;
    }

    const char* mensagem()const{
        return msg;
    }
};

struct cliente{
    char nome[250];
    int conta;
    float valor;

    cliente(){
        conta=-1;
        valor=0.0;
        nome[0]='\0';
    }
};

struct fila{
    int tam;
    cliente *v;
    int prim,ult;

    void avancar(int &indice){
        if(indice==tam-1){
            indice=0;
        }
        else{
            ++indice;
        }
    }

    fila(){
        tam=1;
         v=new cliente[tam];
        prim=-1;
       
    }
    ~fila(){
        delete[]v;
    }

    bool vazia(){
        return (prim==-1);
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

        strcpy(v[ult].nome, nome);
        v[ult].conta = conta;
        v[ult].valor = valor;
        return 1; // Inserção bem-sucedida
    }


    int consulta_valor_proximo(){
        if(vazia()){
            throw errofila("erro,fila vazia");
        }
        return v[prim].valor;
    }

    float consulta_conta_proximo(){
        if(vazia()){
            throw errofila("erro,fila vazia");
        }
        return v[prim].conta;
    }

    void desinfileirar(){
        if(vazia()){
            throw errofila("erro, fila vazia");
        }

        if(prim==ult){
            prim=-1;
        }
        else{
            avancar(prim);
        }
    }

    string nome_proximo(){
        if(vazia()){
            throw errofila("erro,fila vazia");
        }
        return v[prim].nome;
    }
};

int main(){
    try{
        fila banco;

        cout<<" clientes se cadastrando para atendimento \n";

         char cliente1_nome[] = "Cliente 1";
        banco.enfileirar(cliente1_nome, 12345, 100.0);

        char cliente2_nome[] = "Cliente 2";
        banco.enfileirar(cliente2_nome, 54321, 200.0);

        char cliente3_nome[] = "Cliente 3";
        banco.enfileirar(cliente3_nome, 67890, 50.0);

        while(!banco.vazia()){
            cout<<"proximo cliente da fila \n";
            cout<<"nome: "<<banco.nome_proximo()<<endl;
            cout<<"conta: "<<banco.consulta_conta_proximo()<<endl;
            cout<<"valor: "<<banco.consulta_valor_proximo()<<endl;
            cout<<"atendendo \n";
            banco.desinfileirar();
        }
    }
    catch(const bad_alloc &e){
        cout<<"falha de alocação da memoria";
        return 1;
    }
    catch(const errofila &e){
        cout<<e.mensagem()<<'\n';
        return 2;
    }
}   
