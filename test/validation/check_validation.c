#include <check.h>

#include "../../src/validation.h"

#include "validation_tests.c"

int main() {
    Suite *s = suite_create("Validation");
    TCase *tc_validation = tcase_create("Validation");
    SRunner *sr = srunner_create(s);

    int num_fails;

    suite_add_tcase(s, tc_validation);

    tcase_add_test(tc_validation, I_is_considered_valid);
    tcase_add_test(tc_validation, Z_is_considered_invalid);
    tcase_add_test(tc_validation, XI_is_considered_valid);
    tcase_add_test(tc_validation, XZ_is_considered_invalid);
    tcase_add_test(tc_validation, Dinosaurs_is_considered_invalid);

    tcase_add_test(tc_validation, MMXLVI_is_considered_valid);
    tcase_add_test(tc_validation, IXI_is_considered_invalid);

    srunner_run_all(sr, CK_NORMAL);
    num_fails = srunner_ntests_failed(sr);
    srunner_free(sr);

    return num_fails == 0 ? 0 : 1;
}
