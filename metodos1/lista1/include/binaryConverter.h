#ifndef BINARY_CONVERTER_H
#define BINARY_CONVERTER_H

#include <string>

using namespace std;

class BinaryConverter {
private:
    static bool isValidBinary(const string& binary);

public:
    static string decimalToBinary(int decimal);

    static int binaryToDecimalByPosition(
        const string& binary
    );

    static int binaryToDecimalByPowers(
        const string& binary
    );
};

#endif