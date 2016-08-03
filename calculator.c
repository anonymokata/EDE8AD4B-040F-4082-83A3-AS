#include <string.h>
#include <stdio.h>

#include "calculator.h"

int max_consecutive(const char *str, const char c) {
    char *current = (char*)str;
    int max = 0, occurrences = 0;
    while(*current != '\0') {
        if(*current++ == c) {
            max = ++occurrences > max ? occurrences : max;
        } else {
            occurrences = 0;
        }
    }
    return max;
}

bool is_roman_numeral_valid(const char *str) {
    char valid_chars[] = "IVXLCDM";
    char *current = (char*)str;
    
    while(*current != '\0')
        if(strchr(valid_chars, *current++) == NULL)
            return false; //fail early

    if(max_consecutive(str, 'I') > 3) return false;
    if(max_consecutive(str, 'X') > 3) return false;
    if(max_consecutive(str, 'C') > 3) return false;
    if(max_consecutive(str, 'L') > 1) return false;
    if(max_consecutive(str, 'V') > 1) return false;
    if(max_consecutive(str, 'D') > 1) return false;

    return true;
}

int roman_numeral_digit_to_int(const char digit) {
    switch(digit) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return -1; //should never happen
    }                   
}

int roman_numeral_to_int(const char *str) {
    if(is_roman_numeral_valid(str) == false)
        return -1;
    int value = 0;
    int last_digit = 0;
    for(int i = 0; i < strlen(str); ++i) {
        int current_digit = roman_numeral_digit_to_int(str[i]);
        if(current_digit > last_digit && i > 0) {
            value += current_digit - last_digit * 2; //subtract twice because it was added to value last loop
        } else {
            value += current_digit;
        }
        last_digit = current_digit;
    }    
    return value;
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
    strcpy(out, "undefined");
    if(is_roman_numeral_valid(first) && is_roman_numeral_valid(second))
        int_to_roman_numeral(out, roman_numeral_to_int(first) + roman_numeral_to_int(second));
}

void subtract_roman_numerals(char *out, const char *first, const char *second) {
    strcpy(out, "undefined");
    if(is_roman_numeral_valid(first) && is_roman_numeral_valid(second))
        int_to_roman_numeral(out, roman_numeral_to_int(first) - roman_numeral_to_int(second));
}