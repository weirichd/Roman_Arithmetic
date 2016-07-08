#include <check.h>

#include "../src/romarth.h"

START_TEST(I_plus_I_equals_II) { 
    char summand1[] = "I";
    char summand2[] = "I";
    char sum[3] = {};

    roman_add(sum, summand1, summand2); 

    ck_assert_str_eq(sum, "II");
} END_TEST

START_TEST(I_plus_II_equals_III) { 
    char summand1[] = "I";
    char summand2[] = "II";
    char sum[4] = {};

    roman_add(sum, summand1, summand2); 

    ck_assert_str_eq(sum, "III");
} END_TEST

START_TEST(I_plus_V_equals_VI) { 
    char summand1[] = "I";
    char summand2[] = "V";
    char sum[3] = {};

    roman_add(sum, summand1, summand2); 

    ck_assert_str_eq(sum, "VI");
} END_TEST

START_TEST(III_plus_II_equals_V) { 
    char summand1[] = "III";
    char summand2[] = "II";
    char sum[2] = {};

    roman_add(sum, summand1, summand2); 

    ck_assert_str_eq(sum, "V");
} END_TEST

START_TEST(V_plus_V_equals_X) { 
    char summand1[] = "V";
    char summand2[] = "V";
    char sum[2] = {};

    roman_add(sum, summand1, summand2); 

    ck_assert_str_eq(sum, "X");
} END_TEST

START_TEST(XXV_plus_XII_equals_XXXVII) { 
    char summand1[] = "XXV";
    char summand2[] = "XII";
    char sum[7] = {};

    roman_add(sum, summand1, summand2); 

    ck_assert_str_eq(sum, "XXXVII");
} END_TEST

START_TEST(IV_plus_I_equals_V) { 
    char summand1[] = "IV";
    char summand2[] = "I";
    char sum[2] = {};

    roman_add(sum, summand1, summand2); 

    ck_assert_str_eq(sum, "V");
} END_TEST

START_TEST(IX_plus_I_equals_X) { 
    char summand1[] = "IX";
    char summand2[] = "I";
    char sum[2] = {};

    roman_add(sum, summand1, summand2); 

    ck_assert_str_eq(sum, "X");
} END_TEST

START_TEST(II_plus_II_equals_IV) { 
    char summand1[] = "II";
    char summand2[] = "II";
    char sum[3] = {};

    roman_add(sum, summand1, summand2); 

    ck_assert_str_eq(sum, "IV");
} END_TEST

START_TEST(I_plus_VIII_equals_IX) { 
    char summand1[] = "I";
    char summand2[] = "VIII";
    char sum[3] = {};

    roman_add(sum, summand1, summand2); 

    ck_assert_str_eq(sum, "IX");
} END_TEST

START_TEST(XXV_plus_XXV_equals_L) { 
    char summand1[] = "XXV";
    char summand2[] = "XXV";
    char sum[2] = {};

    roman_add(sum, summand1, summand2); 

    ck_assert_str_eq(sum, "L");
} END_TEST

START_TEST(L_plus_L_equals_C) { 
    char summand1[] = "L";
    char summand2[] = "L";
    char sum[2] = {};

    roman_add(sum, summand1, summand2); 

    ck_assert_str_eq(sum, "C");
} END_TEST

START_TEST(CCLXXXIX_plus_CDVII_equals_DCXCVI) { 
    char summand1[] = "CCLXXXIX";
    char summand2[] = "CDVII";
    char sum[2] = {};

    roman_add(sum, summand1, summand2); 

    ck_assert_str_eq(sum, "DCXCVI");
} END_TEST


int main() {
    Suite *s = suite_create("Arithmatic");
    TCase *tc_add = tcase_create("Addition");
    SRunner *sr = srunner_create(s);

    int num_fails;

    suite_add_tcase(s, tc_add);

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

    srunner_run_all(sr, CK_NORMAL);
    num_fails = srunner_ntests_failed(sr);
    srunner_free(sr);

    return num_fails == 0 ? 0 : 1;
}
