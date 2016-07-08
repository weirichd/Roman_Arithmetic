#include "romarth.h"
#include <string.h> /* For strlen, strncat, memset */

static int roman_to_arabic(char *numeral);
static char *arabic_to_roman(char *dest, size_t dest_size, int arabic_number);

inline static int roman_char_to_arabic(char roman_character);
inline static int concat_place_value(char *dest, size_t dest_size, int arabic_numeral, int place);
inline static char arabic_to_roman_char(int arabic_value);
inline static void additive_place_value(char *dest, int digit, int place);
inline static void subtractive_place_value(char *dest, int digit, int place);
inline static int there_is_not_enough_room_to_perform_a_safe_concat(char *dest, size_t dest_size, char *src);
inline static int is_subtractive_digit(int digit);
inline static int is_five_minus_one_case(int digit);

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

static const size_t roman_map_size = sizeof(roman_map)/sizeof(roman_map[0]);

static const int largest_possible_place_value = 1000;
#define LARGEST_POSSIBLE_PLACE_VALUE_SIZE 4

char *roman_add(char *sum, size_t sum_size, char *summand1, char *summand2) {
    int a = roman_to_arabic(summand1);
    int b = roman_to_arabic(summand2);
    return arabic_to_roman(sum, sum_size, a + b);
}

char *roman_subtract(char *differene, size_t difference_size, char *minuend, char *suptrahend) {
    int a = roman_to_arabic(minuend);
    int b = roman_to_arabic(suptrahend);
    if(a > b)
        return arabic_to_roman(differene, difference_size, a - b);
    else
        return memset(differene, 0, difference_size);
}

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

static char *arabic_to_roman(char *dest, size_t dest_size, int arabic_number) {
    for(int place = largest_possible_place_value; place >= 1; place /= 10) {
        int concat_was_successful = concat_place_value(dest, dest_size, arabic_number, place);

        if(!concat_was_successful) {
            memset(dest, 0, dest_size);
            return dest;
        }
    }

    return dest;
}

inline static int roman_char_to_arabic(char roman_character) {
    int result = 0;

    for(int i = 0; i < roman_map_size; i++) {
        if(roman_character == roman_map[i].roman_character)
            result = roman_map[i].arabic_value;
    }

    return result;
}

inline static int concat_place_value(char *dest, size_t dest_size, int arabic_numeral, int place) {
    int this_places_digit = (arabic_numeral / place) % 10;         

    char temp_buffer[LARGEST_POSSIBLE_PLACE_VALUE_SIZE] = { };

    if(!is_subtractive_digit(this_places_digit)) 
        additive_place_value(temp_buffer, this_places_digit, place);
    else
        subtractive_place_value(temp_buffer, this_places_digit, place);

    if(there_is_not_enough_room_to_perform_a_safe_concat(dest, dest_size, temp_buffer))
        return 0;

    strncat(dest, temp_buffer, LARGEST_POSSIBLE_PLACE_VALUE_SIZE);

    return 1;
}

inline static int is_subtractive_digit(int digit) {
    return digit % 5 == 4;
}

inline static int there_is_not_enough_room_to_perform_a_safe_concat(char *dest, size_t dest_size, char *src) {
    return strlen(dest) + strlen(src) > dest_size - 1;
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

inline static void subtractive_place_value(char *dest, int digit, int place) {
    char one_character  = arabic_to_roman_char( 1 * place);
    char five_character = arabic_to_roman_char( 5 * place);
    char ten_character  = arabic_to_roman_char(10 * place);

    dest[0] = one_character;

    if(is_five_minus_one_case(digit))
        dest[1] = five_character;
    else
        dest[1] = ten_character;
}

inline static int is_five_minus_one_case(int digit) {
    return digit == 4;
}

inline static char arabic_to_roman_char(int arabic_value) {
    char result = '\0';

    for(int i = 0; i < roman_map_size; i++) {
        if(arabic_value == roman_map[i].arabic_value)
            result = roman_map[i].roman_character;
    }

    return result;
}
