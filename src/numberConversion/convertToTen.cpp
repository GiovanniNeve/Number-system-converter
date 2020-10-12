#include "../include/includeLibrary.h"

inline double convertToTenNumber(std::string number, int initialBase, int length) {
    std::vector<int> decimalNumber;
    double sum = 0;

    //** Loop for each char in the number
    for (char c : number) {

        //** Check if the number is an alphabet letter
        if (std::isalpha(c)) {
            //** If so, find it in the lettes array returning his iterator
            char* i = std::find(letters, end, c);
            //** Then calculate his intger value and insert in a vector
            decimalNumber.push_back(i-letters+10);
        }
        else {
            //** If the number is an actual number convert from char to string
            std::string temp(1, c);
            //** Convert string to int and insert in a vector
            decimalNumber.push_back(std::stoi(temp));
        }

    }

    //** Loop for each number in the vector
    for(auto c : decimalNumber) {
        length -= 1;
        //** Sum every number multiplied by inital base pow the position of the number
        sum += (c * std::pow(initialBase, length));
    }

    //** Convert sum to string
    return sum;
}

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


