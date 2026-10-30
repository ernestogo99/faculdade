#ifndef ERROR_CALCULATOR_H
#define ERROR_CALCULATOR_H

using namespace std;

class ErrorCalculator {
public:
    static double absoluteError(
        double exactValue,
        double approximateValue
    );

    static double relativeError(
        double exactValue,
        double approximateValue
    );

    static double relativeErrorPercentage(
        double exactValue,
        double approximateValue
    );

    static double truncationErrorBound(
        int base,
        int precision
    );

    static double roundingErrorBound(
        int base,
        int precision
    );
};

#endif