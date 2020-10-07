#include "../include/includeLibrary.h"
#include "convertToUnderTenBaseFractorial.cpp"

//**  Convert decimal number in a base higher than 10
static std::string convertToUnderTenBase(std::string stringNumber, int newBase) {
    std::vector<int> binaryNumber;
    std::string finalResult;
    std::string fractorialResult;
    int intNumber;
    float fractorialNumber;

    if(stringNumber.find('.', 0) != std::string::npos) {
        //** Store the fractorial part in a float
        fractorialNumber = std::stof(stringNumber);
        intNumber = int(fractorialNumber);
        fractorialResult = convertFractorial(fractorialNumber - intNumber, binaryNumber, newBase);
    } else {
        intNumber = std::stoi(stringNumber);
    }

    //** Loop till the number is 0
    while (intNumber!=0) {
        //** Insert the rest in a vector
        binaryNumber.push_back(intNumber%newBase);
        //** Divide the number by the base
        intNumber = intNumber/newBase;
    }

    //** Create a reverse iterator for the vector
    std::vector<int>::reverse_iterator it = binaryNumber.rbegin();
    //** Reverse insert numbers in a string
    for (it; it!=binaryNumber.rend(); it++) {
        //** Convert reversed intgers to string and add them in a string
        finalResult += std::to_string(*it);
    }

    finalResult += fractorialResult;

    return finalResult;
}