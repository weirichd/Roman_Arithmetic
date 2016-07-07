#include "romarth.h"
#include <stddef.h> /* For NULL Macro */
#include <string.h> /* For strlen, memset */

static int roman_to_arabic(char *numeral);
static char *arabic_to_roman(char *dest, int number);

char *roman_add(char *sum, char *summand1, char *summand2) {
    int a = roman_to_arabic(summand1);
    int b = roman_to_arabic(summand2);
    return arabic_to_roman(sum, a + b);
}

char *roman_subtract(char *differene, char *minuend, char *suptrahend) {
    return NULL;
}

static int roman_to_arabic(char *numeral) {
    return strlen(numeral); 
}

static char *arabic_to_roman(char *dest, int number) {
    memset(dest,'I', number);
    return dest;
}
