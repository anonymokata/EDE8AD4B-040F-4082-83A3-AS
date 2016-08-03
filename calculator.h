#include <stdbool.h>

bool is_valid_roman_numeral(const char *str);
int roman_numeral_digit_value(const char digit);
int roman_numeral_to_int(const char *str);
const char* next_roman_digit(const int value);
void int_to_roman_numeral(char *out, int value);