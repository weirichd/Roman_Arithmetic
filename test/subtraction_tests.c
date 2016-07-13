START_TEST(II_minus_I_equals_I) { 
    char minuend[] = "II";
    char suptrhend[] = "I";
    char difference[2] = {};

    roman_subtract(difference, ARRAY_LENGTH(difference), minuend, suptrhend); 

    ck_assert_str_eq(difference, "I");
} END_TEST

START_TEST(V_minus_II_equals_III) { 
    char minuend[] = "V";
    char suptrhend[] = "II";
    char difference[4] = {};

    roman_subtract(difference, ARRAY_LENGTH(difference), minuend, suptrhend); 

    ck_assert_str_eq(difference, "III");
} END_TEST

START_TEST(X_minus_V_equals_V) { 
    char minuend[] = "X";
    char suptrhend[] = "V";
    char difference[2] = {};

    roman_subtract(difference, ARRAY_LENGTH(difference), minuend, suptrhend); 

    ck_assert_str_eq(difference, "V");
} END_TEST

START_TEST(X_minus_II_equals_VIII) { 
    char minuend[] = "X";
    char suptrhend[] = "II";
    char difference[5] = {};

    roman_subtract(difference, ARRAY_LENGTH(difference), minuend, suptrhend); 

    ck_assert_str_eq(difference, "VIII");
} END_TEST

START_TEST(L_minus_XX_equals_XXX) { 
    char minuend[] = "L";
    char suptrhend[] = "XX";
    char difference[4] = {};

    roman_subtract(difference, ARRAY_LENGTH(difference), minuend, suptrhend); 

    ck_assert_str_eq(difference, "XXX");
} END_TEST

START_TEST(C_minus_L_equals_L) { 
    char minuend[] = "C";
    char suptrhend[] = "L";
    char difference[2] = {};

    roman_subtract(difference, ARRAY_LENGTH(difference), minuend, suptrhend); 

    ck_assert_str_eq(difference, "L");
} END_TEST

START_TEST(D_minus_CC_equals_CCC) { 
    char minuend[] = "D";
    char suptrhend[] = "CC";
    char difference[4] = {};

    roman_subtract(difference, ARRAY_LENGTH(difference), minuend, suptrhend); 

    ck_assert_str_eq(difference, "CCC");
} END_TEST

START_TEST(M_minus_D_equals_D) { 
    char minuend[] = "M";
    char suptrhend[] = "D";
    char difference[2] = {};

    roman_subtract(difference, ARRAY_LENGTH(difference), minuend, suptrhend); 

    ck_assert_str_eq(difference, "D");
} END_TEST

START_TEST(V_minus_I_equals_IV) { 
    char minuend[] = "V";
    char suptrhend[] = "I";
    char difference[3] = {};

    roman_subtract(difference, ARRAY_LENGTH(difference), minuend, suptrhend); 

    ck_assert_str_eq(difference, "IV");
} END_TEST

START_TEST(X_minus_I_equals_IX) { 
    char minuend[] = "X";
    char suptrhend[] = "I";
    char difference[3] = {};

    roman_subtract(difference, ARRAY_LENGTH(difference), minuend, suptrhend); 

    ck_assert_str_eq(difference, "IX");
} END_TEST

START_TEST(L_minus_X_equals_XL) { 
    char minuend[] = "L";
    char suptrhend[] = "X";
    char difference[3] = {};

    roman_subtract(difference, ARRAY_LENGTH(difference), minuend, suptrhend); 

    ck_assert_str_eq(difference, "XL");
} END_TEST

START_TEST(C_minus_X_equals_XC) { 
    char minuend[] = "C";
    char suptrhend[] = "X";
    char difference[3] = {};

    roman_subtract(difference, ARRAY_LENGTH(difference), minuend, suptrhend); 

    ck_assert_str_eq(difference, "XC");
} END_TEST

START_TEST(D_minus_C_equals_CD) { 
    char minuend[] = "D";
    char suptrhend[] = "C";
    char difference[3] = {};

    roman_subtract(difference, ARRAY_LENGTH(difference), minuend, suptrhend); 

    ck_assert_str_eq(difference, "CD");
} END_TEST

/*

START_TEST(MMCDXXI_minus_CLIX_equals_MMCCLXII) { 
    char minuend[] = "MMCDXXI";
    char suptrhend[] = "CLIX";
    char difference[9] = {};

    roman_subtract(difference, ARRAY_LENGTH(difference), minuend, suptrhend); 

    ck_assert_str_eq(difference, "MMCCLXII");
} END_TEST
*/
