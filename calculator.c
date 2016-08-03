#include <string.h>
#include <stdio.h>

#include "calculator.h"

bool is_valid_roman_numeral(const char *str) {
    char valid_chars[] = "IVXLCDM";

    for(int i = 0; i < strlen(str); ++i)
        if(strchr(valid_chars, str[i]) == NULL)
            return false; //fail early
    return true;
}

int roman_numeral_digit_value(const char digit) {
    switch(digit) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default:
            printf("THIS SHOULD NOT HAVE HAPPENED\n"); 
            return -1;
    }                   
}

int roman_numeral_to_int(const char *str) {
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
            value += current_digit;
        }
        printf("%s -> intermediate: %i, value: %i\n", str, intermediate, value);
        
        last_digit = current_digit;
    }    
    return value + intermediate; //sum running value and intermediate not subtracted out
}

const char* next_roman_digit(const int value) {
    if(value >= 1000) return "M";
    if(value >= 900) return "CM";
    if(value >= 500) return "D";
    if(value >= 400) return "CD";
    if(value >= 100) return "C";
    if(value >= 90) return "XC";
    if(value >= 50) return "L";
    if(value >= 40) return "XL";
    if(value >= 10) return "X";
    if(value >= 9) return "IX";
    if(value >= 5) return "V";
    if(value >= 4) return "IV";
    return "I";
}

void int_to_roman_numeral(char *out, int value) {
    int current_pos = 0;
    strcpy(out, "undefined");
    while(value > 0) {
        const char *next = next_roman_digit(value);
        value -= roman_numeral_to_int(next);
        strncpy(&out[current_pos], next, strlen(next));
        current_pos += strlen(next);
        strcpy(&out[current_pos], "\0");
    }
   
}

void add_roman_numerals(char *out, const char *first, const char *second) {

    strcpy(out, "II");
}