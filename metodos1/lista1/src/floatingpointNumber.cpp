#include "floatingPointNumber.h"
#include "floatingPointSystem.h"

#include <cmath>
#include <stdexcept>

using namespace std;

FloatingPointNumber::FloatingPointNumber(double exactValue) {
    this->exactValue = exactValue;
}
    
double FloatingPointNumber::getExactValue() const {
    return exactValue;
}

int FloatingPointNumber::getExponent(
    const FloatingPointSystem& system
) const {
    if (exactValue == 0.0) {
        throw invalid_argument(
            "O numero zero nao possui expoente normalizado."
        );
    }

    double value = fabs(exactValue);

    return static_cast<int>(
        floor(log(value) / log(system.getBase()))
    ) + 1;
}

double FloatingPointNumber::fx(
    const FloatingPointSystem& system
) const {
    if (exactValue == 0.0) {
        return 0.0;
    }

    int exponent = getExponent(system);

    double normalized =
        fabs(exactValue) /
        pow(system.getBase(), exponent);

    double factor =
        pow(system.getBase(), system.getPrecision());

    return floor(normalized * factor) / factor;
}

double FloatingPointNumber::gx(
    const FloatingPointSystem& system
) const {
    if (exactValue == 0.0) {
        return 0.0;
    }

    int exponent = getExponent(system);

    double fxValue = fx(system);

    double residual =
        fabs(exactValue) -
        fxValue * pow(system.getBase(), exponent);

    return residual /
           pow(
               system.getBase(),
               exponent - system.getPrecision()
           );
}

double FloatingPointNumber::truncate(
    const FloatingPointSystem& system
) const {
    if (exactValue == 0.0) {
        return 0.0;
    }

    int exponent = getExponent(system);

    double result =
        fx(system) *
        pow(system.getBase(), exponent);

    return exactValue < 0 ? -result : result;
}

double FloatingPointNumber::round(
    const FloatingPointSystem& system
) const {
    if (exactValue == 0.0) {
        return 0.0;
    }

    int exponent = getExponent(system);

    double normalized =
        fabs(exactValue) /
        pow(system.getBase(), exponent);

    double factor =
        pow(system.getBase(), system.getPrecision());

    double roundedMantissa =
        std::round(normalized * factor) / factor;

    if (roundedMantissa >= 1.0) {
        roundedMantissa /= system.getBase();
        exponent++;
    }

    double result =
        roundedMantissa *
        pow(system.getBase(), exponent);

    return exactValue < 0 ? -result : result;
}