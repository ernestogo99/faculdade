#include <iostream>
#include <new>
using namespace std;
struct minha_string{
    private: // não acessivel fora da struct
    char *s; 
    int tam; //tamanho (numero de posições de s)
    public: // acessivel fora da struct
    minha_string(){
        tam =1;
        cout<<"construtor";
        s=new char[tam];
        s[0]=0; //*s=0

    }

    void copiar(const char *origem){
        int tam_origem=0;
        int i=0; while(origem[i]!=0) ++i;
        tam_origem=i;
        // ou usar srtlen(origem) de <cstring>
        if(tam<tam_origem+1){
            delete[]s;
            tam=tam_origem+1;
            s=new char[tam];
        }
        for(i=0;i<tam_origem;++i) s[i]=origem[i];
    }

    // char_acessarelemento(int i ){return s[i];}

    char operator[](int i){
        return s[i];
    }
    ~minha_string(){
        delete[]s;
        cout<<"destrutor\n";
        
    }


}; // struct minha string

void imprimir(minha_string &texto){
    cout<<endl;
    cout<<"texto: [";
    for(int i=0;texto[i]!=0;++i){
        cout<<texto[i];
    }

    cout<<endl;
}

int main(){
    try{
        minha_string texto;

        imprimir(texto);
        texto.copiar("uma string qualquer...");
        imprimir(texto);
    }
    catch(const bad_alloc &e){
        cout<<"erro,falta de memoria";
        return 1;
    }
}
