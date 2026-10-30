#ifndef FLOATING_POINT_SYSTEM_H
#define FLOATING_POINT_SYSTEM_H

using namespace std;

class FloatingPointSystem {
private:
    int base;
    int precision;
    int minExponent;
    int maxExponent;

public:
    FloatingPointSystem(
        int base,
        int precision,
        int minExponent,
        int maxExponent
    );

    int getBase() const;
    int getPrecision() const;
    int getMinExponent() const;
    int getMaxExponent() const;

    double getMinMantissa() const;
    double getMaxMantissa() const;

    double getMinNumber() const;
    double getMaxNumber() const;
};

#endif