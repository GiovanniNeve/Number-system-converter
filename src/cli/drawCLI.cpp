#include "../include/includeLibrary.h"
#include "terminalSize.cpp"

/*
    Draw the command line interface with unicodes character
    The right section, calculation history, is drawn only if
    the history section's length is longer than 20 character
*/


// Print a string in x,y position in the terminal
static void print_object(int y, int x, const char* data)
{
    char *Y = (char*)malloc(sizeof(y)), *X = (char*)malloc(sizeof(x));
    snprintf(Y, sizeof(y), "%d", y);
    snprintf(X, sizeof(x), "%d", x);
    // Uses the \x1b[rows;columnsH interrupt code
    printf("%s%s%s%s%s%s", "\x1b[", X, ";", Y, "H", data);
    fflush(stdout);
}


// Draw the command line interface
static void draw(int* length, int* height, std::string filename, std::string num, int base1, std::string res, int base2) {
    // Clear the screen with \x1b[2J to clear the screen
    // and \x1b[0;0H to set the cursor on the first cell of the terminal
    print_object(0, 0, "\x1b[2J\x1b[0;0H");
    // Get the index for the history section
    int history_index = (*length / 4) * 3;
    // Get the length of the history section
    int history_len = *length - history_index;
    std::ifstream file;

    // Draw the top line
    print_object(0, 0, "\u250F");
    for(int i=2; i < *length; i++)
    {   
        if(history_len >= 20 && i == history_index)
            print_object(i, 0, "\u2533");
        else
            print_object(i, 0, "\u2501");
    }
    print_object(*length, 0, "\u2513");


    // Draw the second top line
    print_object(0, 3, "\u2523");
    for(int i=2; i < *length; i++)
    {   
        if(history_len >= 20 && i == history_index)
            print_object(i, 3, "\u254B");
        else
            print_object(i, 3, "\u2501");
    }
    print_object(*length, 3, "\u252B");


    // Draw the bottom line
    print_object(0, *height, "\u2517");
    for(int i=2; i < *length; i++)
    {   
        if(history_len >= 20 && i == history_index)
            print_object(i, *height, "\u253B");
        else
            print_object(i, *height, "\u2501");
    }
    print_object(*length, *height, "\u251B");


    // Draw the left and right walls
    for(int i=2; i < *height; i++)
    {   
        if(i == 3)
            continue;
        // Draw the right wall
        print_object(0, i, "\u2503");
        // Draw the center wall
        if(history_len >= 20)
            print_object(history_index, i, "\u2503");
        // Draw the left wall
        print_object(*length, i, "\u2503");
    }


    // Write the main title
    if((*length - history_len) / 2 + 15 < history_index)
        print_object((*length - history_len) / 2 - 14, 2, "Number converter by Zambo-dev");
    // Write the history section title
    if(history_len >= 20)
        print_object(history_index + (*length - history_index) / 2 - 9, 2, "CONVERSION HISTORY");

    file.open(filename);

    if(!file.fail()) {
        int heightIdx = 0, idx = 0;
        char tmp[500];
        int arr_size = 15;
        char** tmp_arr = new char*[arr_size];

        while(!file.eof()) {
            if(idx == arr_size) {
                char** arr = new char*[arr_size*2];
                for(int i=0; i < arr_size; i++) {
                    arr[i] = new char[strlen(tmp_arr[i]) + 2];
                    strcpy(arr[i], tmp_arr[i]);
                }

                tmp_arr = arr;
                arr_size *= 2;
            }


            file.getline(tmp, 500, '\n');
            tmp_arr[idx] = new char[strlen(tmp) + 2];
            strcpy(tmp_arr[idx], tmp);
        
            idx++;
        }

        idx -= 2;
        for(idx; idx >= 0; idx--) {
            if(strlen(tmp_arr[idx]) + 6 <= history_len && heightIdx + 5 < *height-2)
            {
                print_object(history_index+3, 5+heightIdx, tmp_arr[idx]);
                heightIdx += 2;
            }
        }
    }

    //Set the cursor position in the main space
    printf("\x1b[5;3H");
    std::cout << "Insert number: ";

    if(!num.empty())
        std::cout << num;
    
    if(base1 != 0)
    {   
        printf("\x1b[6;3H");
        std::cout << "Insert number's base: ";
        std::cout << base1;
    }

    if(base2 != 0)
    {   
        printf("\x1b[7;3H");
        std::cout << "Insert new base: ";
        std::cout << base2;
    }

    if(!res.empty())
    {
        printf("\x1b[9;3H");
        std::cout << res;
        printf("\x1b[10;3H");
        std::cout << "New conversion? (Y/n): ";
    }

    fflush(stdout);
}


static void loopDraw(std::string* filename, std::string* number, int* base1, std::string* result, int* base2, bool* toLoop, bool* stop) {
    int *len = new int, *heg = new int;
    getTerminalSize(len, heg);

    int initLen = * len, initHeg = *heg;
    draw(len, heg, *filename, *number, *base1, *result, *base2);

    while(true) {
        if(*stop)
            break;
            
        getTerminalSize(len, heg);
        
        if(*len != initLen || *heg != initHeg || *toLoop) {
            initLen = *len;
            initHeg = *heg;
            draw(len, heg, *filename, *number, *base1, *result, *base2);
            *toLoop = false;
        }
    }

    return;
} 