#include "../include/includeLibrary.h"
#include "convertNumberFunction.cpp"

//** Convert decimal number in a base lower than 10
static std::string convertToNewBase(std::string stringNumber, int newBase) {
    std::string result;
    int stringLength = stringNumber.length();

    //** Check if the number id fractorial
    if(stringNumber.find('.', 0) != std::string::npos) {
        std::string stringTemp = stringNumber;
        //** Get the position of the dot
        size_t dotPosition = stringTemp.find_first_of('.');
        //** Erase all string after the dot, dot included
        stringTemp.erase(dotPosition);
        //** Store intger number
        std::string intNumber = stringTemp;
        //** Restore initial string
        stringTemp = stringNumber;
        //** Get the fractorial part of the number
        stringTemp.erase(stringTemp.begin(), stringTemp.end() - (stringLength - dotPosition));
        //** Store fractorial part
        std::string floatNumber = stringTemp;

        //** Calculate new base numbers
        floatNumber = multiplyNumberByBase(floatNumber, newBase);
        intNumber =   devideNumberByBase(intNumber, newBase);

        //** Put together the numbers and return
        return result = intNumber + '.' + floatNumber;

    } else {
        //** If number is not fractorial return intger number converted
        return result = devideNumberByBase(stringNumber, newBase);
    }

}