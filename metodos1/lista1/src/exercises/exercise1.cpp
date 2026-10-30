#include "../../include/binaryConverter.h"

#include <iostream>

using namespace std;

void runExercise01() {
    int decimal = 27;

    cout << "========================================" << endl;
    cout << "           QUESTAO 1" << endl;
    cout << "========================================" << endl;

    cout << endl;
    cout << "a) Conversao de decimal para binario" << endl;

    string binary = BinaryConverter::decimalToBinary(decimal);

    cout << decimal << " (base 10) = "
         << binary << " (base 2)" << endl;

    cout << endl;
    cout << "b) Conversao de binario para decimal" << endl;

    int decimalByPosition =
        BinaryConverter::binaryToDecimalByPosition(binary);

    int decimalByPowers =
        BinaryConverter::binaryToDecimalByPowers(binary);

    cout << "Metodo das posicoes: "
         << decimalByPosition << endl;

    cout << "Metodo dos parenteses: "
         << decimalByPowers << endl;

    cout << endl;
    cout << "c) Verificacao dos resultados" << endl;

    bool positionCorrect = decimalByPosition == decimal;
    bool powersCorrect = decimalByPowers == decimal;

    cout << "Metodo das posicoes: "
         << (positionCorrect ? "correto" : "incorreto")
         << endl;

    cout << "Metodo dos parenteses: "
         << (powersCorrect ? "correto" : "incorreto")
         << endl;

    cout << endl;
}