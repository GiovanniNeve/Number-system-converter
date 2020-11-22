#pragma once
#include "../include/includeLibrary.h"

//** Multiply input number by the new base
inline std::string multiplyNumberByBase(std::string& stringNumber, int newBase) {
    std::string result;
    std::vector<char> numberVector;
    //Limit fractorial digits
    int fractorialLimit = 0;
    double number = std::stof(stringNumber);
    int mapKey = 0;
    std::map<float, int> periodicMap;
    std::map<float, int>::iterator it;

    //** Loop till the number is 0 or the limit reach 5
    while (number != 0 && fractorialLimit < 8) {

        it = periodicMap.find(std::floor(number * 1000) / 1000);
        if(it != periodicMap.end()) {
            break;
        } else {
            periodicMap[std::floor(number * 1000) / 1000] = mapKey;
        }

        //** Multiply number by the new base
        number = number * newBase;

        //** Check if the number is grater or equal to 5
        if (number >= 1) {
            int rest = (int)number;

            if(rest > 9) {
                numberVector.push_back(letters[rest-10]);
            } else {
                //** Insert in the result vecotor the intger part
                numberVector.push_back(int(rest) + '0');
            }

            //** Remove intger part from the number
            number -= int(number);

        } else {
            numberVector.push_back(0 + '0');
        }

        //** Increase limit value
        fractorialLimit++;

        mapKey++;
    }

    //** Create an iterator for the vector
    std::vector<char>::iterator it2 = numberVector.begin();
    //** Insert numbers in a string
    for(it2; it2 != numberVector.end(); it2++) {
        //** Convert intgers to string and add them in a string
        result += *it2;
    }

    return result;
}

//** Devide number by the new base
inline std::string devideNumberByBase(std::string& stringNumber, int newBase) {
    std::string result;
    std::vector<char> numberVector;
    int number = std::stoi(stringNumber);

    if(stringNumber == "0")
        return stringNumber;

    while(number > 0) {
        int rest = number % newBase;
        if(rest > 9) {
            numberVector.push_back(letters[rest-10]);
        } else {
            //** Insert in the result vecotor the intger part
            numberVector.push_back(rest + '0');
        }

        number /= newBase;
    }

    //** Create an iterator for the vector
    std::vector<char>::reverse_iterator it2 = numberVector.rbegin();
    //** Insert numbers in a string
    for(it2; it2 != numberVector.rend(); it2++) {
        //** Convert intgers to string and add them in a string
        result += *it2;
    }

    return result;
}

//** COnvert number to ten base
inline double convertToTenNumber(std::string& number, int initialBase, int length) {
    std::vector<int> decimalNumber;
    double sum = 0;

    //** Loop for each char in the number
    for (char c : number) {

        //** Check if the number is an alphabet letter
        if (std::isalpha(c)) {
            //** If so, find it in the letters array returning his iterator
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