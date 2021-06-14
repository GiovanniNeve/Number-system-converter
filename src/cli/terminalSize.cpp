/*
    Uses macros to get the size of terminal in both Windws and Linux
*/

#include "../include/includeLibrary.h"

#ifdef  __linux__
    #include <sys/ioctl.h>
    #include <unistd.h>     
#elif   _WIN32
    #include <Windows.h>
#endif


// Return the terminal's length and height
static void getTerminalSize(int* length, int* height) {
    #ifdef  __linux__
        struct winsize size;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
        *length = size.ws_col;
        *height = size.ws_row;

    #elif   _WIN32
        HANDLE hStdout;
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        SMALL_RECT srctWindow;

        GetConsoleScreenBufferInfo(hStdout, &csbi);

        srctWindow = csbi.srWindow;
        *length = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        *height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    #endif
}
