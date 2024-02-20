#include <iostream>
#include <new>
using namespace std;

struct dicionario{
    struct dados
    {
       int chave;
       string valor;
    };

    int n;
    int tam;
    dados *v;

    dicionario(){
        tam=1;
        v= new dados[tam];
        n=0;
    }
    
    ~dicionario(){
        delete[]v;
    }

    bool vazia(){
        return(n==0);
    }

    int consultar(int chave){
        for(int i=0;i<n;++i){
            if(v[i].chave==chave){
             cout << "O aluno de nome " << v[i].valor << " e matricula " << v[i].chave << " esta na posicao " << i << " do dicionario\n";
             return i;
            }
        }
        return -1;
    }

 void inserir(int mat , string texto){
        if (consultar(mat)!=-1) return;
        if (tam==n){
            tam=tam*2;
            dados *novo = new dados [tam];
            for (int i = 0;i<n;++i){
                novo[i].chave=v[i].chave;
                novo[i].valor=v[i].valor;
            }
            delete [] v;
            v=novo;
        }
        v[n].chave = mat;
        v[n].valor = texto;
        n++;
    }


   void remover(int chave) {
    int indice = consultar(chave);

    if (vazia()) {
        cout << "dicionario vazio, impossivel remover";
        return;
    }
    
    if (indice == -1) {
        cout << "a chave nao esta no dicionario";
        return;
    }

    if (n > 1 && n <= tam / 4) {
        tam = tam / 2;
    }

    dados *novo = new dados[tam];
    int j = 0; // Índice para o novo vetor

    // Copia todos os elementos diferentes da chave a ser removida para o novo vetor
    for (int i = 0; i < n; ++i) {
        if (v[i].chave != chave) {
            novo[j].chave = v[i].chave;
            novo[j].valor = v[i].valor;
            ++j; // Incrementa o índice do novo vetor apenas se o elemento for copiado
        }
    }

    delete[] v;
    v = novo;
    n--;
}

    
};

int main()
{
    dicionario dic;
    try{
        double num;
        while (true){
        cout << "----------------------Menu----------------------\n"
             << "Digite 1 para inserir elementos no dicionario\n"
             << "Digite 2 para remover elementos do dicionario\n"
             << "Digite 3 para consultar elementos do dicionario\n"
             << "Digite qualquer outro n�mero para finalizar\n";
        cout << "Digite ao lado -> ";
        cin >> num;
        if (num==1){
            double d;
            cout << "\nDigite a chave que deseja inserir (int): ";
            cin >> d;
            string t;
            cout << "\nDigite o nome que deseja inserir (string): ";
            cin >> t;
            dic.inserir(d,t);
        }
        else if (num==2){
            double d;
            cout << "\nDigite a chave do elemento que deseja remover (int): ";
            cin >> d;
            dic.remover(d);
        }
        else if (num==3){
            double d;
            cout << "\nDigite a chave do elemento que deseja consultar (int): ";
            cin >> d;
            d=dic.consultar(d);
            if (d==-1) cout << "Usuario nao encontrado no dicionario\n";
        }
        else{
            break;
        }
    }
    }
    catch (bad_alloc &e){
        cout << "Erro de alocacao\n";
    }
}
