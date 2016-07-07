#include "romarth.h"
#include <stddef.h> /* For NULL Macro */
#include <string.h> /* For strlen, memset */

static int roman_to_arabic(char *numeral);
static char *arabic_to_roman(char *dest, int arabic_number);

char *roman_add(char *sum, char *summand1, char *summand2) {
    int a = roman_to_arabic(summand1);
    int b = roman_to_arabic(summand2);
    return arabic_to_roman(sum, a + b);
}

char *roman_subtract(char *differene, char *minuend, char *suptrahend) {
    return NULL;
}

static int roman_to_arabic(char *numeral) {
    int arabic_result = 0;

    for(int i = 0; i < strlen(numeral); i++) {
        switch (numeral[i]) {
           case 'I':
               arabic_result += 1;
               break;
           case 'V':
               arabic_result += 5;
               break;
        }
    }
    
    return arabic_result;
}

static char *arabic_to_roman(char *dest, int arabic_number) {
    int number_of_Is = arabic_number % 5;
    int number_of_Vs = arabic_number / 5;

    memset(dest,'V', number_of_Vs);
    memset(dest + number_of_Vs, 'I', number_of_Is);

    return dest;
}
