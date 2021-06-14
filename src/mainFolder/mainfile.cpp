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
#include "../cli/drawCLI.cpp"


//** Initialization of global variables
char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char* end = letters + sizeof(letters) / sizeof(letters[0]);
int lettersLength = std::strlen(letters);

//** Main
int main() {

    std::string number = "";
    std::string result = "";
    std::string outFileName = "out_file.txt";
    int initialBase = 0, newBase = 0;
    char choice = 'Y';
    bool toDraw = false, end = false;
    std::fstream outFile;
    std::thread thread(loopDraw, &outFileName, &number, &initialBase, &result, &newBase, &toDraw, &end);

    while (true) {
    //** Try condition
        try {            
            toDraw = true;

            //** Get number from the user and store in a string
            std::cin >> number;
            
            F_PRINT;
            //** Get the number initial base from the user
            std::cout << "Insert number's base: ";
            std::cin >> initialBase;

            F_PRINT;
            //** Get the number new base from the user
            std::cout << "Insert new base: ";
            std::cin >> newBase;

            //** Call numberCheck()
            numberCheck(number, initialBase, newBase);
            
            //** Check if number has to be caonverted from base 10 to base under 10
            if (initialBase==10 && newBase!=10) {
                F_PRINT;
                //** Call convertToUnderTenBase()
                result = convertToNewBase(number, newBase);
                std::cout << result << "\n\n";
            }
            //** Check if number has to be caonverted from base != 10 to base 10
            else if (initialBase!=10 && newBase==10) {
                F_PRINT;
                //** Call convertToTen()
                result = convertToTen(number, initialBase);
                std::cout << result << "\n\n";
            }
            //** Check if number has to be caonverted from base != 10 to base != 10
            else if (initialBase!=10 && newBase!=10) {
                //** Convert number to ten base
                result = convertToTen(number, initialBase);
                F_PRINT;
                //** Concert number to the new base
                result = convertToNewBase(result, newBase);
                std::cout << result << "\n\n";
            }

            outFile.open(outFileName, std::ios::app);
            outFile << number << " (" << initialBase << ")  " << result << " (" << newBase << ")\n";
            outFile.close();

            // Check if the user want to do another conversion
            F_PRINT;
    
            std::cout << "New conversion? (Y/n): ";
            std::cin.ignore();
            std::cin.get(choice);

            if(choice == 'n' || choice == 'N') {
                print_object(0, 0, "\x1b[2J\x1b[0;0H");
                end = true;

                if(thread.joinable())
                    thread.join();

                return EXIT_SUCCESS;
            }

            initialBase = 0;
            newBase = 0;
            number.erase();
            result.erase();
        }
        
        //** Catch condition
        catch (const std::exception& e) {
            F_PRINT;
            std::cout << "Cought exception: " << e.what();
            
            // Check if the user want to do another conversion
            F_PRINT;
    
            std::cout << "New conversion? (Y/n): ";
            std::cin.ignore();
            std::cin.get(choice);

            if(choice == 'n' || choice == 'N') {
                print_object(0, 0, "\x1b[2J\x1b[0;0H");
                end = true;

                if(thread.joinable())
                    thread.join();

                return EXIT_SUCCESS;
            }

            initialBase = 0;
            newBase = 0;
            number.erase();
            result.erase();
        }

        catch (const char* error) {
            F_PRINT;
            std::cout << "Cought exception: " << error;

            // Check if the user want to do another conversion
            F_PRINT;
    
            std::cout << "New conversion? (Y/n): ";
            std::cin.ignore();
            std::cin.get(choice);
            result.erase();

            if(choice == 'n' || choice == 'N') {
                print_object(0, 0, "\x1b[2J\x1b[0;0H");
                end = true;

                if(thread.joinable())
                    thread.join();

                return EXIT_SUCCESS;
            }

            initialBase = 0;
            newBase = 0;
            number.erase();
        }
    }

    return EXIT_SUCCESS;
}
