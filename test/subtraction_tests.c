START_TEST(II_minus_I_equals_I) { 
    char minuend[] = "II";
    char suptrhend[] = "I";
    char difference[2] = {};

    roman_subtract(difference, ARRAY_LENGTH(difference), minuend, suptrhend); 

    ck_assert_str_eq(difference, "I");
} END_TEST

START_TEST(MMCDXXI_minus_CLIX_equals_MMCCLXII) { 
    char minuend[] = "MMCDXXI";
    char suptrhend[] = "CLIX";
    char difference[9] = {};

    roman_subtract(difference, ARRAY_LENGTH(difference), minuend, suptrhend); 

    ck_assert_str_eq(difference, "MMCCLXII");
} END_TEST
