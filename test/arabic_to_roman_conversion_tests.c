START_TEST(one_converts_to_I) {
    char expected[] = "I";
    char actual[2] = { };

    arabic_to_roman(actual, ARRAY_LENGTH(actual), 1);
    ck_assert_str_eq(actual, expected);
} END_TEST

START_TEST(two_converts_to_II) {
    char expected[] = "II";
    char actual[3] = { };

    arabic_to_roman(actual, ARRAY_LENGTH(actual), 2);
    ck_assert_str_eq(actual, expected);
} END_TEST

START_TEST(five_converts_to_V) {
    char expected[] = "V";
    char actual[2] = { };

    arabic_to_roman(actual, ARRAY_LENGTH(actual), 5);
    ck_assert_str_eq(actual, expected);
} END_TEST

START_TEST(twelve_converts_to_XII) {
    char expected[] = "XII";
    char actual[4] = { };

    arabic_to_roman(actual, ARRAY_LENGTH(actual), 12);
    ck_assert_str_eq(actual, expected);
} END_TEST

