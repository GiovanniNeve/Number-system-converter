#include "../include/includeLibrary.h"

//** Convert decimal number in a base lower than 10
static std::string convertToOverTenBase(std::string stringNumber, int newBase) {
    std::vector<char> newBaseNumber;
    std::string result;
    //** Convert the string into intger number
    int intNumber = std::stoi(stringNumber);    

    //** Loop till the number is 0
    while(intNumber > 0) {
        char temp;
        //** Calculate the rest of the number
        float rest = intNumber % newBase;

        //** Check if the rest is over 9
        //** If so the intger need to be converted into alphabetical char
        if(rest > 9) {
            //** Get the index of the corresponding letter in the letters array
            int index = std::round(rest - 10);
            //** Insert the letter in the vector
            newBaseNumber.push_back(letters[index]);

        } else {
            //** Convert int to char
            temp = rest + '0';
            //** Insert the number(char) int he vector
            newBaseNumber.push_back(temp);
        }
        
        //** Divide the number by the base
        intNumber = intNumber / newBase;
    }
    
    //** Create a reverse iterator for the vector
    std::vector<char>::reverse_iterator it = newBaseNumber.rbegin();
    for(it; it != newBaseNumber.rend(); it++) {
        //** Insert reversed numbers in a string
        result += *it;
	}

    return result;
}