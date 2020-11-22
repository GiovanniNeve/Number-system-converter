/**
 * * ------------------------------------------------------------
 * * For a better understanding of the code
 * * it is required a basic knowledge of  
 * * the number system conversion
 * * ------------------------------------------------------------
*/

//** Include other files with functions
#include "../numberCheck/numberCheck.cpp"
#include "../numberConversion/convertToNewBase.cpp"
#include "../numberConversion/convertToTen.cpp"

//** Initialization of global variables
char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char* end = letters + sizeof(letters) / sizeof(letters[0]);
int lettersLength = std::strlen(letters);

//** Main
int main() {

    std::string number;
    std::string result;
    int initialBase, newBase;
    char loop = 'Y';

    while (true) {

    //** Try condition
        try {

            //** Get number from the user and store in a string
            std::cout << "Insert number: ";
            std::cin >> number;

            //** Get the number initial base from the user
            std::cout << "Insert number's base: ";
            std::cin >> initialBase;

            //** Get the number new base from the user
            std::cout << "Insert new base: ";
            std::cin >> newBase;

            //** Call numberCheck()
            numberCheck(number, initialBase, newBase);

            //** Check if number has to be caonverted from base 10 to base under 10
            if (initialBase==10 && newBase!=10) {
                //** Call convertToUnderTenBase()
                std::cout << convertToNewBase(number, newBase);

                //** Check if number has to be caonverted from base != 10 to base 10
            }
            else if (initialBase!=10 && newBase==10) {
                //** Call convertToTen()
                std::cout << convertToTen(number, initialBase);

                //** Check if number has to be caonverted from base != 10 to base != 10
            }
            else if (initialBase!=10 && newBase!=10) {
                //** Convert number to ten base
                result = convertToTen(number, initialBase);
                //** Concert number to the new base
                std::cout << convertToNewBase(result, newBase);
            }

            std::cout << "\nNew conversion? (Y/n): ";
            std::cin.ignore();
            std::cin.get(loop);

            if(loop == 'n' || loop == 'N')
                break;

        }
        //** Catch condition
        catch(const char* error) {
            std::cout << "\nAn error occured: " << error << ", try again...\n";
        }

    }

return 0;

}
