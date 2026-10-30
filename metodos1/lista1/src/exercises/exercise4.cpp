
#include "../../include/ErrorCalculator.h"

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void runExercise04() {
    const int base = 10;
    const int precision = 4;

    const double m = 10.0;
    const double n = 20.0;
    const double w = 40.0;
    const double o = 30.0;

    cout << "========================================" << endl;
    cout << "           QUESTAO 4" << endl;
    cout << "========================================" << endl;

    cout << fixed << setprecision(6);

    cout << endl;
    cout << "Expressao:" << endl;

    cout << "u = ((m + n) * w) / o" << endl;

    cout << endl;
    cout << "Valores:" << endl;

    cout << "m = " << m << endl;
    cout << "n = " << n << endl;
    cout << "w = " << w << endl;
    cout << "o = " << o << endl;

    /*
     * ============================================================
     * ITEM (a)
     * ============================================================
     *
     * Numeros representados com arredondamento.
     *
     * Cada numero possui erro relativo limitado por:
     *
     *     epsilon = 1/2 * 10^(-t + 1)
     *
     * A expressao possui tres operacoes:
     *
     *     s = m + n
     *     p = s * w
     *     u = p / o
     *
     * O erro e propagado a cada etapa.
     */

    cout << endl;
    cout << "a) Erro com arredondamento" << endl;

    double roundingError =
        ErrorCalculator::roundingErrorBound(
            base,
            precision
        );

    cout << "Erro relativo de cada representacao:" << endl;
    cout << "epsilon = "
         << roundingError
         << endl;

    /*
     * Primeira operacao:
     *
     * ER_s =
     * ER_m * (m / (m + n))
     * +
     * ER_n * (n / (m + n))
     * +
     * RA_1
     *
     * Para m = 10 e n = 20:
     *
     * m / (m + n) = 1/3
     * n / (m + n) = 2/3
     *
     * As duas contribuicoes somam epsilon.
     * O arredondamento da soma acrescenta mais epsilon.
     *
     * Portanto:
     *
     * |ER_s| < 2 * epsilon
     */

    double sumErrorBound =
        2.0 * roundingError;

    cout << endl;
    cout << "1) Soma: s = m + n" << endl;

    cout << "m / (m + n) = "
         << m / (m + n)
         << endl;

    cout << "n / (m + n) = "
         << n / (m + n)
         << endl;

    cout << "|ER_s| < "
         << sumErrorBound
         << endl;

    /*
     * Segunda operacao:
     *
     * ER_p = ER_s + ER_w + RA_2
     *
     * |ER_s| < 2 epsilon
     * |ER_w| < epsilon
     * |RA_2| < epsilon
     *
     * Portanto:
     *
     * |ER_p| < 4 epsilon
     */

    double multiplicationErrorBound =
        sumErrorBound
        + roundingError
        + roundingError;

    cout << endl;
    cout << "2) Multiplicacao: p = s * w" << endl;

    cout << "|ER_p| < "
         << multiplicationErrorBound
         << endl;

    /*
     * Terceira operacao:
     *
     * ER_u = ER_p - ER_o + RA_3
     *
     * Para obter um limite superior:
     *
     * |ER_u| <
     * |ER_p| + |ER_o| + |RA_3|
     *
     * |ER_p| < 4 epsilon
     * |ER_o| < epsilon
     * |RA_3| < epsilon
     *
     * Portanto:
     *
     * |ER_u| < 6 epsilon
     */

    double totalRoundingErrorBound =
        multiplicationErrorBound
        + roundingError
        + roundingError;

    cout << endl;
    cout << "3) Divisao: u = p / o" << endl;

    cout << "|ER_u| < "
         << totalRoundingErrorBound
         << endl;

    cout << endl;
    cout << "Limite final do erro relativo:" << endl;

    cout << "|ER_u| < "
         << totalRoundingErrorBound
         << endl;

   

    /*
     * ============================================================
     * ITEM (b)
     * ============================================================
     *
     * Agora os numeros sao considerados exatos e usamos
     * truncamento nas tres operacoes.
     *
     * Para truncamento:
     *
     *     |RT| < 10^(-t + 1)
     *
     * Como temos tres operacoes:
     *
     *     |ER_s| < RT
     *     |ER_p| < 2 RT
     *     |ER_u| < 3 RT
     */

    cout << endl;
    cout << "b) Erro com truncamento" << endl;

    double truncationError =
        ErrorCalculator::truncationErrorBound(
            base,
            precision
        );

    cout << "Erro relativo de cada operacao:" << endl;
    cout << "RT = "
         << truncationError
         << endl;

    double truncationSumErrorBound =
        truncationError;

    double truncationMultiplicationErrorBound =
        truncationSumErrorBound
        + truncationError;

    double totalTruncationErrorBound =
        truncationMultiplicationErrorBound
        + truncationError;

    cout << endl;
    cout << "1) Soma: s = m + n" << endl;

    cout << "|ER_s| < "
         << truncationSumErrorBound
         << endl;

    cout << endl;
    cout << "2) Multiplicacao: p = s * w" << endl;

    cout << "|ER_p| < "
         << truncationMultiplicationErrorBound
         << endl;

    cout << endl;
    cout << "3) Divisao: u = p / o" << endl;

    cout << "|ER_u| < "
         << totalTruncationErrorBound
         << endl;

    cout << endl;
    cout << "Limite final do erro relativo:" << endl;

    cout << "|ER_u| < "
         << totalTruncationErrorBound
         << endl;

   

    /*
     * ============================================================
     * ITEM (c)
     * ============================================================
     *
     * Calculamos o valor exato da expressao utilizando os valores:
     *
     *     m = 10
     *     n = 20
     *     w = 40
     *     o = 30
     */

    cout << endl;
    cout << "c) Valor da expressao" << endl;

    double exactValue =
        ((m + n) * w) / o;

    cout << "u = "
         << exactValue
         << endl;

    cout << endl;
}

