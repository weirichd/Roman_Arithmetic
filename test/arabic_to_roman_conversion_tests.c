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

START_TEST(four_hundered_forty_four_converts_to_CDXLIV) {
    char expected[] = "CDXLIV";
    char actual[7] = { };

    arabic_to_roman(actual, ARRAY_LENGTH(actual), 444);
    ck_assert_str_eq(actual, expected);
} END_TEST

START_TEST(nine_hundered_ninety_nine_converts_to_CMXCIX) {
    char expected[] = "CMXCIX";
    char actual[7] = { };

    arabic_to_roman(actual, ARRAY_LENGTH(actual), 999);
    ck_assert_str_eq(actual, expected);
} END_TEST

START_TEST(arabic_to_roman_returns_an_empty_string_when_there_isnt_enough_room_in_dest) {
    char expected[] = "";
    char actual[1] = { };

    arabic_to_roman(actual, ARRAY_LENGTH(actual), 3333);
    ck_assert_str_eq(actual, expected);
} END_TEST

START_TEST(the_longest_possible_roman_numeral_will_convert_properly) {
    char expected[] = "MMMDCCLXXVII";
    char actual[16] = { };

    arabic_to_roman(actual, ARRAY_LENGTH(actual), 3888);
    ck_assert_str_eq(actual, expected);

} END_TEST
