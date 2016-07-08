START_TEST(addition_returns_an_empty_string_when_the_sum_is_not_large_enough) { 
    char summand1[] = "V";
    char summand2[] = "III";
    char sum[2] = { };

    roman_add(sum, ARRAY_LENGTH(sum),  summand1, summand2); 

    ck_assert_str_eq(sum, "");
} END_TEST

START_TEST(subtraction_returns_an_empty_string_when_the_difference_is_not_large_enough) { 
    char minuend[] = "VIII";
    char suptrhend[] = "I";
    char difference[2] = { };

    roman_subtract(difference, ARRAY_LENGTH(difference), minuend, suptrhend); 

    ck_assert_str_eq(difference, "");
} END_TEST
