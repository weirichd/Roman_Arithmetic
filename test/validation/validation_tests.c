START_TEST(I_is_considered_valid) {
    int validation_result = is_a_valid_roman_numeral("I");

    ck_assert(validation_result); 
} END_TEST

START_TEST(Z_is_considered_invalid) {
    int validation_result = is_a_valid_roman_numeral("Z");

    ck_assert(!validation_result); 
} END_TEST

START_TEST(XI_is_considered_valid) {
    int validation_result = is_a_valid_roman_numeral("XI");

    ck_assert(validation_result); 
} END_TEST

START_TEST(XZ_is_considered_invalid) {
    int validation_result = is_a_valid_roman_numeral("XZ");

    ck_assert(!validation_result); 
} END_TEST

START_TEST(Dinosaurs_is_considered_invalid) {
    int validation_result = is_a_valid_roman_numeral("Dinosaurs");

    ck_assert(!validation_result); 
} END_TEST

START_TEST(MMXLVI_is_considered_valid) {
    int validation_result = is_a_valid_roman_numeral("MMXLVI");

    ck_assert(validation_result); 
} END_TEST

START_TEST(IXI_is_considered_invalid) {
   int validation_result = is_a_valid_roman_numeral("IXI");

    ck_assert(!validation_result); 
} END_TEST

START_TEST(IVI_is_considered_invalid) {
   int validation_result = is_a_valid_roman_numeral("IVI");

    ck_assert(!validation_result); 
} END_TEST

START_TEST(IM_is_considered_invalid) {
   int validation_result = is_a_valid_roman_numeral("IM");

    ck_assert(!validation_result); 
} END_TEST

START_TEST(VV_is_considered_invalid) {
   int validation_result = is_a_valid_roman_numeral("VV");

    ck_assert(!validation_result); 
} END_TEST

START_TEST(DD_is_considered_invalid) {
   int validation_result = is_a_valid_roman_numeral("DD");

    ck_assert(!validation_result); 
} END_TEST

START_TEST(IXCD_is_considered_invalid) {
   int validation_result = is_a_valid_roman_numeral("IXCD");

    ck_assert(!validation_result); 
} END_TEST
