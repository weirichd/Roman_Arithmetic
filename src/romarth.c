#include "romarth.h"
#include <stddef.h> /* For NULL Macro */
#include <string.h> /* For strlen, memset */

static int roman_to_arabic(char *numeral);
static char *arabic_to_roman(char *dest, int arabic_number);

typedef struct RomanMapEntry {
    char roman_character;
    int arabic_value;
} RomanMapEntry;

static const RomanMapEntry roman_map[] = {
    {'I', 1},
    {'V', 5},
    {'X', 10}
};

static const size_t roman_map_size = sizeof(roman_map)/sizeof(roman_map[0]);

char *roman_add(char *sum, char *summand1, char *summand2) {
    int a = roman_to_arabic(summand1);
    int b = roman_to_arabic(summand2);
    return arabic_to_roman(sum, a + b);
}

char *roman_subtract(char *differene, char *minuend, char *suptrahend) {
    return NULL;
}

inline static int roman_char_to_arabic(char roman_character);

static int roman_to_arabic(char *numeral) {
    int arabic_result = 0;

    int previous = 0;
    for(int i = strlen(numeral) - 1; i >= 0; i--) {
        int current = roman_char_to_arabic(numeral[i]);

        if(current >= previous)
            arabic_result += current;
        else
            arabic_result -= current;

        previous = current;
    }
    
    return arabic_result;
}

inline static int roman_char_to_arabic(char roman_character) {
    int result = 0;

    for(int i = 0; i < roman_map_size; i++) {
        if(roman_character == roman_map[i].roman_character)
            result = roman_map[i].arabic_value;
    }

    return result;
}

inline static char arabic_to_roman_char(int arabic_value);

static char *arabic_to_roman(char *dest, int arabic_number) {
    int number_of_10s = arabic_number / 10;
    int remainder_for_10s = arabic_number % 10;
    int number_of_1s = remainder_for_10s % 5;
    int number_of_5s = remainder_for_10s / 5;

    memset(dest, arabic_to_roman_char(10), number_of_10s);
    memset(dest + number_of_10s, arabic_to_roman_char(5), number_of_5s);
    memset(dest + number_of_10s + number_of_5s, arabic_to_roman_char(1), number_of_1s);

    *(dest + number_of_1s + number_of_5s + number_of_10s) = '\0';

    return dest;
}

inline static char arabic_to_roman_char(int arabic_value) {
    char result = '\0';

    for(int i = 0; i < roman_map_size; i++) {
        if(arabic_value == roman_map[i].arabic_value)
            result = roman_map[i].roman_character;
    }

    return result;
}
