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
    {'V', 5}
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

    for(int i = 0; i < strlen(numeral); i++) {
        arabic_result += roman_char_to_arabic(numeral[i]);
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


static char *arabic_to_roman(char *dest, int arabic_number) {
    int number_of_Is = arabic_number % 5;
    int number_of_Vs = arabic_number / 5;

    memset(dest,'V', number_of_Vs);
    memset(dest + number_of_Vs, 'I', number_of_Is);

    return dest;
}
