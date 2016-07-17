#include "romarth.h"
#include "conversion.h"
#include "validation.h"

#include <string.h> /* memset */

typedef int (*Operation)(int a, int b);

static char *roman_Operation(char *const result, const size_t result_size, const char *const operand1, const char *const operand2, Operation operation);

static int add(int a, int b) {
    return a + b;
}

static int subtract(int a, int b) {
    return a - b;
}

char *roman_add(char *const sum, const size_t sum_size, const char *const summand1, const char *const summand2) {
    return roman_Operation(sum, sum_size, summand1, summand2, add);
}

char *roman_subtract(char *const difference, const size_t difference_size, const char *const minuend, const char *const suptrahend) {
    return roman_Operation(difference, difference_size, minuend, suptrahend, subtract);
}

static const int LARGEST_NUMERAL_THAT_CAN_BE_EXPRESSED = 3999;

inline int is_within_valid_range(int number) {
    return 0 < number && number < LARGEST_NUMERAL_THAT_CAN_BE_EXPRESSED;
}

static char *roman_Operation(char *const result, const size_t result_size, const char *const operand1, const char *const operand2, Operation operation) {
    if(result == NULL || operand1 == NULL || operand2 == NULL)
        return NULL;

    if(is_a_valid_roman_numeral(operand1) && is_a_valid_roman_numeral(operand2)) {
        int a = roman_to_arabic(operand1);
        int b = roman_to_arabic(operand2);

        memset(result, 0, result_size);

        int arabic_result = operation(a, b);

        if(is_within_valid_range(arabic_result)) 
            arabic_to_roman(result, result_size, arabic_result);
     } else
        memset(result, 0, result_size);

    return result;
}
