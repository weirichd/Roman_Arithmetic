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

START_TEST(sixty_six_converts_to_LXVI) {
    char expected[] = "LXVI";
    char actual[5] = { };

    arabic_to_roman(actual, ARRAY_LENGTH(actual), 66);
    ck_assert_str_eq(actual, expected);
} END_TEST

START_TEST(three_hundred_converts_to_CCC) {
    char expected[] = "CCC";
    char actual[4] = { };

    arabic_to_roman(actual, ARRAY_LENGTH(actual), 300);
    ck_assert_str_eq(actual, expected);
} END_TEST

START_TEST(seven_hundred_thirty_two_converts_to_DCCXXXII) {
    char expected[] = "DCCXXXII";
    char actual[9] = { };

    arabic_to_roman(actual, ARRAY_LENGTH(actual), 732);
    ck_assert_str_eq(actual, expected);
} END_TEST

START_TEST(two_thousand_converts_to_MM) {
    char expected[] = "MM";
    char actual[3] = { };

    arabic_to_roman(actual, ARRAY_LENGTH(actual), 2000);
    ck_assert_str_eq(actual, expected);
} END_TEST


