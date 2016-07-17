START_TEST(I_is_considered_valid) {
    int validation_result = is_a_valid_roman_numeral("I");

    ck_assert(validation_result); 
} END_TEST

START_TEST(Z_is_considered_invalid) {
    int validation_result = is_a_valid_roman_numeral("Z");

    ck_assert(!validation_result); 
} END_TEST

START_TEST(XI_is_considered_valid) {
    int validation_result = is_a_valid_roman_numeral("XI");

    ck_assert(validation_result); 
} END_TEST
