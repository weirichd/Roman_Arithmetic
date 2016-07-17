START_TEST(one_converts_to_I) {
    char expected[] = "I";
    char actual[2] = { };

    arabic_to_roman(actual, ARRAY_LENGTH(actual), 1);
    ck_assert_str_eq(actual, expected);
} END_TEST
