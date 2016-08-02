#include <string.h>
#include "calculator.h"

bool is_valid_roman_numeral(char str[]) {
    char valid_chars[] = "IVXLCDM";

    for(int i = 0; i < strlen(str); ++i)
        if(strchr(valid_chars, str[i]) == NULL)
            return false; //fail early
    return true;
}

int roman_numeral_digit_value(char digit) {
    switch(digit) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return -1;
    }                   
}

int roman_numeral_to_int(char str[]) {
    if(is_valid_roman_numeral(str) == false)
        return -1;
    int value = 0;
    int subtract = 0; //intermediate value used to calculate subtractions
    for(int i = 0; i < strlen(str); ++i) {
        value += roman_numeral_digit_value(str[i]);
        //if(i < strlen(str) - 1) //check to see if need to subtract instead

    }    
    return value;
}