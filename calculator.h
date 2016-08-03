#include <stdbool.h>

bool is_roman_numeral_valid(const char *str);
int max_consecutive(const char *str, const char c);   
int roman_numeral_digit_to_int(const char digit);
int roman_numeral_to_int(const char *str);
const char* next_roman_digit(const int value);
void int_to_roman_numeral(char *out, int value);
void add_roman_numerals(char *out, const char *first, const char *second);
void subtract_roman_numerals(char *out, const char *first, const char *second);