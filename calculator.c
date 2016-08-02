#include <string.h>
#include "calculator.h"

bool is_valid_roman_numeral(char str[]) {
    char valid_chars[] = "IVXLCDM";

    for(int i = 0; i < strlen(str); ++i)
        if(strchr(valid_chars, str[i]) == NULL)
            return false; //fail early
    return true;
}

int roman_numeral_to_int(char str[]) {
    if(is_valid_roman_numeral(str) == false)
        return -1;
    int value = 0;
        for(int i = 0; i < strlen(str); ++i) {
            switch(str[i]) {
                case 'I':
                    value += 1;
                    break;
                case 'V':
                    value += 5;
                    break;
                case 'X':
                    value += 10;
                    break;
                case 'L':
                    value += 10;
                    break;
                case 'C':
                    value += 10;
                    break;  
                case 'D':
                    value += 10;
                    break;
                case 'M':
                    value += 10;
                    break;
                default:
                //this should never actually happen due to the earlier check. Consider refactoring later
                    return -1;                                                                                        
            }
        }    
    return value;
}