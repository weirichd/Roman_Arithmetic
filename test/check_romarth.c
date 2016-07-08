#include <check.h>

#include "../src/romarth.h"

#define ARRAY_LENGTH(arr) sizeof(arr)/sizeof(arr[0])

START_TEST(I_plus_I_equals_II) { 
    char summand1[] = "I";
    char summand2[] = "I";
    char sum[3] = {};

    roman_add(sum, ARRAY_LENGTH(sum),  summand1, summand2); 

    ck_assert_str_eq(sum, "II");
} END_TEST

START_TEST(I_plus_II_equals_III) { 
    char summand1[] = "I";
    char summand2[] = "II";
    char sum[4] = {};

    roman_add(sum, ARRAY_LENGTH(sum),  summand1, summand2); 

    ck_assert_str_eq(sum, "III");
} END_TEST

START_TEST(I_plus_V_equals_VI) { 
    char summand1[] = "I";
    char summand2[] = "V";
    char sum[3] = {};

    roman_add(sum, ARRAY_LENGTH(sum),  summand1, summand2); 

    ck_assert_str_eq(sum, "VI");
} END_TEST

START_TEST(III_plus_II_equals_V) { 
    char summand1[] = "III";
    char summand2[] = "II";
    char sum[2] = {};

    roman_add(sum, ARRAY_LENGTH(sum),  summand1, summand2); 

    ck_assert_str_eq(sum, "V");
} END_TEST

START_TEST(V_plus_V_equals_X) { 
    char summand1[] = "V";
    char summand2[] = "V";
    char sum[2] = {};

    roman_add(sum, ARRAY_LENGTH(sum),  summand1, summand2); 

    ck_assert_str_eq(sum, "X");
} END_TEST

START_TEST(XXV_plus_XII_equals_XXXVII) { 
    char summand1[] = "XXV";
    char summand2[] = "XII";
    char sum[7] = {};

    roman_add(sum, ARRAY_LENGTH(sum),  summand1, summand2); 

    ck_assert_str_eq(sum, "XXXVII");
} END_TEST

START_TEST(IV_plus_I_equals_V) { 
    char summand1[] = "IV";
    char summand2[] = "I";
    char sum[2] = {};

    roman_add(sum, ARRAY_LENGTH(sum),  summand1, summand2); 

    ck_assert_str_eq(sum, "V");
} END_TEST

START_TEST(IX_plus_I_equals_X) { 
    char summand1[] = "IX";
    char summand2[] = "I";
    char sum[2] = {};

    roman_add(sum, ARRAY_LENGTH(sum),  summand1, summand2); 

    ck_assert_str_eq(sum, "X");
} END_TEST

START_TEST(II_plus_II_equals_IV) { 
    char summand1[] = "II";
    char summand2[] = "II";
    char sum[3] = {};

    roman_add(sum, ARRAY_LENGTH(sum),  summand1, summand2); 

    ck_assert_str_eq(sum, "IV");
} END_TEST

START_TEST(I_plus_VIII_equals_IX) { 
    char summand1[] = "I";
    char summand2[] = "VIII";
    char sum[3] = {};

    roman_add(sum, ARRAY_LENGTH(sum),  summand1, summand2); 

    ck_assert_str_eq(sum, "IX");
} END_TEST

START_TEST(XXV_plus_XXV_equals_L) { 
    char summand1[] = "XXV";
    char summand2[] = "XXV";
    char sum[2] = {};

    roman_add(sum, ARRAY_LENGTH(sum),  summand1, summand2); 

    ck_assert_str_eq(sum, "L");
} END_TEST

START_TEST(L_plus_L_equals_C) { 
    char summand1[] = "L";
    char summand2[] = "L";
    char sum[2] = {};

    roman_add(sum, ARRAY_LENGTH(sum),  summand1, summand2); 

    ck_assert_str_eq(sum, "C");
} END_TEST

START_TEST(CCLXXXIX_plus_CDVII_equals_DCXCVI) { 
    char summand1[] = "CCLXXXIX";
    char summand2[] = "CDVII";
    char sum[7] = {};

    roman_add(sum, ARRAY_LENGTH(sum),  summand1, summand2); 

    ck_assert_str_eq(sum, "DCXCVI");
} END_TEST

START_TEST(D_plus_D_equals_M) { 
    char summand1[] = "D";
    char summand2[] = "D";
    char sum[2] = {};

    roman_add(sum, ARRAY_LENGTH(sum),  summand1, summand2); 

    ck_assert_str_eq(sum, "M");
} END_TEST

START_TEST(M_plus_I_equals_MI) { 
    char summand1[] = "M";
    char summand2[] = "I";
    char sum[3] = {};

    roman_add(sum, ARRAY_LENGTH(sum),  summand1, summand2); 

    ck_assert_str_eq(sum, "MI");
} END_TEST

START_TEST(II_minus_I_equals_I) { 
    char minuend[] = "II";
    char suptrhend[] = "I";
    char difference[2] = {};

    roman_subtract(difference, ARRAY_LENGTH(difference), minuend, suptrhend); 

    ck_assert_str_eq(difference, "I");
} END_TEST

START_TEST(MMCDXXI_minus_CLIX_equals_MMCCLXII) { 
    char minuend[] = "MMCDXXI";
    char suptrhend[] = "CLIX";
    char difference[9] = {};

    roman_subtract(difference, ARRAY_LENGTH(difference), minuend, suptrhend); 

    ck_assert_str_eq(difference, "MMCCLXII");
} END_TEST

START_TEST(addition_returns_an_empty_string_when_the_sum_is_not_large_enough) { 
    char summand1[] = "V";
    char summand2[] = "III";
    char sum[2] = { };

    roman_add(sum, ARRAY_LENGTH(sum),  summand1, summand2); 

    ck_assert_str_eq(sum, "");
} END_TEST

int main() {
    Suite *s = suite_create("Arithmatic");
    TCase *tc_add = tcase_create("Addition");
    TCase *tc_subtract = tcase_create("Subtraction");
    TCase *tc_error_checks = tcase_create("Errors");
    SRunner *sr = srunner_create(s);

    int num_fails;

    suite_add_tcase(s, tc_add);
    suite_add_tcase(s, tc_subtract);
    suite_add_tcase(s, tc_error_checks);

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

    tcase_add_test(tc_subtract, II_minus_I_equals_I);
    tcase_add_test(tc_subtract, MMCDXXI_minus_CLIX_equals_MMCCLXII);

    tcase_add_test(tc_error_checks, addition_returns_an_empty_string_when_the_sum_is_not_large_enough);

    srunner_run_all(sr, CK_NORMAL);
    num_fails = srunner_ntests_failed(sr);
    srunner_free(sr);

    return num_fails == 0 ? 0 : 1;
}
