#include "../../include/floatingPointSystem.h"
#include "../../include/floatingPointNumber.h"
#include "../../include/errorCalculator.h"

#include <iostream>
#include <iomanip>

using namespace std;

void runExercise02() {
    FloatingPointSystem system(
        10,
        4,
        -5,
        5
    );

    FloatingPointNumber number(357.26);

    cout << "========================================" << endl;
    cout << "           QUESTAO 2" << endl;
    cout << "========================================" << endl;

    cout << fixed << setprecision(4);

    cout << endl;
    cout << "Sistema de ponto flutuante:" << endl;

    cout << "Base: "
         << system.getBase()
         << endl;

    cout << "Precisao: "
         << system.getPrecision()
         << endl;

    cout << "Menor expoente: "
         << system.getMinExponent()
         << endl;

    cout << "Maior expoente: "
         << system.getMaxExponent()
         << endl;

    cout << endl;
 cout << "a) Menor e maior numero representavel" << endl;

cout << "m = "
     << system.getMinMantissa()
     << " x 10^"
     << system.getMinExponent()
     << endl;

cout << "M = "  
     << system.getMaxMantissa()
     << " x 10^"
     << system.getMaxExponent()
     << endl;

    cout << endl;
    cout << "b) Representacao de 100.000" << endl;

    double value = 100.000;

    cout << "Valor: "
         << value
         << endl;

    cout << "Representavel: "
         << "nao"
         << endl;

    cout << "Motivo: o expoente necessario e 6, "
         << "mas o sistema permite expoente ate 5, assim causando um overflow"
         << endl;

    cout << endl;
    cout << "c) Representacao de 357.26 com arredondamento"
         << endl;

    double rounded = number.round(system);

    cout << "357.26 -> "
         << rounded
         << endl;

    cout << endl;
    cout << "d) Representacao de 357.26 com truncamento"
         << endl;

    double truncated = number.truncate(system);

    cout << "357.26 -> "
         << truncated
         << endl;

    cout << endl;
    cout << "e) Erros" << endl;

    double absoluteError =
        ErrorCalculator::absoluteError(
            rounded,
            truncated
        );

    double relativeError =
        ErrorCalculator::relativeError(
            rounded,
            truncated
        );

    double relativeErrorPercentage =
        ErrorCalculator::relativeErrorPercentage(
            rounded,
            truncated
        );

    cout << "Valor considerado exato: "
         << rounded
         << endl;

    cout << "Valor considerado aproximado: "
         << truncated
         << endl;

    cout << "Erro absoluto: "
         << absoluteError
         << endl;

    cout << "Erro relativo: "
         << relativeError
         << endl;
    cout << endl;
}