#include "../../include/floatingPointSystem.h"
#include "../../include/floatingPointNumber.h"
#include "../../include/errorCalculator.h"

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void runExercise03() {
    FloatingPointSystem system(
        10,
        4,
        -5,
        5
    );

    FloatingPointNumber number(357.26);

    cout << "========================================" << endl;
    cout << "           QUESTAO 3" << endl;
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

    cout << "Expoente minimo: "
         << system.getMinExponent()
         << endl;

    cout << "Expoente maximo: "
         << system.getMaxExponent()
         << endl;

    cout << endl;
    cout << "a) Representacao de 357.26" << endl;

    int exponent =
        number.getExponent(system);

    double fx =
        number.fx(system);

    double gx =
        number.gx(system);

    cout << "f(x) = "
         << fx
         << endl;

    cout << "g(x) = "
         << gx
         << endl;

    cout << "e = "
         << exponent
         << endl;

    cout << endl;

    cout << "Representacao:" << endl;

    cout << fx
         << " x 10^"
         << exponent
         << " + "
         << gx
         << " x 10^"
         << exponent - system.getPrecision()
         << endl;

    cout << endl;
    cout << "Verificacao:" << endl;

    double reconstructed =
        fx * pow(system.getBase(), exponent)
        +
        gx * pow(
            system.getBase(),
            exponent - system.getPrecision()
        );

    cout << reconstructed
         << endl;

    cout << endl;
    cout << "b) Truncamento" << endl;

    double truncated =
        number.truncate(system);

    double truncationAbsoluteError =
        ErrorCalculator::absoluteError(
            number.getExactValue(),
            truncated
        );

    double truncationRelativeError =
        ErrorCalculator::relativeError(
            number.getExactValue(),
            truncated
        );

    cout << "Valor truncado: "
         << truncated
         << endl;

    cout << "Erro absoluto: "
         << truncationAbsoluteError
         << endl;

    cout << "Erro relativo: "
         << truncationRelativeError
         << endl;

    cout << "Limite teorico do erro relativo: "
         << ErrorCalculator::truncationErrorBound(
                system.getBase(),
                system.getPrecision()
            )
         << endl;

    cout << endl;
    cout << "c) Arredondamento" << endl;

    double rounded =
        number.round(system);

    double roundingAbsoluteError =
        ErrorCalculator::absoluteError(
            number.getExactValue(),
            rounded
        );

    double roundingRelativeError =
        ErrorCalculator::relativeError(
            number.getExactValue(),
            rounded
        );

    cout << "Valor arredondado: "
         << rounded
         << endl;

    cout << "Erro absoluto: "
         << roundingAbsoluteError
         << endl;

    cout << "Erro relativo: "
         << roundingRelativeError
         << endl;

    cout << "Limite teorico do erro relativo: "
         << ErrorCalculator::roundingErrorBound(
                system.getBase(),
                system.getPrecision()
            )
         << endl;

    cout << endl;
}