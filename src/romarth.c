#include "romarth.h"
#include "conversion.h"
#include "validation.h"

#include <string.h> /* memset */

static const int LARGEST_NUMERAL_THAT_CAN_BE_EXPRESSED = 3999;

char *roman_add(char *const sum, const size_t sum_size, const char *const summand1, const char *const summand2) {
    if(sum == NULL || summand1 == NULL || summand2 == NULL)
        return NULL;

    if(is_a_valid_roman_numeral(summand1) && is_a_valid_roman_numeral(summand2)) {
        int a = roman_to_arabic(summand1);
        int b = roman_to_arabic(summand2);

        memset(sum, 0, sum_size);

        if(a + b <= LARGEST_NUMERAL_THAT_CAN_BE_EXPRESSED) 
            arabic_to_roman(sum, sum_size, a + b);
     } else
        memset(sum, 0, sum_size);

    return sum;
}

char *roman_subtract(char *const difference, const size_t difference_size, const char *const minuend, const char *const suptrahend) {
    if(difference == NULL || minuend == NULL || suptrahend == NULL)
        return NULL;

    if(is_a_valid_roman_numeral(minuend) && is_a_valid_roman_numeral(suptrahend)) {
        int a = roman_to_arabic(minuend);
        int b = roman_to_arabic(suptrahend);

        memset(difference, 0, difference_size);

        if(a > b)
            arabic_to_roman(difference, difference_size, a - b);
     } else
        memset(difference, 0, difference_size);
    return difference;
}
