# Roman Numeral Calculator

Develop an C library for performing basic arithmetic operations on Roman Numeral values. Tested with libcheck. Developed with gcc version 4.8.4 on Ubuntu 14.04.

## prerequisites
* **libcheck** ```sudo apt install check``` on Ubuntu/Debian

## running the tests
```
git clone https://github.com/stevensona/RomanNumeralCalculator.git
cd RomanNumeralCalculator
make
./calculator
```

## functions

```c 
void add_roman_numerals(char *result, const char *first, const char *second);
void subtract_roman_numerals(char *result, const char *first, const char *second);
```

## future improvements
* unified way of handling invalid inputs
* efficiency could be improved because "adding two roman numerals" currently checks validity of inputs at multiple stages due to the way the tests are set up.
* use tree data structure to more quickly be able to convert from decimal to roman numeral
* add support for lower case roman numerals if desired
