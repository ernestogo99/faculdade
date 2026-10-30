#include "floatingPointSystem.h"

#include <cmath>
#include <stdexcept>

using namespace std;

FloatingPointSystem::FloatingPointSystem(
    int base,
    int precision,
    int minExponent,
    int maxExponent
) {
    if (base < 2) {
        throw invalid_argument(
            "A base deve ser maior ou igual a 2."
        );
    }

    if (precision <= 0) {
        throw invalid_argument(
            "A precisao deve ser maior que zero."
        );
    }

    if (minExponent > maxExponent) {
        throw invalid_argument(
            "O menor expoente nao pode ser maior que o maior expoente."
        );
    }

    this->base = base;
    this->precision = precision;
    this->minExponent = minExponent;
    this->maxExponent = maxExponent;
}



int FloatingPointSystem::getBase() const {
    return base;
}

int FloatingPointSystem::getPrecision() const {
    return precision;
}

double FloatingPointSystem::getMinMantissa() const {
    return 1.0 / base;
}

double FloatingPointSystem::getMaxMantissa() const {
    return 1.0 - pow(base, -precision);
}

int FloatingPointSystem::getMinExponent() const {
    return minExponent;
}

int FloatingPointSystem::getMaxExponent() const {
    return maxExponent;
}

double FloatingPointSystem::getMinNumber() const {
    return getMinMantissa() *
           pow(base, minExponent);
}

double FloatingPointSystem::getMaxNumber() const {
    return getMaxMantissa() *
           pow(base, maxExponent);
}