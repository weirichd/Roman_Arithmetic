#ifndef VALIDATION_H
#define VALIDATION_H

#include "numeral_map.h"

static int is_a_valid_roman_numeral(const char *const numeral) {
    const RomanMapEntry *entry = find_map_element(numeral);

    return entry != NULL;
}

#endif /* VALIDATION_H */
