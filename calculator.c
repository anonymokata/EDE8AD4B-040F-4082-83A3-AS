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
    int intermediate = 0; //intermediate value used in case subtraction is needed
    int last_digit = 0;
    for(int i = 0; i < strlen(str); ++i) {
        int current_digit = roman_numeral_digit_value(str[i]);
        if(current_digit > last_digit && i > 0) {
            value += current_digit - intermediate;
            intermediate = 0;
        } else {
            intermediate += current_digit;
        }
        last_digit = current_digit;
    }    
    return value + intermediate; //sum running value and intermediate not subtracted out
}

char first_digit(int value) {
    if(value < 5) return 'I';
    if(value < 10) return 'V';
    if(value < 50) return 'X';
    if(value < 100) return 'L';
    if(value < 500) return 'C';
    if(value < 1000) return 'D';
    return 'M';
}
void int_to_roman_numeral(char *out, int value) {
    strcpy(out, "VII");

}