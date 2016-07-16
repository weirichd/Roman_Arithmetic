START_TEST(I_converts_to_one) { 
    char roman_nuneral[] = "I";

    int expected = 1;
    int actual = roman_to_arabic(roman_nuneral);

    ck_assert_int_eq(actual, expected);
} END_TEST

/* This is only included to get rid of the unused error for arabic_to_roman
 * For now this test will do NOTHING
 */
START_TEST(one_converts_to_I) {
    int arabic_value = 1;
    
    // char expected[] = "I";
    char actual[2] = { };

    arabic_to_roman(actual, ARRAY_LENGTH(actual), arabic_value);

    // ck_assert_str_eq(actual, expected);
} END_TEST
