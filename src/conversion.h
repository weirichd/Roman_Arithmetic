#include <string.h> /* For strlen, strncat, strncmp, memset */

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

static const size_t LONGEST_POSSIBLE_ROMAN_NUMERAL_SIZE = sizeof("MMMDCCCLXXXVIII");

inline static const RomanMapEntry *find_map_element(const char *roman_symbol);
inline static void append_symbols_to_string(char *const dest, const char *const symbol, const int amount);

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

inline static const RomanMapEntry *find_map_element(const char *roman_symbol) {
    for(int i = 0; i < ROMAN_MAP_SIZE; i++) {
        int symbol_len = strlen(ROMAN_MAP[i].roman_symbol);

        if(strncmp(roman_symbol, ROMAN_MAP[i].roman_symbol, symbol_len) == 0)
            return &ROMAN_MAP[i];
    }

    return NULL; 
}

static void arabic_to_roman(char *const dest, const size_t dest_size, const int arabic_number) {
    int remaining = arabic_number;

    char temp_char_buffer[LONGEST_POSSIBLE_ROMAN_NUMERAL_SIZE];
    memset(temp_char_buffer, 0, LONGEST_POSSIBLE_ROMAN_NUMERAL_SIZE);

    for(int i = 0; i < ROMAN_MAP_SIZE; i++) {
        const char *roman_symbol = ROMAN_MAP[i].roman_symbol;
        int arabic_value = ROMAN_MAP[i].arabic_value;

        int number_of_symbols_to_append = remaining / arabic_value;

        append_symbols_to_string(temp_char_buffer, roman_symbol, number_of_symbols_to_append);
        remaining %= arabic_value;
    }   

    if(strlen(temp_char_buffer) <= dest_size - 1)
        strcpy(dest, temp_char_buffer);
    else
        memset(dest, 0, dest_size);
}

inline static void append_symbols_to_string(char *const dest, const char *const symbol, const int amount) {
    for(int i = 0; i < amount; i++) {
        strcat(dest, symbol);
    }
}
