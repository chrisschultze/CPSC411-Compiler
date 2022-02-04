#ifndef ERROR_HANDLER_HPP
#define ERROR_HANDLER_HPP

#include <iostream>

using namespace std;

enum {
    ERROR_TOOMANYWARNINGS = 1,
    ERROR_BADARGS,
    ERROR_BADFILE,
    LEX_ERROR_NEWLINESTR,
    LEX_ERROR_EOFSTR,
    LEX_WARNING_INVALIDCHAR
};

inline int error(int code, string details = "")
{
    switch (code)
    {
        case ERROR_TOOMANYWARNINGS:
            cerr << "\x1B[1;31mError: \x1B[0mToo many warnings, aborting process." << endl;
            exit(EXIT_FAILURE);
        case ERROR_BADARGS:
            cerr << "\x1B[1;31mError: \x1B[0mExpected one argument" << endl;
            exit(EXIT_FAILURE);
        case ERROR_BADFILE:
            cerr << "\x1B[1;31mError: \x1B[0mFile could not be opened" << endl;
            exit(EXIT_FAILURE);
        case LEX_ERROR_NEWLINESTR:
            cerr << "\x1B[1;31mError: \x1B[0mnewline inside string at line " << details << endl;
            exit(EXIT_FAILURE);
        case LEX_ERROR_EOFSTR:
            cerr << "\x1B[1;31mError: \x1B[0mstring missing closing quote at line " << details << endl;
            exit(EXIT_FAILURE);
        default:
            cerr << "\x1B[1;31mError: \x1B[0undefined error";
            exit(EXIT_FAILURE);
    }
}

int warningno = 0;

inline void warning(int code, string details = "")
{
    switch (code)
    {
        case LEX_WARNING_INVALIDCHAR:
            cerr << "Warning: invalid character at line " << details << endl;
            warningno++;
            break;
        default:
            cerr << "\x1B[31mWarning: \x1B[0mundefined warning " << endl;
    }
    if (warningno > 10) error(1);
}

#endif