#include "../include/includeLibrary.h"

//**  Convert decimal number in a base higher than 10
static std::string convertToUnderTenBase(std::string stringNumber, int newBase) {
    std::vector<int> binaryNumber;
    std::string result;
    //** Convert the string into intger number
    int intNumber = std::stoi(stringNumber);

    //** Loop till the number is 0
    while (intNumber != 0) {
        //** Insert the rest in a vector
        binaryNumber.push_back(intNumber % newBase);
        //** Divide the number by the base
        intNumber = intNumber / newBase;
    }

    //** Create a reverse iterator for the vector
    std::vector<int>::reverse_iterator it = binaryNumber.rbegin();
    //** Reverse insert numbers in a string
    for(it; it != binaryNumber.rend(); it++) {
        //** Convert reversed intgers to string and add them in a string
        result += std::to_string(*it);
    }

    return result;
}