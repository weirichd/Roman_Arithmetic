#include <check.h>

#include "../src/conversion.h"

#include "array_length_macro.h"
#include "conversion_tests.c"

int main() {
    Suite *s = suite_create("Converison");
    TCase *tc_roman_to_arabic = tcase_create("Roman to Arabic");
    TCase *tc_arabic_to_roman = tcase_create("Arabic to Roman");
    SRunner *sr = srunner_create(s);

    int num_fails;

    suite_add_tcase(s, tc_roman_to_arabic);

    tcase_add_test(tc_roman_to_arabic, I_converts_to_one);
    tcase_add_test(tc_roman_to_arabic, II_converts_to_two);
    tcase_add_test(tc_roman_to_arabic, V_converts_to_five);
    tcase_add_test(tc_roman_to_arabic, VII_converts_to_seven);

    // For now, this test does nothing, and is not eveb added to the suite, this is only to prevent unused function errors
    tcase_add_test(tc_arabic_to_roman, one_converts_to_I);

    srunner_run_all(sr, CK_NORMAL);
    num_fails = srunner_ntests_failed(sr);
    srunner_free(sr);

    return num_fails == 0 ? 0 : 1;
}
