#include "romarth.h"
#include <stddef.h> /* For NULL Macro */
#include <string.h> /* For strlen, strcat, memset */

static int roman_to_arabic(char *numeral);
static char *arabic_to_roman(char *dest, int arabic_number);

typedef struct RomanMapEntry {
    char roman_character;
    int arabic_value;
} RomanMapEntry;

static const RomanMapEntry roman_map[] = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000},
};

static const int largest_possible_place_value = 1000;
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

inline static void concat_place_value(char *dest, int arabic_numeral, int place);

static char *arabic_to_roman(char *dest, int arabic_number) {
    for(int place = largest_possible_place_value; place >= 1; place /= 10) 
        concat_place_value(dest, arabic_number, place); 

    return dest;
}

inline static char arabic_to_roman_char(int arabic_value);
inline static void additive_place_value(char *dest, int digit, int place);
inline static void subtractive_place_value(char *dest, int digit, int place);

inline static int is_subtractive_digit(int digit) {
    return digit % 5 == 4;
}

inline static void concat_place_value(char *dest, int arabic_numeral, int place) {
    int this_places_digit = (arabic_numeral / place) % 10;         

    char temp_buffer[4] = { };

    if(!is_subtractive_digit(this_places_digit)) 
        additive_place_value(temp_buffer, this_places_digit, place);
    else
        subtractive_place_value(temp_buffer, this_places_digit, place);

    strcat(dest, temp_buffer);
}

inline static void additive_place_value(char *dest, int digit, int place) {
        int number_of_ones = digit % 5;
        int number_of_fives = digit / 5;

        char one_character = arabic_to_roman_char(place);
        char five_character = arabic_to_roman_char(5 * place);

        if(number_of_fives) {
            dest[0] = five_character;
            dest++;
        }

        memset(dest, one_character, number_of_ones);
}

inline int is_five_minus_one_case(int digit) {
    return digit == 4;
}

inline static void subtractive_place_value(char *dest, int digit, int place) {
    char one_character = arabic_to_roman_char(place);
    char five_character = arabic_to_roman_char(5 * place);
    char ten_character = arabic_to_roman_char(10 * place);

    dest[0] = one_character;

    if(is_five_minus_one_case(digit))
        dest[1] = five_character;
    else
        dest[1] = ten_character;
}

inline static char arabic_to_roman_char(int arabic_value) {
    char result = '\0';

    for(int i = 0; i < roman_map_size; i++) {
        if(arabic_value == roman_map[i].arabic_value)
            result = roman_map[i].roman_character;
    }

    return result;
}
