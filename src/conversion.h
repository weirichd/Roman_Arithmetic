#include <string.h> /* For strlen, strncat, strncmp, strcpy, memset */

#include "numeral_map.h"

static const size_t LONGEST_POSSIBLE_ROMAN_NUMERAL_SIZE = sizeof("MMMDCCCLXXXVIII");

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
