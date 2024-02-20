#include <iostream>
using namespace std;
int main() {
    double x, y;
    double minX = 0.0, minY = 0.0, maxX = 0.0, maxY = 0.0;
    int i = 1;

    while (i <= 5) {
        cout << "Digite a coordenada x do ponto " << i << ": ";
        cin >> x;

        cout << "Digite a coordenada y do ponto " << i << ": ";
        cin >> y;

        if (x < minX) minX = x;
        if (x > maxX) maxX = x;
        if (y < minY) minY = y;
        if (y > maxY) maxY = y;

        i++;
    }

    double base = maxX - minX;
    double altura = maxY - minY;

    if (base > altura)
        cout << "Classificação do retângulo: largo." << std::endl;
    else if (altura > base)
        cout << "Classificação do retângulo: alto." << std::endl;
    else
        cout << "Classificação do retângulo: quadrado." << std::endl;

    return 0;
}