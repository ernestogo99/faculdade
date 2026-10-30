#include "errorCalculator.h"

#include <cmath>
#include <stdexcept>

using namespace std;

double ErrorCalculator::absoluteError(
    double exactValue,
    double approximateValue
) {
    return fabs(exactValue - approximateValue);
}

double ErrorCalculator::relativeError(
    double exactValue,
    double approximateValue
) {
    if (exactValue == 0.0) {
        throw invalid_argument(
            "Nao e possivel calcular o erro relativo "
            "com valor exato igual a zero."
        );
    }

    return absoluteError(exactValue, approximateValue)
           / fabs(exactValue);
}

double ErrorCalculator::relativeErrorPercentage(
    double exactValue,
    double approximateValue
) {
    return relativeError(exactValue, approximateValue) * 100.0;
}

double ErrorCalculator::truncationErrorBound(
    int base,
    int precision
) {
    if (base <= 1) {
        throw invalid_argument(
            "A base deve ser maior que 1."
        );
    }

    if (precision <= 0) {
        throw invalid_argument(
            "A precisao deve ser maior que zero."
        );
    }

    return pow(base, 1 - precision);
}

double ErrorCalculator::roundingErrorBound(
    int base,
    int precision
) {
    if (base <= 1) {
        throw invalid_argument(
            "A base deve ser maior que 1."
        );
    }

    if (precision <= 0) {
        throw invalid_argument(
            "A precisao deve ser maior que zero."
        );
    }

    return 0.5 * pow(base, 1 - precision);
}