#ifndef FLOATING_POINT_NUMBER_H
#define FLOATING_POINT_NUMBER_H

class FloatingPointSystem;

using namespace std;

class FloatingPointNumber {
private:
    double exactValue;

public:
    explicit FloatingPointNumber(double exactValue);

    double getExactValue() const;

    int getExponent(
        const FloatingPointSystem& system
    ) const;

    double fx(
        const FloatingPointSystem& system
    ) const;

    double gx(
        const FloatingPointSystem& system
    ) const;

    double truncate(
        const FloatingPointSystem& system
    ) const;

    double round(
        const FloatingPointSystem& system
    ) const;
};

#endif