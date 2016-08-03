#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include <check.h>
#include "calculator.h"

START_TEST(can_count_max_number_of_consecutive_occurrences_in_string)
{
    ck_assert_int_eq(max_consecutive("123", '1'), 1);
    ck_assert_int_eq(max_consecutive("123", '0'), 0);
    ck_assert_int_eq(max_consecutive("123123", '1'), 1);
    ck_assert_int_eq(max_consecutive("ccc1c", 'c'), 3);
    ck_assert_int_eq(max_consecutive("ccc1ccc", 'c'), 3);
}
END_TEST

START_TEST(when_is_roman_numeral_valid_is_passed_one_digit_correct_response_returned)
{
    ck_assert_int_eq(is_roman_numeral_valid("I"), true);
    ck_assert_int_eq(is_roman_numeral_valid("V"), true);
    ck_assert_int_eq(is_roman_numeral_valid("X"), true);
    ck_assert_int_eq(is_roman_numeral_valid("L"), true);
    ck_assert_int_eq(is_roman_numeral_valid("C"), true);
    ck_assert_int_eq(is_roman_numeral_valid("D"), true);
    ck_assert_int_eq(is_roman_numeral_valid("M"), true);

    ck_assert_int_eq(is_roman_numeral_valid("A"), false);
    ck_assert_int_eq(is_roman_numeral_valid("B"), false);
    ck_assert_int_eq(is_roman_numeral_valid("E"), false);
    ck_assert_int_eq(is_roman_numeral_valid("F"), false);
    ck_assert_int_eq(is_roman_numeral_valid("1"), false);
    ck_assert_int_eq(is_roman_numeral_valid("5"), false);
    ck_assert_int_eq(is_roman_numeral_valid("9"), false);
    ck_assert_int_eq(is_roman_numeral_valid("0"), false);
}
END_TEST

START_TEST(when_is_roman_numeral_valid_is_passed_multiple_digits_correct_response_returned)
{
    ck_assert_int_eq(is_roman_numeral_valid("VI"), true);
    ck_assert_int_eq(is_roman_numeral_valid("IV"), true);
    ck_assert_int_eq(is_roman_numeral_valid("XXX"), true);
    ck_assert_int_eq(is_roman_numeral_valid("XVI"), true);
    ck_assert_int_eq(is_roman_numeral_valid("MI"), true);
    ck_assert_int_eq(is_roman_numeral_valid("DXLIV"), true);

    ck_assert_int_eq(is_roman_numeral_valid("IIII"), false);
    ck_assert_int_eq(is_roman_numeral_valid("XXXX"), false);
    ck_assert_int_eq(is_roman_numeral_valid("CCCC"), false);
    ck_assert_int_eq(is_roman_numeral_valid("LL"), false);
    ck_assert_int_eq(is_roman_numeral_valid("VV"), false);
    ck_assert_int_eq(is_roman_numeral_valid("DD"), false);

    ck_assert_int_eq(is_roman_numeral_valid("This should be invalid"), false);
    ck_assert_int_eq(is_roman_numeral_valid("INVALID"), false);
    ck_assert_int_eq(is_roman_numeral_valid("vii"), false);
    ck_assert_int_eq(is_roman_numeral_valid("xxx "), false);
    ck_assert_int_eq(is_roman_numeral_valid("d?d"), false);
    ck_assert_int_eq(is_roman_numeral_valid("12"), false);
    ck_assert_int_eq(is_roman_numeral_valid("-1005"), false);
    ck_assert_int_eq(is_roman_numeral_valid("123.34"), false);
}
END_TEST

START_TEST(when_roman_numeral_digit_to_int_is_passed_value_correct_response_returned)
{
    ck_assert_int_eq(roman_numeral_digit_to_int('I'), 1);
    ck_assert_int_eq(roman_numeral_digit_to_int('V'), 5);
    ck_assert_int_eq(roman_numeral_digit_to_int('X'), 10);
    ck_assert_int_eq(roman_numeral_digit_to_int('L'), 50);
    ck_assert_int_eq(roman_numeral_digit_to_int('C'), 100);
    ck_assert_int_eq(roman_numeral_digit_to_int('D'), 500);
    ck_assert_int_eq(roman_numeral_digit_to_int('M'), 1000);
}
END_TEST

START_TEST(when_roman_numeral_to_int_is_passed_invalid_value_correct_response_returned)
{
    ck_assert_int_eq(roman_numeral_to_int("INVALID"), -1);
}
END_TEST

START_TEST(when_roman_numeral_to_int_is_passed_value_correct_response_returned)
{
    ck_assert_int_eq(roman_numeral_to_int("VI"), 6);
    ck_assert_int_eq(roman_numeral_to_int("IV"), 4);
    ck_assert_int_eq(roman_numeral_to_int("XIV"), 14);
    ck_assert_int_eq(roman_numeral_to_int("XXX"), 30);
    ck_assert_int_eq(roman_numeral_to_int("III"), 3);
    ck_assert_int_eq(roman_numeral_to_int("XVI"), 16);
    ck_assert_int_eq(roman_numeral_to_int("MI"), 1001);
    ck_assert_int_eq(roman_numeral_to_int("XLIV"), 44);
    ck_assert_int_eq(roman_numeral_to_int("DXL"), 540);
    ck_assert_int_eq(roman_numeral_to_int("DXLI"), 541);
    ck_assert_int_eq(roman_numeral_to_int("DXLII"), 542);
    ck_assert_int_eq(roman_numeral_to_int("DXLIII"), 543);
    ck_assert_int_eq(roman_numeral_to_int("DXLIV"), 544);
}
END_TEST

