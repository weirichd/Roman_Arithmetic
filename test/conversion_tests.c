START_TEST(I_converts_to_one) { 
    int expected = 1;
    int actual = roman_to_arabic("I");

    ck_assert_int_eq(actual, expected);
} END_TEST

START_TEST(II_converts_to_two) { 
    int expected = 2;
    int actual = roman_to_arabic("II");

    ck_assert_int_eq(actual, expected);
} END_TEST

START_TEST(V_converts_to_five) { 
    int expected = 5;
    int actual = roman_to_arabic("V");

    ck_assert_int_eq(actual, expected);
} END_TEST

START_TEST(VII_converts_to_seven) { 
    int expected = 7;
    int actual = roman_to_arabic("VII");

    ck_assert_int_eq(actual, expected);
} END_TEST

START_TEST(X_converts_to_ten) { 
    int expected = 10;
    int actual = roman_to_arabic("XI");

    ck_assert_int_eq(actual, expected);
} END_TEST

/* This is only included to get rid of the unused error for arabic_to_roman
 * For now this test will do NOTHING
 */
START_TEST(one_converts_to_I) {
    // char expected[] = "I";
    char actual[2] = { };

    arabic_to_roman(actual, ARRAY_LENGTH(actual), 1);
    // ck_assert_str_eq(actual, expected);
} END_TEST
