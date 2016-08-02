#include <stdlib.h>
#include <stdbool.h>

#include <check.h>
#include "calculator.h"

START_TEST(when_is_valid_roman_numeral_is_passed_a_value_correct_response_returned)
{
    ck_assert_int_eq(is_valid_roman_numeral("I"), true);    
}
END_TEST

Suite *roman_numeral_calculator_suite(void)
{
    Suite *test_suite = suite_create("Roman Numeral Calculator");
    TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_is_valid_roman_numeral);
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