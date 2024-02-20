#include <iostream>
using namespace std;

int main()
{
    int matriz[3][4]; // 3 linhas e 4 colunas
    int l, c;

    for (l = 0; l < 3; ++l)
    {
        cout << "digite os elementos da matriz  " << endl;
        cout << endl;
        cout << "linha  [" << l << "]" << endl;
        cout << endl;
        for (c = 0; c < 4; ++c)
        {

            cout << "coluna [" << c << "]" << endl;
            cin >> matriz[l][c];
        }
    }

    for (l = 0; l < 3; ++l)
    {
        for (c = 0; c < 4; ++c)
        {
            cout << matriz[l][c] << " ";
        }
        cout << endl;
    }
}