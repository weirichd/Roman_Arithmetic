START_TEST(addition_returns_an_empty_string_when_the_sum_array_is_not_large_enough) { 
    char summand1[] = "V";
    char summand2[] = "III";
    char sum[2] = { };

    roman_add(sum, ARRAY_LENGTH(sum),  summand1, summand2); 

    ck_assert_str_eq(sum, "");
} END_TEST

START_TEST(subtraction_returns_an_empty_string_when_the_difference_array_is_not_large_enough) { 
    char minuend[] = "VIII";
    char suptrahend[] = "I";
    char difference[2] = { };

    roman_subtract(difference, ARRAY_LENGTH(difference), minuend, suptrahend); 

    ck_assert_str_eq(difference, "");
} END_TEST

START_TEST(subtraction_returns_an_empty_string_when_the_difference_would_have_been_negative) { 
    char minuend[] = "I";
    char suptrahend[] = "II";
    char difference[2] = { };

    roman_subtract(difference, ARRAY_LENGTH(difference), minuend, suptrahend); 

    ck_assert_str_eq(difference, "");
} END_TEST

START_TEST(addition_returns_an_empty_string_when_the_sum_is_larger_than_we_can_express) { 
    char summand1[] = "MMM";
    char summand2[] = "M";
    char sum[2] = { };

    roman_add(sum, ARRAY_LENGTH(sum),  summand1, summand2); 

    ck_assert_str_eq(sum, "");
} END_TEST

START_TEST(the_caller_can_use_the_same_pointer_for_the_sum_and_the_first_summand_without_errors) { 
    char summand1[] = "III";
    char summand2[3] = { };
 
    summand2[0] = 'I';

    roman_add(summand2, ARRAY_LENGTH(summand2), summand1, summand2); 

    ck_assert_str_eq(summand2, "IV");
} END_TEST

START_TEST(the_caller_can_use_the_same_pointer_for_the_sum_and_the_second_summand_without_errors) { 
    char summand1[3] = { };
    char summand2[] = "III";
 
    summand1[0] = 'I';

    roman_add(summand2, ARRAY_LENGTH(summand2), summand1, summand2); 

    ck_assert_str_eq(summand2, "IV");
} END_TEST

START_TEST(the_caller_can_use_the_same_pointer_for_the_difference_and_the_minuend_without_errors) { 
    char minuend[5] = { };
    char suptrahend[] = "II";
 
    minuend[0] = 'X';

    roman_subtract(minuend, ARRAY_LENGTH(minuend), minuend, suptrahend); 

    ck_assert_str_eq(minuend, "VIII");
} END_TEST

START_TEST(the_caller_can_use_the_same_pointer_for_the_difference_and_the_suptrahend_without_errors) { 
    char minuend[] = "C";
    char suptrahend[5] = { };
 
    suptrahend[0] = 'I';

    roman_subtract(suptrahend, ARRAY_LENGTH(suptrahend), minuend, suptrahend); 

    ck_assert_str_eq(suptrahend, "XCIX");
} END_TEST

START_TEST(passing_a_null_pointer_for_sum_returns_null_without_an_error) { 
    char summand1[] = "I";
    char summand2[] = "I";
    char *sum = NULL;

    ck_assert(roman_add(sum, ARRAY_LENGTH(sum), summand1, summand2) == NULL);
} END_TEST

START_TEST(passing_a_null_pointer_for_summand1_returns_null_without_an_error) { 
    char *summand1 = NULL;
    char summand2[] = "I";
    char sum[2];

    ck_assert(roman_add(sum, ARRAY_LENGTH(sum), summand1, summand2) == NULL);
} END_TEST

START_TEST(passing_a_null_pointer_for_summand2_returns_null_without_an_error) { 
    char summand1[] = "I";
    char *summand2 = NULL;
    char sum[2];

    ck_assert(roman_add(sum, ARRAY_LENGTH(sum), summand1, summand2) == NULL);
} END_TEST

START_TEST(passing_a_null_pointer_for_difference_returns_null_without_an_error) { 
    char minuend[] = "II";
    char suptrahend[] = "I";
    char *difference = NULL;

    ck_assert(roman_subtract(difference, ARRAY_LENGTH(difference), minuend, suptrahend) == NULL);
} END_TEST

START_TEST(passing_a_null_pointer_for_minuend_returns_null_without_an_error) { 
    char *minuend = NULL;
    char suptrahend[] = "I";
    char difference[2];

    ck_assert(roman_subtract(difference, ARRAY_LENGTH(difference), minuend, suptrahend) == NULL);
} END_TEST

START_TEST(passing_a_null_pointer_for_suptrahend_returns_null_without_an_error) { 
    char minuend[] = "II";
    char *suptrahend = NULL;
    char difference[2];

    ck_assert(roman_subtract(difference, ARRAY_LENGTH(difference), minuend, suptrahend) == NULL);
} END_TEST

START_TEST(passing_an_invalid_numeral_for_summand1_returns_an_empty_string) { 
    char summand1[] = "David";
    char summand2[] = "I";
    char sum[16] = {};

    roman_add(sum, ARRAY_LENGTH(sum),  summand1, summand2); 

    ck_assert_str_eq(sum, "");
} END_TEST

START_TEST(passing_an_invalid_numeral_for_summand2_returns_an_empty_string) { 
    char summand1[] = "I";
    char summand2[] = "VVVVVVV";
    char sum[16] = {};

    roman_add(sum, ARRAY_LENGTH(sum),  summand1, summand2); 

    ck_assert_str_eq(sum, "");
} END_TEST

START_TEST(passing_an_invalid_numeral_for_minuend_returns_an_empty_string) { 
    char minuend[] = "IXI";
    char suptrahend[] = "I";
    char difference[16] = {};

    roman_subtract(difference, ARRAY_LENGTH(difference), minuend, suptrahend); 

    ck_assert_str_eq(difference, "");
} END_TEST

START_TEST(passing_an_invalid_numeral_for_suptrahend_returns_an_empty_string) { 
    char minuend[] = "MM";
    char suptrahend[] = "IM";
    char difference[16] = {};

    roman_subtract(difference, ARRAY_LENGTH(difference), minuend, suptrahend); 

    ck_assert_str_eq(difference, "");
} END_TEST
