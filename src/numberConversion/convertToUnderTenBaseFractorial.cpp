#include "../include/includeLibrary.h"

//** COnvert intger to under ten base
inline std::string convertFractorial(float fractorialNumber, std::vector<int> binaryNumber, int newBase) {
    std::string result;
    //** Set a limit for fractorial part
    int fractorialLimitCharacter = 0;

    //** Add a dot between intger and fractorial part
    result += '.';

    //** Loop till the number is 0 or the limit reach 5
    while (fractorialNumber != 0 && fractorialLimitCharacter < 5) {
        //** Multiply number by the new base
        fractorialNumber = fractorialNumber * newBase;

        //** Check if the number is grater or equal to 5
        if (fractorialNumber >= 1) {
            //** Insert in the result vecotor the intger part
            binaryNumber.push_back(int(fractorialNumber));
            //** Remove intger part from the number
            fractorialNumber -= int(fractorialNumber);

        } else {
            binaryNumber.push_back(0);
        }

        //** Increase limit value
        fractorialLimitCharacter++;
    }

    //** Create an iterator for the vector
    std::vector<int>::iterator it2 = binaryNumber.begin();
    //** Insert numbers in a string
    for(it2; it2 != binaryNumber.end(); it2++) {
        //** Convert intgers to string and add them in a string
        result += std::to_string(*it2);
    }

    return result;
}