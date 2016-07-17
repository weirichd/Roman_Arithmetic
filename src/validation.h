#ifndef VALIDATION_H
#define VALIDATION_H

#include <string.h>
#include <regex.h>

#include "numeral_map.h"

static const char roman_numeral_patern[] = "^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$";

static int is_a_valid_roman_numeral(const char *const numeral) {
    regex_t regex;

    regcomp(&regex, roman_numeral_patern, REG_EXTENDED | REG_NOSUB); 

    int result = regexec(&regex, numeral, 0, NULL, 0);

    regfree(&regex);

    return (result != REG_NOMATCH);
}

#endif /* VALIDATION_H */
