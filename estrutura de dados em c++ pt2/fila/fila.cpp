#include <iostream>
#include <new>
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
    int  conta;
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
    int ini,fim;

    fila(){
        tam=1;
        v=new cliente[tam];
        ini=-1;
    }
    ~fila(){
        delete[]v;
    }

    bool vazia(){
        return ini==-1;
    }

    void avancar(int &indice){
        if(indice==tam-1){
            indice=0;
        }
        ++indice;
    }

    void strcpy(char *a,char *b){
        while(*b!='\0'){
            *a=*b;
            ++a;
            ++b;
        }
        *a='\0';
    }

    void enfileirar(char nome[250],int conta,float valor){
        if((ini==0 and fim==tam-1) or (fim+1==ini)){
            tam=tam*2;
            cliente *w=new cliente[tam];
            for(int i=0,j=ini;i<tam;++i){
                w[i]=v[j];
                avancar(j);
            }
            delete[]v;
            v=w;
            ini=0;
            fim=tam-1;
        }
        if(vazia()){
            ini=0;
            fim=0;
        }
        else{
            avancar(fim);
        }
        strcpy(v[fim].nome,nome);
        v[fim].conta=conta;
        v[fim].valor=valor;
        
    }

    void desinfileirar(){
        if(vazia()){
            throw errofila("erro,fila vazia");
        }
        if(ini==fim){
            ini=-1;
        }
        else{
            avancar(ini);
        }
    }

    string consulta_nome(){
        if(vazia()){
            throw errofila("erro,fila vazia");
        }
        else{
            return v[ini].nome;
        }
    }
    float consulta_valor(){
        if(vazia()){
            throw errofila("erro,fila vazia");
        }
        return v[ini].valor;
    }

    int consulta_conta(){
        if(vazia()){
            throw errofila("erro,fila vazia");
        }
        return v[ini].conta;
    }


};
int main() {
    try {
        fila banco;

        cout << "Clientes chegando no banco e se cadastrando para atendimento:\n";

        // Exemplo de inserção de clientes
        char cliente1_nome[] = "Cliente 1";
        banco.enfileirar(cliente1_nome, 12345, 100.0);

        char cliente2_nome[] = "Cliente 2";
        banco.enfileirar(cliente2_nome, 54321, 200.0);

        char cliente3_nome[] = "Cliente 3";
        banco.enfileirar(cliente3_nome, 67890, 50.0);

        while (!banco.vazia()) {
            cout << "Proximo cliente da fila:\n";
            cout << "Nome: " << banco.consulta_nome() << endl;
            cout << "Conta: " << banco.consulta_conta() << endl;
            cout << "Valor a sacar: " << banco.consulta_valor() << endl;
            cout << "Atendendo...\n";
            banco.desinfileirar();
        }

        if (banco.vazia()) {
            cout << "Fila do banco vazia.\n";
        }

    } catch (const bad_alloc &e) {
        cout << "Falha de alocação de memória.\n";
        return 1;
    } catch (const errofila &e) {
        cout << e.mensagem() << '\n';
        return 2;
    }

    return 0;
}
