#include "romarth.h"
#include <string.h> /* For strlen, strncat, memset */

static int roman_to_arabic(const char *const numeral);
static char *arabic_to_roman(char *dest, size_t dest_size, int arabic_number);

typedef struct RomanMapEntry {
    char roman_symbol[3];
    int arabic_value;
} RomanMapEntry;

static const RomanMapEntry ROMAN_MAP[] = {
    { .roman_symbol = "M",  .arabic_value = 1000},
    { .roman_symbol = "CM", .arabic_value = 900},
    { .roman_symbol = "D",  .arabic_value = 500},
    { .roman_symbol = "CD", .arabic_value = 400},
    { .roman_symbol = "C",  .arabic_value = 100},
    { .roman_symbol = "XC", .arabic_value = 90},
    { .roman_symbol = "L",  .arabic_value = 50},
    { .roman_symbol = "XL", .arabic_value = 40},
    { .roman_symbol = "X",  .arabic_value = 10},
    { .roman_symbol = "IX", .arabic_value = 9},
    { .roman_symbol = "V",  .arabic_value = 5},
    { .roman_symbol = "IV", .arabic_value = 4},
    { .roman_symbol = "I",  .arabic_value = 1},
};

static const size_t ROMAN_MAP_SIZE = sizeof(ROMAN_MAP)/sizeof(RomanMapEntry);

static const int LARGEST_NUMERAL_THAT_CAN_BE_EXPRESSED = 3999; // TODO: Can we get this value by testing... instead of just coming up with it here?

char *roman_add(char *const sum, const size_t sum_size, const char *const summand1, const char *const summand2) {
    int a = roman_to_arabic(summand1);
    int b = roman_to_arabic(summand2);

    if(a + b <= LARGEST_NUMERAL_THAT_CAN_BE_EXPRESSED) 
        return arabic_to_roman(sum, sum_size, a + b);
    else
        return memset(sum, 0, sum_size);
}

char *roman_subtract(char *const difference, const size_t difference_size, const char *const minuend, const char *const suptrahend) {
    int a = roman_to_arabic(minuend);
    int b = roman_to_arabic(suptrahend);

    if(a > b)
        return arabic_to_roman(difference, difference_size, a - b);
    else
        return memset(difference, 0, difference_size);
}

inline static int string_starts_with_substring(const char *string, const char *substring) {
    int compare_value = strncmp(string, substring, strlen(substring));

    if(compare_value == 0)
        return 1;
    else
        return 0;
}

static const RomanMapEntry *roman_symbol_to_map_element(const char *roman_symbol) {
    for(int i = 0; i < ROMAN_MAP_SIZE; i++) {
        if(string_starts_with_substring(roman_symbol, ROMAN_MAP[i].roman_symbol))
            return &ROMAN_MAP[i];
    }

    return NULL; 
}

static int roman_to_arabic(const char *const numeral) {
    int arabic_result = 0;

    for(int i = 0; i <  strlen(numeral); i++) {
        arabic_result += roman_symbol_to_map_element(numeral + i)->arabic_value;
        i += strlen(roman_symbol_to_map_element(numeral + i)->roman_symbol) - 1;
    }

    return arabic_result;
}

static char *arabic_to_roman(char *const dest, const size_t dest_size, const int arabic_number) {
    int remaining = arabic_number;

    char* dest_index = dest;

    for(int i = 0; i < ROMAN_MAP_SIZE; i++) {
        while(remaining >= ROMAN_MAP[i].arabic_value) {
            int symbol_len = strlen(ROMAN_MAP[i].roman_symbol);

            if(dest_index - dest > dest_size - 1) {
                memset(dest, 0, dest_size);
                return dest;
            }

            strncat(dest_index, ROMAN_MAP[i].roman_symbol, symbol_len);

            remaining -= ROMAN_MAP[i].arabic_value;

            dest_index += symbol_len;
        }
    }   

    return dest;
}
