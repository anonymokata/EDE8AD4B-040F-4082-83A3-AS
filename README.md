# Roman Numeral Calculator Kata

Develop an C library for performing basic operations on Roman Numeral values. Tested with libcheck.

## functions

```c 
void add_roman_numerals(char *out, const char *first, const char *second);
void subtract_roman_numerals(char *out, const char *first, const char *second);
```

## future improvements

* unified way of handling invalid inputs
* efficiency could be improved because "adding two roman numerals" currently checks validity of inputs at multiple stages due to the way the tests are set up.
* use tree data structure to more quickly be able to convert from decimal to roman numeral
