#include <iostream>
#include <new>
using namespace std;

struct matriz{ // ou class matriz ,struct: tudo public por padrao,class:tudo private por padrao
    private:
    double*v;
    int m;   // numero de linhas
    int  n;   // numero de colunas

    public:
    matriz(int num_linhas,int num_cols){
        cout<<"construtor\n";
        v=new double[num_linhas*num_cols]();
        m=num_linhas;
        n=num_cols;

    }

    ~matriz(){
        cout<<"destrutor\n";
        delete []v;
    }

    int num_linhas(){
        return m;
    }

    int num_colunas(){
        return n;
    }

    double &operator()(int linha,int coluna){
        return v[linha*n + coluna];
       
    }

    
};
// nao desejo copia
void imprimir(matriz &m){ 
    for(int l=0;l<m.num_linhas();++l){
        cout<<"[";
        for(int c=0;c<m.num_colunas();++c){
            cout<<" "<<m(l,c);
        }
        cout<<endl;
    }

}

int main(){
    try{
        matriz m(3,3);
        cout<<"inicio (sem inicializacao ):\n";
        imprimir(m);

        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                m(i,j)= 1+ i*3 +j;
            }
        }

        cout<<"\n apos atribuicoes:\n";
        imprimir(m);
    }
    catch(const bad_alloc &e){
        cout<<"erro: falha de alocacao de memoria";
        return 1;
    }
}


