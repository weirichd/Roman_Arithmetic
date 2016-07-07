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

    srunner_run_all(sr, CK_NORMAL);
    num_fails = srunner_ntests_failed(sr);
    srunner_free(sr);

    return num_fails == 0 ? 0 : 1;
}
