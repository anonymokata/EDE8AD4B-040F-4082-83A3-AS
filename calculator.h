#include <stdbool.h>

bool is_valid_roman_numeral(char str[]);
int roman_numeral_digit_value(char digit);
int roman_numeral_to_int(char str[]);
char first_digit(int value);
void int_to_roman_numeral(char *out, int value);