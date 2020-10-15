#include "../include/includeLibrary.h"
#include "convertNumberFunction.cpp"

//** Convert decimal number in a base lower than 10
static std::string convertToNewBase(std::string stringNumber, int newBase) {
    std::string result;
    int stringLength = stringNumber.length();

    if(stringNumber.find('.', 0) != std::string::npos) {
        std::string stringTemp = stringNumber;
        size_t dotPosition = stringTemp.find_first_of('.');
        stringTemp.erase(dotPosition);
        std::string intNumber = stringTemp;
        stringTemp = stringNumber;
        stringTemp.erase(stringTemp.begin(), stringTemp.end() - (stringLength - dotPosition));
        std::string floatNumber = stringTemp;

        floatNumber = multiplyNumberByBase(floatNumber, newBase, true);
        intNumber =   devideNumberByBase(intNumber, newBase);

        return result = intNumber + '.' + floatNumber;

    } else {
        return result = devideNumberByBase(stringNumber, newBase);
    }

}