START_TEST(when_next_roman_digit_is_passed_value_correct_response_returned)
{
    ck_assert_str_eq(next_roman_digit(1), "I");
    ck_assert_str_eq(next_roman_digit(7), "V");
    ck_assert_str_eq(next_roman_digit(100), "C");
    ck_assert_str_eq(next_roman_digit(50), "L");
    ck_assert_str_eq(next_roman_digit(1001), "M");
    
}
END_TEST

START_TEST(when_int_to_roman_numeral_is_passed_value_correct_response_returned)
{
    char result[16];
    int_to_roman_numeral(result, 7); ck_assert_str_eq(result, "VII");
    int_to_roman_numeral(result, 3); ck_assert_str_eq(result, "III");
    int_to_roman_numeral(result, 1); ck_assert_str_eq(result, "I");
    int_to_roman_numeral(result, 16); ck_assert_str_eq(result, "XVI");
    int_to_roman_numeral(result, 0); ck_assert_str_eq(result, "undefined");
    int_to_roman_numeral(result, 540); ck_assert_str_eq(result, "DXL");
    int_to_roman_numeral(result, 541); ck_assert_str_eq(result, "DXLI");
    int_to_roman_numeral(result, 44); ck_assert_str_eq(result, "XLIV");
    int_to_roman_numeral(result, 144); ck_assert_str_eq(result, "CXLIV");
    int_to_roman_numeral(result, 544); ck_assert_str_eq(result, "DXLIV");
    
}
END_TEST

START_TEST(can_add_roman_numerals)
{
    char result[16];

    add_roman_numerals(result, "I", "I"); ck_assert_str_eq(result, "II");
    add_roman_numerals(result, "II", "II"); ck_assert_str_eq(result, "IV");
    add_roman_numerals(result, "D", "D"); ck_assert_str_eq(result, "M");
    
}
END_TEST

START_TEST(can_subtract_roman_numerals)
{
    char result[16];

    subtract_roman_numerals(result, "I", "I"); ck_assert_str_eq(result, "undefined");
    subtract_roman_numerals(result, "X", "IV"); ck_assert_str_eq(result, "VI");
    subtract_roman_numerals(result, "C", "L"); ck_assert_str_eq(result, "L");
    
}
END_TEST

START_TEST(can_handle_random_inputs)
{
    srand(time(NULL));

    for(int i = 0; i < 10000; ++i) {
        int a = rand() % 2000 + 1, b = rand() % 2000 + 1;
        int c = rand() % 2000 + 1, d = rand() % 2000 + 1;
        
        char correct_answer_add[16], computed_add[16], roman_a[16], roman_b[16];
        char correct_answer_sub[16], computed_sub[16], roman_c[16], roman_d[16];

        int_to_roman_numeral(roman_a, a);
        int_to_roman_numeral(roman_b, b);
        int_to_roman_numeral(roman_c, c);
        int_to_roman_numeral(roman_d, d);

        ck_assert_int_eq(a, roman_numeral_to_int(roman_a));
        ck_assert_int_eq(b, roman_numeral_to_int(roman_b));
        ck_assert_int_eq(c, roman_numeral_to_int(roman_c));
        ck_assert_int_eq(d, roman_numeral_to_int(roman_d));

        int_to_roman_numeral(correct_answer_add, a + b);
        add_roman_numerals(computed_add, roman_a, roman_b);
        ck_assert_str_eq(correct_answer_add, computed_add);

        int_to_roman_numeral(correct_answer_sub, c - d);
        subtract_roman_numerals(computed_sub, roman_c, roman_d);
        ck_assert_str_eq(correct_answer_sub, computed_sub);
    }
}
END_TEST

Suite *roman_numeral_calculator_suite(void)
{
    Suite *test_suite = suite_create("Roman Numeral Calculator");
    TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, can_count_max_number_of_consecutive_occurrences_in_string);
    tcase_add_test(tc_core, when_is_roman_numeral_valid_is_passed_one_digit_correct_response_returned);
    tcase_add_test(tc_core, when_is_roman_numeral_valid_is_passed_multiple_digits_correct_response_returned);
    tcase_add_test(tc_core, when_roman_numeral_digit_to_int_is_passed_value_correct_response_returned);
    tcase_add_test(tc_core, when_roman_numeral_to_int_is_passed_value_correct_response_returned);
    tcase_add_test(tc_core, when_roman_numeral_to_int_is_passed_invalid_value_correct_response_returned);
    tcase_add_test(tc_core, when_next_roman_digit_is_passed_value_correct_response_returned);
    tcase_add_test(tc_core, when_int_to_roman_numeral_is_passed_value_correct_response_returned);
    tcase_add_test(tc_core, can_add_roman_numerals);
    tcase_add_test(tc_core, can_subtract_roman_numerals);
    tcase_add_test(tc_core, can_handle_random_inputs);
    suite_add_tcase(test_suite, tc_core);

    return test_suite;
}

int main(void)
{
    int number_failed;
    Suite *suite = roman_numeral_calculator_suite();
    SRunner *runner = srunner_create(suite);

    srunner_run_all(runner, CK_NORMAL);
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}