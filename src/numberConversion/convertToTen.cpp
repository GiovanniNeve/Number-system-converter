#include "../include/includeLibrary.h"

//** Convert a non decimal number in a decimal number
static std::string convertToTen(std::string stringNumber, int initialBase) {
    std::vector<int> decimalNumber; 
    std::string numTemp;
    int sum = 0;
    //** Initialize length value at -1
    int length = -1;

    //** Loop for each char in the number
    for(char c : stringNumber) {
        //** Check if the number is an alphabet letter
        if(std::isalpha(c))  {
            //** If so, find it in the lettes array returning his iterator
            char* i = std::find(letters, end, c);
            //** Then calculate his intger value and insert in a vector
            decimalNumber.push_back(i - letters + 10);
        } else {
            //** If the number is an actual number convert from char to string
            std::string temp(1, c);
            //** Convert string to int and insert in a vector
            decimalNumber.push_back(std::stoi(temp));
        }
        length++;
    }

    //** Loop for each number in the vector
    for(auto c : decimalNumber) {
        //** Sum every number multiplied by inital base pow the position of the number
        sum += (c * std::pow(initialBase, length));
        length--;
    }
    
    //** Convert sum to string
    return std::to_string(sum);
}