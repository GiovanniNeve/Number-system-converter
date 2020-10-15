/**
 * * ------------------------------------------------------------
 * * For a better understanding of the code
 * * it is required a basic knowledge of  
 * * the number system conversion
 * * ------------------------------------------------------------
*/

#include "../numberCheck/numberCheck.cpp"
#include "../numberConversion/convertToNewBase.cpp"
#include "../numberConversion/convertToTen.cpp"

//** Initialization of global variables
char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char* end = letters + sizeof(letters) / sizeof(letters[0]);
int lettersLength = std::strlen(letters);

//** Main
int main() {
    
    //** Try condition
    try {
        std::cout
                << "\nWARNING: At the moment the number this converter can take fractorial numbers only\nfor 10 to <10 base conversion, fractorial numbers will be implementerd soon.\n\n";

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
        if (initialBase==10 && newBase!=10) {
            //** Call convertToUnderTenBase()
            std::cout << convertToNewBase(number, newBase);

        //** Check if number has to be caonverted from base != 10 to base 10
        } else if (initialBase != 10 && newBase == 10) {
            //** Call convertToTen()
            std::cout << convertToTen(number, initialBase);

        //** Check if number has to be caonverted from base != 10 to base != 10
        } else if(initialBase != 10 && newBase != 10) {
            //** Convert number to ten base
            result = convertToTen(number, initialBase);
            //** Concert number to the new base
            result = convertToNewBase(result, newBase);
        }
    } 

    //** Catch condition
    catch(const char* error) {
        std::cout << "\nAn error occured: " << error << std::endl;
    }

return 0;

}
