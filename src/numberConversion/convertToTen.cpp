#include "../include/includeLibrary.h"
#include "convertNumberFunction.cpp"

//** Convert a non decimal number in a decimal number
static std::string convertToTen(std::string stringNumber, int initialBase) {
    int intgerSum;
    double fractorialSum = 0.0;
    int stringLength = stringNumber.length();
    std::string result;
    std::string numTemp;
    std::string intgerNumber;

    if(stringNumber.find('.', 0) != std::string::npos) {
        std::string fractorialNumber;
        std::string stringTemp = stringNumber;

        size_t dotPosition = stringTemp.find_first_of('.');
        //** Leave only the intger part in the string
        stringTemp.erase(dotPosition);
        //** Store the intger part in a variable
        intgerNumber = stringTemp;
        //** Reset string template
        stringTemp = stringNumber;
        //** Leave only the fractorial part in the string
        stringTemp.erase(stringTemp.begin(), stringTemp.end() - (stringLength - dotPosition - 1));
        //** Store the fractorial part in a variable
        fractorialNumber = stringTemp;
        fractorialSum = convertToTenNumber(fractorialNumber, initialBase, 0);

    } else {
        intgerNumber = stringNumber;

    }

    intgerSum = convertToTenNumber(intgerNumber, initialBase, intgerNumber.length());

    result = (fractorialSum != 0.0) ? std::to_string(intgerSum + fractorialSum) : std::to_string(intgerSum);

    return result;
}


