#include <stdlib.h>
#include <stdbool.h>

#include <check.h>
#include "calculator.h"

START_TEST(when_is_valid_roman_numeral_is_passed_one_digit_correct_response_returned)
{
    ck_assert_int_eq(is_valid_roman_numeral("I"), true);
    ck_assert_int_eq(is_valid_roman_numeral("V"), true);
    ck_assert_int_eq(is_valid_roman_numeral("X"), true);
    ck_assert_int_eq(is_valid_roman_numeral("L"), true);
    ck_assert_int_eq(is_valid_roman_numeral("C"), true);
    ck_assert_int_eq(is_valid_roman_numeral("D"), true);
    ck_assert_int_eq(is_valid_roman_numeral("M"), true);

    ck_assert_int_eq(is_valid_roman_numeral("A"), false);
    ck_assert_int_eq(is_valid_roman_numeral("B"), false);
    ck_assert_int_eq(is_valid_roman_numeral("E"), false);
    ck_assert_int_eq(is_valid_roman_numeral("F"), false);
    ck_assert_int_eq(is_valid_roman_numeral("1"), false);
    ck_assert_int_eq(is_valid_roman_numeral("5"), false);
    ck_assert_int_eq(is_valid_roman_numeral("9"), false);
    ck_assert_int_eq(is_valid_roman_numeral("0"), false);
}
END_TEST

START_TEST(when_is_valid_roman_numeral_is_passed_multiple_digits_correct_response_returned)
{
    ck_assert_int_eq(is_valid_roman_numeral("VI"), true);
    ck_assert_int_eq(is_valid_roman_numeral("IV"), true);
    ck_assert_int_eq(is_valid_roman_numeral("XXX"), true);
    ck_assert_int_eq(is_valid_roman_numeral("XVI"), true);
    ck_assert_int_eq(is_valid_roman_numeral("MI"), true);
    ck_assert_int_eq(is_valid_roman_numeral("DXLIV"), true);

    ck_assert_int_eq(is_valid_roman_numeral("IIII"), false);
    ck_assert_int_eq(is_valid_roman_numeral("IIIX"), false);

    ck_assert_int_eq(is_valid_roman_numeral("This should be invalid"), false);
    ck_assert_int_eq(is_valid_roman_numeral("INVALID"), false);
    ck_assert_int_eq(is_valid_roman_numeral("vii"), false);
    ck_assert_int_eq(is_valid_roman_numeral("xxx "), false);
    ck_assert_int_eq(is_valid_roman_numeral("d?d"), false);
    ck_assert_int_eq(is_valid_roman_numeral("12"), false);
    ck_assert_int_eq(is_valid_roman_numeral("-1005"), false);
    ck_assert_int_eq(is_valid_roman_numeral("123.34"), false);
}
END_TEST

START_TEST(when_roman_numeral_digit_value_is_passed_value_correct_response_returned)
{
    ck_assert_int_eq(roman_numeral_digit_value('I'), 1);
    ck_assert_int_eq(roman_numeral_digit_value('V'), 5);
    ck_assert_int_eq(roman_numeral_digit_value('X'), 10);
    ck_assert_int_eq(roman_numeral_digit_value('L'), 50);
    ck_assert_int_eq(roman_numeral_digit_value('C'), 100);
    ck_assert_int_eq(roman_numeral_digit_value('D'), 500);
    ck_assert_int_eq(roman_numeral_digit_value('M'), 1000);
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
    char out[16];
    int_to_roman_numeral(out, 7); ck_assert_str_eq(out, "VII");
    int_to_roman_numeral(out, 3); ck_assert_str_eq(out, "III");
    int_to_roman_numeral(out, 1); ck_assert_str_eq(out, "I");
    int_to_roman_numeral(out, 16); ck_assert_str_eq(out, "XVI");
    int_to_roman_numeral(out, 0); ck_assert_str_eq(out, "undefined");
    int_to_roman_numeral(out, 540); ck_assert_str_eq(out, "DXL");
    int_to_roman_numeral(out, 541); ck_assert_str_eq(out, "DXLI");
    int_to_roman_numeral(out, 44); ck_assert_str_eq(out, "XLIV");
    int_to_roman_numeral(out, 144); ck_assert_str_eq(out, "CXLIV");
    int_to_roman_numeral(out, 544); ck_assert_str_eq(out, "DXLIV");
    
}
END_TEST

START_TEST(can_add_roman_numerals)
{
    char out[16];

    add_roman_numerals(out, "I", "I"); ck_assert_str_eq(out, "II");
    add_roman_numerals(out, "II", "II"); ck_assert_str_eq(out, "IV");
    add_roman_numerals(out, "D", "D"); ck_assert_str_eq(out, "M");
    
}
END_TEST

START_TEST(can_subtract_roman_numerals)
{
    char out[16];

    subtract_roman_numerals(out, "I", "I"); ck_assert_str_eq(out, "undefined");
    subtract_roman_numerals(out, "X", "IV"); ck_assert_str_eq(out, "VI");
    subtract_roman_numerals(out, "C", "L"); ck_assert_str_eq(out, "L");
    
}
END_TEST

Suite *roman_numeral_calculator_suite(void)
{
    Suite *test_suite = suite_create("Roman Numeral Calculator");
    TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, when_is_valid_roman_numeral_is_passed_one_digit_correct_response_returned);
    tcase_add_test(tc_core, when_is_valid_roman_numeral_is_passed_multiple_digits_correct_response_returned);
    tcase_add_test(tc_core, when_roman_numeral_digit_value_is_passed_value_correct_response_returned);
    tcase_add_test(tc_core, when_roman_numeral_to_int_is_passed_value_correct_response_returned);
    tcase_add_test(tc_core, when_roman_numeral_to_int_is_passed_invalid_value_correct_response_returned);
    tcase_add_test(tc_core, when_next_roman_digit_is_passed_value_correct_response_returned);
    tcase_add_test(tc_core, when_int_to_roman_numeral_is_passed_value_correct_response_returned);
    tcase_add_test(tc_core, can_add_roman_numerals);
    tcase_add_test(tc_core, can_subtract_roman_numerals);
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