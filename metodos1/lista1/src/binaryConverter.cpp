#include "binaryConverter.h"
#include <algorithm>
#include <cmath>
#include <stdexcept>

using namespace std;

bool BinaryConverter::isValidBinary(const string& binary) {
    if (binary.empty()) {
        return false;
    }

    for (char bit : binary) {
        if (bit != '0' && bit != '1') {
            return false;
        }
    }

    return true;
}

string BinaryConverter::decimalToBinary(int decimal) {
    if (decimal < 0) {
        throw invalid_argument(
            "O numero decimal deve ser maior ou igual a zero."
        );
    }

    if (decimal == 0) {
        return "0";
    }

    string binary;

    while (decimal > 0) {
        int remainder = decimal % 2;

        binary.push_back('0' + remainder);

        decimal /= 2;
    }

    reverse(binary.begin(), binary.end());

    return binary;
}

int BinaryConverter::binaryToDecimalByPosition(
    const string& binary
) {
    if (!isValidBinary(binary)) {
        throw invalid_argument(
            "O numero informado nao e um numero binario valido."
        );
    }

    int decimal = 0;
    int exponent = 0;

    for (int i = binary.length() - 1; i >= 0; i--) {
        int bit = binary[i] - '0';

        decimal += bit * pow(2, exponent);

        exponent++;
    }

    return decimal;
}

int BinaryConverter::binaryToDecimalByPowers(
    const string& binary
) {
    if (!isValidBinary(binary)) {
        throw invalid_argument(
            "O numero informado nao e um numero binario valido."
        );
    }

    int decimal = 0;

    for (char bit : binary) {
        decimal = decimal * 2 + (bit - '0');
    }

    return decimal;
}