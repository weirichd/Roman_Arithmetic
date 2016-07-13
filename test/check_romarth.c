#include <check.h>

#include "../src/romarth.h"

#define ARRAY_LENGTH(arr) sizeof(arr)/sizeof(arr[0])

// #include "addition_tests.c"
#include "subtraction_tests.c"
//#include "error_tests.c"

int main() {
    Suite *s = suite_create("Arithmatic");
//    TCase *tc_add = tcase_create("Addition");
    TCase *tc_subtract = tcase_create("Subtraction");
//    TCase *tc_error_checks = tcase_create("Errors");
    SRunner *sr = srunner_create(s);

    int num_fails;

//    suite_add_tcase(s, tc_add);
    suite_add_tcase(s, tc_subtract);
//    suite_add_tcase(s, tc_error_checks);
/*
    tcase_add_test(tc_add, I_plus_I_equals_II);
    tcase_add_test(tc_add, I_plus_II_equals_III);
    tcase_add_test(tc_add, I_plus_V_equals_VI);
    tcase_add_test(tc_add, III_plus_II_equals_V);
    tcase_add_test(tc_add, V_plus_V_equals_X);

    tcase_add_test(tc_add, XXV_plus_XII_equals_XXXVII);
    tcase_add_test(tc_add, IV_plus_I_equals_V);
    tcase_add_test(tc_add, IX_plus_I_equals_X);
    tcase_add_test(tc_add, II_plus_II_equals_IV);
    tcase_add_test(tc_add, I_plus_VIII_equals_IX);

    tcase_add_test(tc_add, XXV_plus_XXV_equals_L);
    tcase_add_test(tc_add, L_plus_L_equals_C);
    tcase_add_test(tc_add, CCLXXXIX_plus_CDVII_equals_DCXCVI);
    tcase_add_test(tc_add, D_plus_D_equals_M);
    tcase_add_test(tc_add, M_plus_I_equals_MI);
*/
    tcase_add_test(tc_subtract, II_minus_I_equals_I);
    tcase_add_test(tc_subtract, V_minus_II_equals_III);
    tcase_add_test(tc_subtract, X_minus_V_equals_V);
    tcase_add_test(tc_subtract, X_minus_II_equals_VIII);
    tcase_add_test(tc_subtract, L_minus_XX_equals_XXX);

    tcase_add_test(tc_subtract, C_minus_L_equals_L);
    tcase_add_test(tc_subtract, D_minus_CC_equals_CCC);
    tcase_add_test(tc_subtract, M_minus_D_equals_D);
    tcase_add_test(tc_subtract, V_minus_I_equals_IV);
    tcase_add_test(tc_subtract, X_minus_I_equals_IX);

    tcase_add_test(tc_subtract, L_minus_X_equals_XL);
/* 
    tcase_add_test(tc_subtract, MMCDXXI_minus_CLIX_equals_MMCCLXII);

    tcase_add_test(tc_error_checks, addition_returns_an_empty_string_when_the_sum_array_is_not_large_enough);
    tcase_add_test(tc_error_checks, subtraction_returns_an_empty_string_when_the_difference_array_is_not_large_enough);
    tcase_add_test(tc_error_checks, subtraction_returns_an_empty_string_when_the_difference_would_have_been_negative);
    tcase_add_test(tc_error_checks, addition_returns_an_empty_string_when_the_sum_is_larger_than_we_can_express);
    tcase_add_test(tc_error_checks, the_caller_can_use_the_same_pointer_for_the_sum_and_the_first_summand_without_errors);

    tcase_add_test(tc_error_checks, the_caller_can_use_the_same_pointer_for_the_sum_and_the_second_summand_without_errors);
    tcase_add_test(tc_error_checks, the_caller_can_use_the_same_pointer_for_the_difference_and_the_minuend_without_errors);
    tcase_add_test(tc_error_checks, the_caller_can_use_the_same_pointer_for_the_difference_and_the_suptrahend_without_errors);
*/

    srunner_run_all(sr, CK_NORMAL);
    num_fails = srunner_ntests_failed(sr);
    srunner_free(sr);

    return num_fails == 0 ? 0 : 1;
}
