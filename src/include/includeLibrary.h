#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <complex>
#include <cstring>
#include <map>
#include <exception>
#include <stdlib.h>
#include <fstream>
#include <thread>

#define F_PRINT         printf("\x1b[2C")               // Print by one (x+2)

//** Global static char array that contains alphabet
extern char letters[26];
//** Safe the iterator to the last char in the array
extern char* end;
//** Get letters's length
extern int lettersLength;