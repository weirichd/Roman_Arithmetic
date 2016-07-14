#include "romarth.h"
#include <string.h> /* For strlen, strncat, strncmp, memset */

static int roman_to_arabic(const char *const numeral);
static void arabic_to_roman(char * const dest, size_t dest_size, int arabic_number);

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

inline static const RomanMapEntry *find_map_element(const char *roman_symbol);
inline static void append_symbols_to_string(char *const dest, const char *const symbol, const int amount);

static const size_t ROMAN_MAP_SIZE = sizeof(ROMAN_MAP)/sizeof(RomanMapEntry);

static const int LARGEST_NUMERAL_THAT_CAN_BE_EXPRESSED = 3999;

char *roman_add(char *const sum, const size_t sum_size, const char *const summand1, const char *const summand2) {
    if(sum == NULL || summand1 == NULL || summand2 == NULL)
        return NULL;

    int a = roman_to_arabic(summand1);
    int b = roman_to_arabic(summand2);

    memset(sum, 0, sum_size);

    if(a + b <= LARGEST_NUMERAL_THAT_CAN_BE_EXPRESSED) 
        arabic_to_roman(sum, sum_size, a + b);

    return sum;
}

char *roman_subtract(char *const difference, const size_t difference_size, const char *const minuend, const char *const suptrahend) {
    if(difference == NULL || minuend == NULL || suptrahend == NULL)
        return NULL;

    int a = roman_to_arabic(minuend);
    int b = roman_to_arabic(suptrahend);

    memset(difference, 0, difference_size);

    if(a > b)
        arabic_to_roman(difference, difference_size, a - b);

    return difference;
}

static int roman_to_arabic(const char *const numeral) {
    int arabic_result = 0;

    int numeral_offset = 0;

    while(numeral[numeral_offset] != '\0') {
        const RomanMapEntry *current_entry = find_map_element(numeral + numeral_offset);

        arabic_result += current_entry->arabic_value;

        numeral_offset += strlen(current_entry->roman_symbol);
    }

    return arabic_result;
}

static void arabic_to_roman(char *const dest, const size_t dest_size, const int arabic_number) {
    int remaining = arabic_number;

    for(int i = 0; i < ROMAN_MAP_SIZE; i++) {
        const char *roman_symbol = ROMAN_MAP[i].roman_symbol;
        int arabic_value = ROMAN_MAP[i].arabic_value;

        int number_of_symbols_to_append = remaining / arabic_value;
        int string_size_needed = strlen(dest) + number_of_symbols_to_append * strlen(roman_symbol);

        if(string_size_needed > dest_size - 1) {
            memset(dest, 0, dest_size);
            return;
        }

        append_symbols_to_string(dest, roman_symbol, number_of_symbols_to_append);
        remaining %= arabic_value;
    }   
}

inline static const RomanMapEntry *find_map_element(const char *roman_symbol) {
    for(int i = 0; i < ROMAN_MAP_SIZE; i++) {
        int symbol_len = strlen(ROMAN_MAP[i].roman_symbol);

        if(strncmp(roman_symbol, ROMAN_MAP[i].roman_symbol, symbol_len) == 0)
            return &ROMAN_MAP[i];
    }

    return NULL; 
}

inline static void append_symbols_to_string(char *const dest, const char *const symbol, const int amount) {
    for(int i = 0; i < amount; i++) {
        strcat(dest, symbol);
    }
}
