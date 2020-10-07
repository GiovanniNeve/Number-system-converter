#include "../include/includeLibrary.h"

//**  Convert decimal number in a base higher than 10
static std::string convertToUnderTenBase(std::string stringNumber, int newBase) {
    std::vector<int> binaryNumber;
    std::string result;
    //** Search in the number for the dot and store his iterator
    size_t dotPosition = stringNumber.find('.', 0);
    //** Convert the string into intger number
    int intNumber = std::stoi(stringNumber, &dotPosition);
    //** Erase the intger part of the number
    stringNumber.erase(0, dotPosition+1);
    int fractorialNumberLength = stringNumber.length();
    //** Store the fractorial part in a float
    float fractorialNumber = std::stoi(stringNumber) * std::pow(10, -(fractorialNumberLength));
    //** Set a limit for fractorial part
    int fractorialLimitCharacter = 0;

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

    //** Clear the restult vector
    binaryNumber.clear();

    //** Add a dot between intger and fractorial part
    result += '.';

    //** Loop till the number is 0 or the limit reach 5
    while (fractorialNumber != 0 && fractorialLimitCharacter < 5) {
        //** Multiply number by the new base
        fractorialNumber = fractorialNumber * newBase;

        //** Check if the number is grater or equal to 5
        if (fractorialNumber >= 1) {
            //** Insert in the result vecotor the intger part
            binaryNumber.push_back(int(fractorialNumber));
            //** Remove intger part from the number
            fractorialNumber -= int(fractorialNumber);

        } else {
            binaryNumber.push_back(0);
        }

        //** Increase limit value
        fractorialLimitCharacter++;
    }

    //** Create an iterator for the vector
    std::vector<int>::iterator it2 = binaryNumber.begin();
    //** Insert numbers in a string
    for(it2; it2 != binaryNumber.end(); it2++) {
        //** Convert intgers to string and add them in a string
        result += std::to_string(*it2);
    }

    return result;
}