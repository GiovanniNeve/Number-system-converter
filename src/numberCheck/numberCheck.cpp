#include "../include/includeLibrary.h"

//** Check if the number and the base are correct
static void numberCheck(std::string stringNumber, int initialBase, int newBase) {

    //** Check if the 2 bases are correct
    if(initialBase > lettersLength || initialBase < 2 || newBase > lettersLength || newBase < 2) {
        //** Throw error message
        throw "Base not supported";

    } else {
        for(char c : stringNumber) {
            
            //** Check if character is an alpha char for > 10 base    
            if(std::isalpha(c)) {
                if(c == ',')
                    throw "Error: ',' is not allowed, use ','";

                //** Get the position of the character in letters
                char* i = std::find(letters, end, c);

                //** Calculate the value of the character and compare with the base
                if ((i-letters+10) > (initialBase-1)) {
                    //** Throw error message
                    throw "Base doesn't contain this number";
                }

            } else {
                //** If the character is a dot ì, skip it
                if(c != '.') {
                    //** Convert char into a string
                    std::string temp(1, c);

                    //** Convert string into int and compare with the base
                    if (std::stoi(temp)>(initialBase-1)) {
                        //** Throw error message
                        throw "Base doesn't contain this number";
                    }
                }
                
            }
        
        }
    
    }

}