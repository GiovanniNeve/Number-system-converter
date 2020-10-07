#include "../include/includeLibrary.h"
#include "convertToUnderTenBaseIntger.cpp"

//**  Convert decimal number in a base higher than 10
static std::string convertToUnderTenBase(std::string stringNumber, int newBase) {
    std::vector<int> binaryNumber;
    std::string finalResult;
    std::string fractorialResult;
    int intNumber;
    float fractorialNumber;

    if(stringNumber.find('.', 0) != std::string::npos) {
        //** Search in the number for the dot and store his iterator
        size_t dotPosition = stringNumber.find('.', 0);
        //** Convert the string into intger number
        intNumber = std::stoi(stringNumber, &dotPosition);
        //** Erase the intger part of the number
        stringNumber.erase(0, dotPosition+1);
        int fractorialNumberLength = stringNumber.length();
        //** Store the fractorial part in a float
        fractorialNumber = std::stoi(stringNumber)*std::pow(10, -(fractorialNumberLength));
        fractorialResult = convertFractorial(fractorialNumber, binaryNumber, newBase);
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