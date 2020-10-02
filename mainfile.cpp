/**
 * * ------------------------------------------------------------
 * * For a better understanding of the code
 * * it is required a basic knowledge of  
 * * the number system conversion
 * * ------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <complex.h>
#include <cstring>

//** Global static char array that contains alphabet
static char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
//** Safe the iterator to the last char in the array
static char* end = letters + sizeof(letters) / sizeof(letters[0]);
//** Get letters's length
static int lettersLength = std::strlen(letters);

//** Check if the number and the base are correct
void numberCheck(std::string stringNumber, int initialBase, int newBase) {

    //** Check if the 2 bases are correct
    if(initialBase > lettersLength || newBase > lettersLength) {    
        //** Throw error message
        throw "Base overload";  

    } else {
        for(char c : stringNumber) {
            
            //** Check if character is an alpha char for > 10 base    
            if(std::isalpha(c)) {
                //** Get the position of the character in letters   
                char* i = std::find(letters, end, c);

                //** Calculate the value of the character and compare with the base  
                if((i - letters + 10) > (initialBase - 1)) {
                    //** Throw error message
                    throw "Base doesn't contain this number";
                }

            } else {
                //** Convert char into a string
                std::string temp(1, c);
                
                //** Convert string into int and compare with the base
                if(std::stoi(temp) > (initialBase - 1)) {
                    //** Throw error message
                    throw "Base doesn't contain this number";
                }
                
            }
        
        }
    
    }

}

//**  Convert decimal number in a base higher than 10 
std::string convertToUnderTenBase(std::string stringNumber, int newBase) {
    std::vector<int> binaryNumber;
    std::string result;
    //** Convert the string into intger number
    int intNumber = std::stoi(stringNumber);

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

    return result;
}

//** Convert decimal number in a base lower than 10
std::string convertToOverTenBase(std::string stringNumber, int newBase) {
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

//** Convert a non decimal number in a decimal number
std::string convertToTen(std::string stringNumber, int initialBase) {
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

//** Main
int main() {
    
    //** Try condition
    try {
        std::cout << "\nWARNING: At the moment the number this converter can take only intger numbers,\nfractorial numbers will be implementerd soon.\n\n";

        std::string number;
        std::string result;
        int initialBase, newBase;

        std::cout << "Insert number: ";
        std::cin >> number;

        std::cout << "Insert number's base: ";
        std::cin >> initialBase;

        std::cout << "Insert new base: ";
        std::cin >> newBase;

        //** Call numberCheck()
        numberCheck(number, initialBase, newBase);

        //** Check if number has to be caonverted from base 10 to base under 10
        if(initialBase == 10 && newBase < 10) {
            //** Call convertToUnderTenBase()
            std::cout << convertToUnderTenBase(number, newBase);

        //** Check if number has to be caonverted from base 10 to base over 10
        } else if(initialBase == 10 && newBase > 10) {
            //** Call convertToOverTenBase()
            std::cout << convertToOverTenBase(number, newBase);

                //** Check if number has to be caonverted from base != 10 to base 10
        } else if (initialBase != 10 && newBase == 10) {
            //** Call convertToTen()
            std::cout << convertToTen(number, initialBase);

                //** Check if number has to be caonverted from base != 10 to base != 10
        } else if(initialBase != 10 && newBase != 10) {
            //** Call convertToTen()
            result = convertToTen(number, initialBase);
            //** If new base is under 10 call convertToUnderTenBase(), if it is over 10 call convertToOverTenBase()
            (newBase < 10) ? std::cout << convertToUnderTenBase(result, newBase) : std::cout << convertToOverTenBase(result, newBase);
        }
    } 

    //** Catch condition
    catch(const char* error) {
        std::cout << "\nAn error occured: " << error << std::endl;
    }

return 0;

}
