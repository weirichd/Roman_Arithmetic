#include "romarth.h"
#include <string.h> /* For strlen, strncat, memset */

static int roman_to_arabic(const char *const numeral);
static char *arabic_to_roman(char *dest, size_t dest_size, int arabic_number);

inline static int roman_char_to_arabic(const char roman_symbol);
/* inline static int concat_place_value(char *const dest, const size_t dest_size, const int arabic_numeral, const int place);
inline static char arabic_to_roman_char(const int arabic_value);
inline static void additive_place_value(char *const dest, const int digit, const int place);
inline static void subtractive_place_value(char *const dest, const int digit, const int place);
inline static int there_is_not_enough_room_to_perform_a_safe_concat(const char *const dest, const size_t dest_size, const char *const src);
inline static int is_subtractive_digit(const int digit);
inline static int is_five_minus_one_case(const int digit); */

typedef struct RomanMapEntry {
    char roman_symbol[2];
    int arabic_value;
} RomanMapEntry;

static const RomanMapEntry roman_map[] = {
    { .roman_symbol = "M", .arabic_value = 1000},
    { .roman_symbol = "D", .arabic_value = 500},
    { .roman_symbol = "C", .arabic_value = 100},
    { .roman_symbol = "L", .arabic_value = 50},
    { .roman_symbol = "X", .arabic_value = 10},
    { .roman_symbol = "V", .arabic_value = 5},
    { .roman_symbol = "I", .arabic_value = 1},
};

static const size_t ROMAN_MAP_SIZE = sizeof(roman_map)/sizeof(roman_map[0]);

/*
static const int largest_possible_place_value = 1000;
#define LARGEST_POSSIBLE_PLACE_VALUE_SIZE 4
*/

static const int LARGEST_NUMERAL_THAT_CAN_BE_EXPRESSED = 3999;

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

static int roman_to_arabic(const char *const numeral) {
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

static char *arabic_to_roman(char *const dest, const size_t dest_size, const int arabic_number) {
    int remaining = arabic_number;

    char* dest_index = dest;

    for(int i = 0; i < ROMAN_MAP_SIZE; i++) {
        while(remaining >= roman_map[i].arabic_value) {
            strncat(dest_index, roman_map[i].roman_symbol, strlen(roman_map[i].roman_symbol));

            remaining -= roman_map[i].arabic_value;

            dest_index++;
        }
    }   

/*
    for(int place = largest_possible_place_value; place >= 1; place /= 10) {
        int concat_was_successful = concat_place_value(dest, dest_size, arabic_number, place);

        if(!concat_was_successful) {
            memset(dest, 0, dest_size);
            return dest;
        }
    }
*/
    return dest;
}

inline static int roman_char_to_arabic(const char roman_symbol) {
    for(int i = 0; i < ROMAN_MAP_SIZE; i++) {
        if(roman_symbol == roman_map[i].roman_symbol[0])
            return roman_map[i].arabic_value;
    }

    return 0;
}

/*
inline static int concat_place_value(char *const dest, const size_t dest_size, const int arabic_numeral, const int place) {
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

inline static int is_subtractive_digit(const int digit) {
    return digit % 5 == 4;
}

inline static int there_is_not_enough_room_to_perform_a_safe_concat(const char *const dest, const size_t dest_size, const char *const src) {
    return strlen(dest) + strlen(src) > dest_size - 1;
}

inline static void additive_place_value(char *const dest, const int digit, const int place) {
    int number_of_ones = digit % 5;
    int number_of_fives = digit / 5;

    char one_character = arabic_to_roman_char(place);
    char five_character = arabic_to_roman_char(5 * place);

    int offset = 0;

    if(number_of_fives) {
        dest[0] = five_character;
        offset = 1;
    }

    memset(dest + offset, one_character, number_of_ones);
}

inline static void subtractive_place_value(char *const dest, const int digit, const int place) {
    char one_character  = arabic_to_roman_char( 1 * place);
    char five_character = arabic_to_roman_char( 5 * place);
    char ten_character  = arabic_to_roman_char(10 * place);

    dest[0] = one_character;

    if(is_five_minus_one_case(digit))
        dest[1] = five_character;
    else
        dest[1] = ten_character;
}

inline static char arabic_to_roman_char(const int arabic_value) {
    char result = '\0';

    for(int i = 0; i < roman_map_size; i++) {
        if(arabic_value == roman_map[i].arabic_value)
            result = roman_map[i].roman_symbol[0];

    }

    return result;
}

inline static int is_five_minus_one_case(const int digit) {
    return digit == 4;
}
*/
