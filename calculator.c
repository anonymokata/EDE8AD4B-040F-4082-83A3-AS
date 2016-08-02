#include <string.h>
#include "calculator.h"

bool is_valid_roman_numeral(char str[]) {
    char valid_chars[] = "IVXLCDM";

    for(int i = 0; i < strlen(str); ++i)
        if(strchr(valid_chars, str[i]) == NULL)
            return false; //fail early
    return true;
}