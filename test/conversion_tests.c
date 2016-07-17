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
    int actual = roman_to_arabic("X");

    ck_assert_int_eq(actual, expected);
} END_TEST

START_TEST(L_converts_to_fifty) { 
    int expected = 50;
    int actual = roman_to_arabic("L");

    ck_assert_int_eq(actual, expected);
} END_TEST

START_TEST(C_converts_to_hundred) { 
    int expected = 100;
    int actual = roman_to_arabic("C");

    ck_assert_int_eq(actual, expected);
} END_TEST

START_TEST(D_converts_to_hundred) { 
    int expected = 500;
    int actual = roman_to_arabic("D");

    ck_assert_int_eq(actual, expected);
} END_TEST

START_TEST(M_converts_to_thousand) { 
    int expected = 1000;
    int actual = roman_to_arabic("M");

    ck_assert_int_eq(actual, expected);
} END_TEST

START_TEST(MMXVI_converts_to_two_thousand_sixteen) { 
    int expected = 2016;
    int actual = roman_to_arabic("MMXVI");

    ck_assert_int_eq(actual, expected);
} END_TEST

START_TEST(XI_converts_to_eleven) { 
    int expected = 11;
    int actual = roman_to_arabic("XI");

    ck_assert_int_eq(actual, expected);
} END_TEST

START_TEST(DLV_converts_to_five_hundred_fifty_five) { 
    int expected = 555;
    int actual = roman_to_arabic("DLV");

    ck_assert_int_eq(actual, expected);
} END_TEST

START_TEST(CI_converts_to_one_hundred_one) { 
    int expected = 101;
    int actual = roman_to_arabic("CI");

    ck_assert_int_eq(actual, expected);
} END_TEST

START_TEST(IV_converts_to_four) { 
    int expected = 4;
    int actual = roman_to_arabic("IV");

    ck_assert_int_eq(actual, expected);
} END_TEST

START_TEST(LIX_converts_to_fifty_nine) { 
    int expected = 59;
    int actual = roman_to_arabic("LIX");

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
