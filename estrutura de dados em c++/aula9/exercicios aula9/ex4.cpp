#include <iostream>
using namespace std;

char *substring(const char *s, int ini, int fim)
{
    int tam = 0;
    while (s[tam] != 0)
        ++tam;

    int novotam = fim - ini + 1;
    char *novo = new char[novotam + 1];
    
    for(int i=0;i<fim;++i){
        novo[i]=s[ini+i];
    }
    
    novo[novotam] = '\0';

    return novo;
}

int main()
{
    cout << "digite o inicio: \n";
    cout << "digite o final: \n";
    int ini, fim;
    cin >> ini;
    cin >> fim;
    while (fim < ini)
    {
        cout << "digite novamente os numeros(fim>inicio para ficar tudo certo)\n";
    cout << "digite o inicio: \n";
    cout << "digite o final: \n";
    
    cin >> ini;
    cin >> fim;
    }
   
    cout << "parte de uma string";
    cout << endl;
    char *novo = substring("parte de uma string", ini, fim);
    cout << novo;
}